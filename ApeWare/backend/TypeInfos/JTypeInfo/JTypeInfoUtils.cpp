#include "JTypeInfoUtils.hpp"

jTypeinfo* GetReversedTypeInfo(std::string typeName)
{
	for (std::shared_ptr<jTypeinfo> info : Globals::typeinfos)
	{
		if (info->name.find(typeName) != std::string::npos && info->populated == true)
		{
			jTypeinfo* newTypeInfo = new jTypeinfo;
			newTypeInfo->address = info->address;
			newTypeInfo->name = info->name;
			newTypeInfo->populated = info->populated;
			newTypeInfo->staticfield = info->staticfield;
			return newTypeInfo;
		}
		continue;
	}
	return nullptr;
}