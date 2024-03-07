#include "HookManager.h"

Hook::Hook(BYTE* source, void* destination, size_t size) : m_byteSource(source), m_byteDestination(destination), m_pGateway(nullptr), m_szLen(size), m_enabled(false) {
#ifdef _WIN32
    DWORD oldProt;
    VirtualProtect(m_byteSource, m_szLen, PAGE_EXECUTE_READWRITE, &oldProt);
    memcpy(stolenBytes, m_byteSource, m_szLen);
    VirtualProtect(m_byteSource, m_szLen, oldProt, &oldProt);
#endif
}

Hook::~Hook() {
    Disable();
}

void Hook::Enable() {
    if (m_enabled)
        return;

    BYTE* jumpbackAddress = nullptr;
    BYTE* functionDestinationAddress = nullptr;

    m_pGateway = VirtualAlloc(nullptr, 0x100, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!m_pGateway) {
        return;
    }

    DWORD oldProt;
    VirtualProtect(m_pGateway, m_szLen + 13, PAGE_EXECUTE_READWRITE, &oldProt);  // Assuming jumpShellCodeSize is 13
    memcpy(m_pGateway, stolenBytes, m_szLen);

#ifdef _WIN64
    jumpbackAddress = m_byteSource + m_szLen;
    functionDestinationAddress = (BYTE*)m_byteDestination;
    BYTE jumpShellcode[] = {
        0x49, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x41, 0xFF, 0xE2
    };
#else
    jumpbackAddress = (BYTE*)((m_byteSource + m_szLen) - ((uintptr_t)m_pGateway + m_szLen + 5));  // Assuming jumpShellCodeSize is 5
    functionDestinationAddress = (BYTE*)(m_byteDestination - m_byteSource - 5);
    BYTE jumpShellcode[] = {
        0xE9, 0x00, 0x00, 0x00, 0x00
    };
#endif
    size_t jumpAddressOffset = sizeof(jumpShellcode) - sizeof(jumpbackAddress);
    *(BYTE**)(jumpShellcode + jumpAddressOffset) = jumpbackAddress;
    memcpy((void*)((uintptr_t)m_pGateway + m_szLen), jumpShellcode, sizeof(jumpShellcode));

    VirtualProtect(m_byteSource, m_szLen, PAGE_EXECUTE_READWRITE, &oldProt);
    memset(m_byteSource, 0x90, m_szLen);
    *(BYTE**)(jumpShellcode + jumpAddressOffset) = functionDestinationAddress;
    memcpy(m_byteSource, jumpShellcode, sizeof(jumpShellcode));
    VirtualProtect(m_byteSource, m_szLen, oldProt, &oldProt);

    m_enabled = true;
}

void Hook::Disable() {
    if (!m_enabled)
        return;

    DWORD oldProt;
    VirtualProtect(m_byteSource, m_szLen, PAGE_EXECUTE_READWRITE, &oldProt);
    memcpy(m_byteSource, stolenBytes, m_szLen);
    VirtualProtect(m_byteSource, m_szLen, oldProt, &oldProt);

    VirtualFree(m_pGateway, 0, MEM_RELEASE);
    m_enabled = false;
}

HookManager::~HookManager() {
    for (auto& pair : m_hooks) {
        delete pair.second;
    }
    m_hooks.clear();
}

void HookManager::HM_AddHook(const std::string& name, BYTE* source, void* destination, size_t size) {
    m_hooks[name] = new Hook(source, destination, size);
}

bool HookManager::HM_EnableHook(const std::string& name) {
    if (m_hooks.find(name) != m_hooks.end()) {
        m_hooks[name]->Enable();
        return true;
    }
    return false;
}

bool HookManager::HM_DisableHook(const std::string& name) {
    if (m_hooks.find(name) != m_hooks.end()) {
        m_hooks[name]->Disable();
        return true;
    }
    return false;
}

void HookManager::HM_EnableAllHooks() {
    for (auto& pair : m_hooks) {
        pair.second->Enable();
    }
}

void HookManager::HM_DisableAllHooks() {
    for (auto& pair : m_hooks) {
        pair.second->Disable();
    }
}
