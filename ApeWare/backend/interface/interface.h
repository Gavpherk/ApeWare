#pragma once
#include "../../include/includes.h"
#include "../TypeInfos/JTypeInfo/JTypeInfoUtils.hpp"
#include "../TypeInfos/TypeInfoJSONParser.h"
#include "../Functions/JFunction/JFunctionUtils.h"
#include "../Functions/FunctionFetcher.h"
#include "../../include/Globals.h"


class Cheat 
{
public:
    bool RegisterTypeInfos(std::vector<const char*> TypeInfoList);
    bool RegisterFunctionClasses(std::vector<const char*> ClassList);
    bool InitTypeInfoSystem(bool ignoreFilters);
    bool UpdateBackendTypeInfos();
    bool InitFunctionSystem(bool ignoreFilters);
    bool PopulateFunctionPointers();
    bool DisableHookGameFunction(const char* nickname);
    bool DisableALLHooks();
    bool SetupCheat(std::vector<std::pair<const char*, FeatureBase*>> FeaturesList);
    bool LoopCheat();
    bool show = false;
    bool cursorclipped = false;

};