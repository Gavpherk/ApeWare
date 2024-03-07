#include "JFunctionUtils.h"

JFunction* GetReversedFunctionInfo(std::string className, std::string methodName, std::string typesignature)
{
	for (std::shared_ptr<JFunction> function : Globals::functions)
	{
		if (typesignature == "NA")
		{
			if (function->ClassName.find(className) != std::string::npos &&
				function->MethodName.find(methodName) != std::string::npos)
			{
				JFunction* newFunction = new JFunction;
				newFunction->address = function->address;
				newFunction->ClassName = function->ClassName;
				newFunction->MethodName = function->MethodName;
				newFunction->TypeSignature = function->TypeSignature;
				newFunction->RVA = function->RVA;
				return newFunction;
			}
		}
		else if (typesignature != "NA")
		{
			if (function->ClassName.find(className) != std::string::npos &&
				function->MethodName.find(methodName) != std::string::npos && 
				function->TypeSignature.find(typesignature) != std::string::npos)
			{
				JFunction* newFunction = new JFunction;
				newFunction->address = function->address;
				newFunction->ClassName = function->ClassName;
				newFunction->MethodName = function->MethodName;
				newFunction->TypeSignature = function->TypeSignature;
				newFunction->RVA = function->RVA;
				return newFunction;
			}
		}

	}

	return nullptr;
}