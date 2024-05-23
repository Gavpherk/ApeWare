#include "HookManager.h"
#include "HookManagerUtils.h"

Hook::Hook(BYTE* source, BYTE* destination, size_t size, bool usesConditions, FuncPtr condition, const char* name, const char* conditionName) 
{
    this->m_byteSource = source;
    this->m_byteDestination = destination;
    this->m_szLen = size;
    ++ConditionHooks::HookCount;
    this->usesConditions = usesConditions;
    this->isConditioned = false;
    this->name = name;
    this->m_pGateway = nullptr;
    this->m_enabled = false;

    if (usesConditions)
    {
        ++ConditionHooks::conditionCount;
        this->conditionName = conditionName;
        this->condition = condition;
        ConditionHooks::conditionsMap[this->conditionName] = this->condition;
        std::cout << "Condition Added with Name: " << conditionName << "\n";
    }
    else if (!usesConditions)
    {
        std::cout << "Hook with no conditions Initialized \n";
    }

    if (!this->isConditioned && this->usesConditions)
    {
        if (this->condition == nullptr)
        {
            ++ConditionHooks::failedConditions;
            std::cout << "[HOOK MANAGER] A Condition was called, but the hook object has a nullptr FuncPtr Field, aborting condition for " + (std::string)conditionName << " this may lead to a crash using this hook." << std::endl;
        }
        else
        {
            ConditionFunctionHook(conditionName, ConditionHooks::conditionsMap);
        }
    }

    DWORD oldprot;
    VirtualProtect((void*)this->m_byteSource, this->m_szLen, PAGE_EXECUTE_READWRITE, &oldprot);
    memcpy(this->stolenBytes, (void*)this->m_byteSource, this->m_szLen);
    VirtualProtect((void*)this->m_byteSource, this->m_szLen, oldprot, &oldprot);

}

Hook::~Hook() {
    Disable();
}

void* Hook::Enable(const std::string name, const char* conditionName)
{
    BYTE* jumpbackAddress = nullptr;
    BYTE* functionDestinationAddress = nullptr;

    this->m_pGateway = VirtualAlloc(nullptr, 0x100, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
   
        if (this->m_pGateway)
        {
            printf("[+] Allocated memory for gateway at: %p\n", this->m_pGateway);
        }
        else
        {
            printf("[!] Failed allocated memory for gateway at: %p\n", this->m_pGateway);
            return 0;
        }
    
#ifdef _WIN64
    BYTE jumpShellcode[] =
    {
        0x49, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,		//mov r10, jumpAddress
        0x41, 0xFF, 0xE2												//jmp r10
    };
    static const size_t jumpShellCodeSize = 13;
    static const size_t jumpAddressOffset = 2;

    jumpbackAddress = this->m_byteSource + this->m_szLen;
    functionDestinationAddress = this->m_byteDestination;
#else
    BYTE jumpShellcode[] =
    {
        0xE9, 0x00, 0x00, 0x00, 0x00									//jmp jumpAddress (jump address must be the relative address)
    };
    static const size_t jumpShellCodeSize = 5;
    static const size_t jumpAddressOffset = 1;

    jumpbackAddress = (BYTE*)((this->m_byteSource + this->m_szLen) - ((uintptr_t)this->m_pGateway + this->m_szLen + jumpShellCodeSize));
    functionDestinationAddress = (BYTE*)(this->m_byteDestination - this->m_byteSource - jumpShellCodeSize);
#endif

    DWORD dwOldProtection;
    VirtualProtect(this->m_pGateway, this->m_szLen + jumpShellCodeSize, PAGE_EXECUTE_READWRITE, &dwOldProtection);	//setup gateway
    {
        memcpy(this->m_pGateway, this->stolenBytes, this->m_szLen);

        *(BYTE**)(jumpShellcode + jumpAddressOffset) = jumpbackAddress;
        memcpy((void*)((uintptr_t)this->m_pGateway + this->m_szLen), jumpShellcode, jumpShellCodeSize);
        VirtualProtect(this->m_pGateway, this->m_szLen + jumpShellCodeSize, dwOldProtection, &dwOldProtection);
}

    VirtualProtect((void*)this->m_byteSource, this->m_szLen, PAGE_EXECUTE_READWRITE, &dwOldProtection);				//setup jump to our function
    {
        memset((void*)this->m_byteSource, 0x90, this->m_szLen);

        *(BYTE**)(jumpShellcode + jumpAddressOffset) = functionDestinationAddress;
        memcpy(this->m_byteSource, jumpShellcode, jumpShellCodeSize);
        VirtualProtect((void*)this->m_byteSource, this->m_szLen, dwOldProtection, &dwOldProtection);
    }

    return this->m_pGateway;
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

void HookManager::HM_AddHook(const std::string& name, BYTE* source, BYTE* destination, size_t size, bool usesConditions, FuncPtr condition, const char* conditionName) 
{
    m_hooks[name] = new Hook((BYTE*)source, destination, size, usesConditions, condition, name.c_str(), conditionName);
}

void* HookManager::HM_EnableHook(const std::string& name, const char* conditionName)
{
    if (m_hooks.find(name) != m_hooks.end()) 
    {
       void* HookReturnAddress = m_hooks[name]->Enable(name, conditionName);
        return HookReturnAddress;
    }

    return nullptr;
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


void* HookManager::HookGameFunction(const char* nickname, JFunction* targetFunc, size_t size, BYTE* detour, bool usesConditions, FuncPtr Condition, const char* conditionName)
{
    if (targetFunc)
    {
        HM_AddHook(nickname, (BYTE*)targetFunc->RVA, detour, size, usesConditions, Condition, conditionName);
        void* newFunctionReturnAddress = HM_EnableHook(nickname, conditionName);
        return newFunctionReturnAddress;
    }
    else
    {
        std::cout << "[INTERFACE] HookGameFunction returned a NullPTR JFunction, make sure your referencing the class and function name properly." << std::endl;
        return nullptr;
    }
}


//TO DO, test system.