#include "HookManagerUtils.h"

void ConditionFunctionHook(const char* condition_str, std::map<std::string, FuncPtr> conditionsMap)
{
    if (conditionsMap.find(condition_str) != conditionsMap.end())
    {
        conditionsMap[condition_str]();
    }
    else
    {
        std::cout << "Hook condition not recognized, make sure you've properly initialized it." << std::endl;
    }
}