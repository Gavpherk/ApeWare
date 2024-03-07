#pragma once
#include "../../include/includes.h"


template <typename T = uintptr_t>
T GetRelativeFunctionAddress(int offset);

bool parseJsonFunctions(const char* filePath, std::vector<std::shared_ptr<JFunction>>& functions, std::vector<std::string>& requestedClasses, bool all);

bool PopulateFuncionRVAs();

bool SetupFunctionCalls();

