#pragma once
#include <iostream>

struct jTypeinfo
{
	int address;
	std::string name;
	void* staticfield;
	bool populated;
};

struct JFunction 
{
	std::string ClassName;
	std::string MethodName;
	std::string TypeSignature;
	int address;
	void* RVA;
};
