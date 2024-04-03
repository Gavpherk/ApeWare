#include "HookManagerUtils.h"

void ConditionFunctionHook(const char* condition_str, std::map<std::string, FuncPtr> conditionsMap)
{
    if (conditionsMap.find(condition_str) != conditionsMap.end())
    {
        conditionsMap[condition_str]();
    }
    else
    {
        std::cout << "[HOOK MANAGER] Hook condition name not recognized, make sure you've properly initialized it. CONDITION-NAME: ";
        std::cout << condition_str << "\n";
    }
}