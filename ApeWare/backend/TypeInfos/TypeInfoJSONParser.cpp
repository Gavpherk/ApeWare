#include "TypeInfoJSONParser.h"

bool ParseJSON(const std::string& filename)
{
	std::ifstream file(filename);

	if (!file.is_open())
	{
		return false;
		printf("%s", "[TYPEINFO_PARSER] Unknown fialure parsing ScriptMetadata.json, does it exist?\n");
	}

	try
	{
		json newJSONData;
		file >> TypeInfoJSONData;

		file.close();
		return true;
	}
	catch (const std::exception& e)
	{
		file.close();
		printf("%s", "[TYPEINFO_PARSER] Unknown fialure parsing ScriptMetadata.json, does it exist?\n");
		return false;
	}
}

bool PopulateTypeInfos(std::vector<std::shared_ptr<jTypeinfo>>& typeinfos, std::vector<std::string> requestedtypeinfos, bool all)
{
	typeinfos.clear();
	

	for (const auto& element : TypeInfoJSONData)
	{
		std::string name = element["name"].get<std::string>();
		if (std::find(requestedtypeinfos.begin(), requestedtypeinfos.end(), name) != requestedtypeinfos.end() || all == true)
		{
			auto typeinfo = std::make_shared<jTypeinfo>();
			typeinfo->address = element["address"];
			typeinfo->name = name;
			typeinfo->staticfield = nullptr;
			typeinfo->populated = false;

			typeinfos.push_back(typeinfo);

		}
	}
	return true;
}

bool parseJsonTypeInfos()
{
	if (ParseJSON("ScriptMetadata.json"))
	{
		return true;
	}
	else
	{
		printf("%s", "[TYPEINFO_PARSER] Unknown fialure parsing ScriptMetadata.json, does it exist?\n");
		return false;
	}
}

bool AddTypeInfo(std::string typeinfoname)
{
	Globals::requestedtypeinfos.push_back(typeinfoname);
	return true;
}

bool AddMethodsFromClass(std::string methodname)
{
	Globals::requestedClasses.push_back(methodname);
	return true;
}
