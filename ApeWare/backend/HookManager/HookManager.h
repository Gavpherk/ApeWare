#pragma once
#include "../../include/includes.h"

class Hook {
private:
    BYTE* m_byteSource;
    void* m_byteDestination;
    void* m_pGateway;
    BYTE stolenBytes[15]; // Assuming maximum hook size is 15 bytes
    size_t m_szLen;
    bool m_enabled;
public:
    Hook(BYTE* source, void* destination, size_t size = 15);
    ~Hook();
    void Enable();
    void Disable();
};

class HookManager {
private:
    std::unordered_map<std::string, Hook*> m_hooks;
public:
    HookManager() {}
    ~HookManager();
    void HM_AddHook(const std::string& name, BYTE* source, void* destination, size_t size = 15);
    bool HM_EnableHook(const std::string& name);
    bool HM_DisableHook(const std::string& name);
    void HM_EnableAllHooks();
    void HM_DisableAllHooks();
};