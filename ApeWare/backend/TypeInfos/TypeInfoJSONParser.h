#pragma once 
#include "../../include/includes.h"

bool ParseJSON(const std::string& filename);

bool PopulateTypeInfos(std::vector<std::shared_ptr<jTypeinfo>>& typeinfos, std::vector<std::string> requestedtypeinfos, bool all);
bool parseJsonTypeInfos();

LONG64* GetUnityStaticField(LONG64 offsetTypeinfo);

bool AddTypeInfo(std::string typeinfoname);

bool AddMethodsFromClass(std::string methodname);

inline static json TypeInfoJSONData;