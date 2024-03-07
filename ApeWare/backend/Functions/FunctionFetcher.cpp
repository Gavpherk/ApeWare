#include "FunctionFetcher.h"

template <typename T>
T GetRelativeFunctionAddress(int offset)
{
	try
	{
		return reinterpret_cast<T>(reinterpret_cast<BYTE*>(Globals::Game::moduleBase) + offset);
	}
	catch (...)
	{
		return static_cast<T>(0);
	}
}

bool parseJsonFunctions(const char* filePath, std::vector<std::shared_ptr<JFunction>>& functions, std::vector<std::string>& requestedClasses, bool all)
{
	functions.clear();
	std::vector<std::shared_ptr<JFunction>> result;
	std::ifstream inputJsonFile(filePath);
	if (!inputJsonFile.is_open())
	{
		printf("%s", "[FUNCTIONFETCHER] Failed to open file ScriptMethod.json does it exist?\n");
		return false;
	}

	try
	{
		json jsonArray = json::parse(inputJsonFile);

		for (const auto& item : jsonArray)
		{
			std::string pClass = item["Class"];
			if (std::find(requestedClasses.begin(), requestedClasses.end(), pClass) != requestedClasses.end() && all == false)
			{
				auto jFunc = std::make_shared<JFunction>();
				jFunc->ClassName = pClass;
				jFunc->MethodName = item["Method"];
				jFunc->address = item["Address"];
				jFunc->TypeSignature = item["TypeSignature"];
				jFunc->RVA = nullptr;
				result.push_back(jFunc);
			}
			else if (all == true)
			{
				auto jFunc = std::make_shared<JFunction>();
				jFunc->ClassName = pClass;
				jFunc->MethodName = item["Method"];
				jFunc->address = item["Address"];
				jFunc->TypeSignature = item["TypeSignature"];
				jFunc->RVA = nullptr;
				result.push_back(jFunc);
			}
		}
	}

	catch (const std::exception& e)
	{
		printf("%s", "[FUNCTIONFETCHER] unknown failure\n");
		inputJsonFile.close();
		return false;
	}

	functions = result;
	inputJsonFile.close();
	return true;
}

bool PopulateFuncionRVAs()
{
	try
	{
		for (auto function : Globals::functions)
		{
			void* FunctionRVA = GetRelativeFunctionAddress<void*>(function->address);
			function->RVA = FunctionRVA;
		}
	}
	catch (const std::exception& e)
	{
		printf("%s", "[FUNCTIONFETCHER] Failed to populate function RVA's\n");
		return false;
	}

	return true;
}

struct JFunctionSucceeded
{
	std::string JFuncName;
	bool suceeded;
	JFunction* JFunc = nullptr;
};

std::vector<JFunctionSucceeded*> SucceededFunctions;
std::vector<JFunctionSucceeded*> FailedFunctions;

bool SetupFunctionCalls()
{
	/*
	JFunction* get_maincameraInfo = GetReversedFunctionInfo("UnityEngine.Camera", "get_main");

	if (!get_maincameraInfo)
	{
		JFunctionSucceeded* MainCameraFailed = new JFunctionSucceeded;
		MainCameraFailed->JFuncName = "MainCamera";
		MainCameraFailed->suceeded = false;
		FailedFunctions.push_back(MainCameraFailed);
	}
	else
	{
		JFunctionSucceeded* MainCameraPassed = new JFunctionSucceeded;
		MainCameraPassed->JFuncName = "MainCamera";
		MainCameraPassed->suceeded = true;
		MainCameraPassed->JFunc = get_maincameraInfo;
		SucceededFunctions.push_back(MainCameraPassed);
	}

	JFunction* worldtoscreenpointInfo = GetReversedFunctionInfo("UnityEngine.Camera", "WorldToScreenPoint");

	if (!worldtoscreenpointInfo)
	{
		JFunctionSucceeded* WorldToScreenFailed = new JFunctionSucceeded;
		WorldToScreenFailed->JFuncName = "WorldToScreen";
		WorldToScreenFailed->suceeded = false;
		FailedFunctions.push_back(WorldToScreenFailed);
	}
	else
	{
		JFunctionSucceeded* WorldToScreenPassed = new JFunctionSucceeded;
		WorldToScreenPassed->JFuncName = "WorldToScreen";
		WorldToScreenPassed->suceeded = true;
		WorldToScreenPassed->JFunc = worldtoscreenpointInfo;
		SucceededFunctions.push_back(WorldToScreenPassed);
	}

	JFunction* transformgetpositionInfo = GetReversedFunctionInfo("UnityEngine.Transform", "get_position");

	if (!transformgetpositionInfo)
	{
		JFunctionSucceeded* TransformGetPositionFailed = new JFunctionSucceeded;
		TransformGetPositionFailed->JFuncName = "TransformGetPosition";
		TransformGetPositionFailed->suceeded = false;
		FailedFunctions.push_back(TransformGetPositionFailed);
	}
	else
	{
		JFunctionSucceeded* TransformGetPositionPassed = new JFunctionSucceeded;
		TransformGetPositionPassed->JFuncName = "TransformGetPosition";
		TransformGetPositionPassed->suceeded = true;
		TransformGetPositionPassed->JFunc = transformgetpositionInfo;
		SucceededFunctions.push_back(TransformGetPositionPassed);
	}
       */

	for (int i = 0; i < SucceededFunctions.size(); i++)
	{
		auto currentPassedJFunc = SucceededFunctions[i];

		/*
		if (currentPassedJFunc->JFuncName == "MainCamera")
		{
			Globals::Game::CallFunction::oGetMainCamera = (tGetMainCamera)currentPassedJFunc->JFunc->RVA;
		}

		if (currentPassedJFunc->JFuncName == "WorldToScreen")
		{
			Globals::Game::CallFunction::oW2S = (tWorldToScreen)currentPassedJFunc->JFunc->RVA;
		}

		if (currentPassedJFunc->JFuncName == "HealthSendDamage")
		{
			Globals::Game::CallFunction::oSendDamage = (tSendDamage)currentPassedJFunc->JFunc->RVA;
		}

		if (currentPassedJFunc->JFuncName == "TransformGetPosition")
		{
			Globals::Game::CallFunction::oTransformGetPosition = (tTransformGetPosition)currentPassedJFunc->JFunc->RVA;
		}
		*/
	}

	std::cout << "size of failed CallFunction RVA's: " << FailedFunctions.size() << std::endl;
	printf("%s", "Function calls setup\n");
	return true;
}