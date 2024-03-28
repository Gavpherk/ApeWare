#include "HookManager.h"
#include "HookManagerUtils.h"

Hook::Hook(BYTE* source, void* destination, size_t size, bool usesConditions, FuncPtr condition, const char* name, const char* conditionName) : m_byteSource(source), m_byteDestination(destination), m_pGateway(nullptr), m_szLen(size), m_enabled(false) 
{
    this->usesConditions = usesConditions;
    this->isConditioned = false;
    this->name = name;

    if (usesConditions)
    {
        this->conditionName = conditionName;
        this->condition = condition;
    }

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

void Hook::Enable(const std::string name, const char* conditionName)
{
    if (!this->isConditioned && this->usesConditions)
    {
        if (this->condition == nullptr)
        {
            std::cout << "A Condition was called, but the hook object has a nullptr FuncPtr Field, aborting condition for " + name << " this may lead to a crash using this hook." << std::endl;
        }
        else
        {
            ConditionFunctionHook(conditionName, ConditionHooks::conditionsMap);
        }
    }

    if (m_enabled)
        return;

    BYTE* jumpbackAddress = nullptr;
    BYTE* functionDestinationAddress = nullptr;

    m_pGateway = VirtualAlloc(nullptr, 0x100, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    if (!m_pGateway)
        return;
 
    DWORD oldProt;
    VirtualProtect(m_pGateway, m_szLen + 13, PAGE_EXECUTE_READWRITE, &oldProt);  // Assuming jumpShellCodeSize is 13
    memcpy(m_pGateway, stolenBytes, m_szLen);

#ifdef _WIN64
    jumpbackAddress = m_byteSource + m_szLen;
    functionDestinationAddress = (BYTE*)m_byteDestination;
    BYTE jumpShellcode[] = 
    {
        0x49, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x41, 0xFF, 0xE2
    };
#else
    jumpbackAddress = (BYTE*)((m_byteSource + m_szLen) - ((uintptr_t)m_pGateway + m_szLen + 5));  // Assuming jumpShellCodeSize is 5
    functionDestinationAddress = (BYTE*)(m_byteDestination - m_byteSource - 5);
    BYTE jumpShellcode[] = 
    {
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

void Hook::Disable() 
{
    if (!m_enabled)
        return;

    DWORD oldProt;
    VirtualProtect(m_byteSource, m_szLen, PAGE_EXECUTE_READWRITE, &oldProt);
    memcpy(m_byteSource, stolenBytes, m_szLen);
    VirtualProtect(m_byteSource, m_szLen, oldProt, &oldProt);

    VirtualFree(m_pGateway, 0, MEM_RELEASE);
    m_enabled = false;
}

HookManager::~HookManager()
{
    for (auto& pair : m_hooks)
    {
        delete pair.second;
    }

    m_hooks.clear();
}

void HookManager::HM_AddHook(const std::string& name, BYTE* source, void* destination, size_t size, bool usesConditions, FuncPtr condition, const char* conditionName) 
{
    m_hooks[name] = new Hook(source, destination, size, usesConditions, condition, conditionName);
}

bool HookManager::HM_EnableHook(const std::string& name, const char* conditionName)
{
    if (m_hooks.find(name) != m_hooks.end()) 
    {
        m_hooks[name]->Enable(name, conditionName);
        return true;
    }

    return false;
}

bool HookManager::HM_DisableHook(const std::string& name) 
{
    if (m_hooks.find(name) != m_hooks.end()) 
    {
        m_hooks[name]->Disable();
        return true;
    }

    return false;
}

void HookManager::HM_EnableAllHooks() 
{
    for (const auto& pair : m_hooks) 
    {
        pair.second->Enable(pair.second->name, pair.second->conditionName);
    }

    for (const auto& pair : m_hooks) 
    {
        delete pair.second;
    }
}

void HookManager::HM_DisableAllHooks() 
{
    for (auto& pair : m_hooks) 
    {
        pair.second->Disable();
    }

    for (const auto& pair : m_hooks)
    {
        delete pair.second;
    }
}


//ex
void Hook1()
{
    
}

//TO DO, add populating system for condition map, test system.