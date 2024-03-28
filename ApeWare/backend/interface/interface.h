#pragma once
#include "../../include/includes.h"
#include "../TypeInfos/JTypeInfo/JTypeInfoUtils.hpp"
#include "../TypeInfos/TypeInfoJSONParser.h"
#include "../Functions/JFunction/JFunctionUtils.h"
#include "../Functions/FunctionFetcher.h"


class Cheat 
{
public:
    bool RegisterTypeInfos(std::vector<const char*> TypeInfoList);
    bool RegisterFunctionClasses(std::vector<const char*> ClassList);
    bool InitTypeInfoSystem(bool ignoreFilters);
    bool UpdateBackendTypeInfos();
    bool InitFunctionSystem(bool ignoreFilters);
    bool PopulateFunctionPointers();
    bool HookGameFunction(const char* nickname, const char* _class, const char* _function, void* detour, const char* typesignature = "NA");
    bool DisableHookGameFunction(const char* nickname);
    bool DisableALLHooks();
    bool SetupCheat(std::vector<std::pair<const char*, FeatureBase*>> FeaturesList);
    bool LoopCheat();
    bool show = false;

};