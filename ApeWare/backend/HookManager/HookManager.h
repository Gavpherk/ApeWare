#pragma once
#include "../../include/includes.h"

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
    const char* conditionName = "N/A";

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

    void HM_AddHook(const std::string& name, BYTE* source, void* destination, size_t size = 15, bool usesConditons = false, FuncPtr condition = nullptr, const char* conditionName = "N/A");
    bool HM_EnableHook(const std::string& name, const char* conditionName = "N/A");
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