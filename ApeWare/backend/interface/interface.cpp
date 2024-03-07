#include "interface.h"
#include "../HookManager/HookManager.h"

HookManager hookManager;
uintptr_t t_moduleBase = (uintptr_t)GetModuleHandle("GameAssembly.dll");

bool Cheat::RegisterTypeInfos(std::vector<const char*> TypeInfoList) 
{
    for (auto& typeinfo : TypeInfoList)
    {
        AddTypeInfo(typeinfo); 
    }
    return true;
}

bool Cheat::RegisterFunctionClasses(std::vector<const char*> ClassList) 
{
    for (auto& _class : ClassList) 
    {
        AddMethodsFromClass(_class); 
    }
    return true;
}

bool Cheat::InitTypeInfoSystem(bool ignoreFilters = false)
{
    parseJsonTypeInfos();
    PopulateTypeInfos(Globals::typeinfos, Globals::requestedtypeinfos, ignoreFilters);
    return true;
}

bool Cheat::UpdateBackendTypeInfos()
{
    for (const auto& currentTypeInfo : Globals::typeinfos) 
    {
        void* static_fields = GetUnityStaticField((LONG64)currentTypeInfo->address); 
        if (static_fields != nullptr)
        {
            currentTypeInfo->staticfield = static_fields;
            currentTypeInfo->populated = true;
        }
        else 
        {
            currentTypeInfo->staticfield = nullptr;
            currentTypeInfo->populated = false;
        }
    }
    return true;
}

bool Cheat::InitFunctionSystem(bool ignoreFilters = false) 
{
    Globals::Game::moduleBase = t_moduleBase;
    parseJsonFunctions("ScriptMethod.json", Globals::functions, Globals::requestedClasses, ignoreFilters);
    PopulateFuncionRVAs(); 
    return true;
}

bool Cheat::ConditionFunctionHooks() 
{


    return true;
}

bool Cheat::PopulateFunctionPointers()
{


    return true;
}

bool Cheat::HookGameFunction(const char* nickname, const char* _class, const char* _function, void* detour, const char* typesignature) 
{
    JFunction* tFunc = GetReversedFunctionInfo(_class, _function, typesignature); 
    if (tFunc) 
    {
        hookManager.HM_AddHook(nickname, (BYTE*)tFunc->RVA, detour);
        hookManager.HM_EnableHook(nickname);
        return true;
    }
    else 
    {
        return false;
    }
}

bool Cheat::DisableHookGameFunction(const char* nickname)
{
        hookManager.HM_DisableHook(nickname);
        return true;
}

bool Cheat::DisableALLHooks()
{
    hookManager.HM_DisableAllHooks();
    return true;
}

bool Cheat::SetupCheat(std::vector<std::pair<const char*, FeatureBase*>> FeaturesList)
{

        for (const auto &feature : FeaturesList)
        {
            Globals::featureManager.AddFeature(feature.first, feature.second);
        }

        FeatureBase* t_menu = Globals::featureManager.FindFeature("Menu");
        Globals::ref_menu = t_menu;
        return true;
}

bool Cheat::LoopCheat()
{
        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            show = !show;							// track menu state for dllmain and menu.cpp here.
            Globals::ref_menu->bToggle = show;
        }

        Globals::featureManager.LoopAll(); // calls ::OnLoop for all features.

        if (show)
        {
            Globals::featureManager.RenderFeature("Menu"); // calls menu::OnRender
        }

        if (GetAsyncKeyState(VK_DELETE) & 1)
        {
            return false;
        }

        return true;
}