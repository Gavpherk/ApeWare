#pragma once
#include "../Functions/JFunction/JFunctionUtils.h"

typedef std::function<void()> FuncPtr;

class Hook 
{
private:
    BYTE* m_byteSource;
    void* m_byteDestination;
    void* m_pGateway;
    BYTE stolenBytes[15]; // Assuming maximum hook size is 15 bytes
    size_t m_szLen;
    bool m_enabled;
public:
    bool usesConditions;
    bool isConditioned;
    const char* name;
    const char* conditionName;

    FuncPtr condition;

    Hook(BYTE* source, void* destination, size_t size = 15, bool usesConditions = false, FuncPtr condition = nullptr, const char* name = "NAME", const char* conditionName = "N/A");
    ~Hook();
    void Enable(const std::string name, const char* conditionName);
    void Disable();
};

class HookManager 
{
private:
    std::unordered_map<std::string, Hook*> m_hooks;
public:
    HookManager() {}
    ~HookManager();

    bool HookGameFunction(const char* nickname, JFunction* taretFunc, void* detour, bool usesConditions, FuncPtr Condition, const char* conditionName);
    void HM_AddHook(const std::string& name, BYTE* source, void* destination, size_t size = 15, bool usesConditons = false, FuncPtr condition = nullptr, const char* conditionName = "N/A");
    bool HM_EnableHook(const std::string& name, const char* conditionName);
    bool HM_DisableHook(const std::string& name);
    void HM_EnableAllHooks();
    void HM_DisableAllHooks();
};


namespace ConditionHooks
{
    inline int failedConditions;
    inline int conditionCount;
    inline int HookCount;
    inline std::map<std::string, FuncPtr> conditionsMap;
}