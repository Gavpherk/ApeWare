#include "../../include/includes.h"
#include "sig.h"

SignatureScanner::SignatureScanner(const char* moduleName, size_t moduleSize, char* pattern, char* mask)
{
	this->moduleBase = (uintptr_t)GetModuleHandleA(moduleName); this->moduleSize = moduleSize; this->pattern = pattern; this->mask = mask;
}

SignatureScanner::SignatureScanner(uintptr_t start, uintptr_t end, char* pattern, char* mask)
{
	this->moduleBase = start; this->moduleSize = end - start; this->pattern = pattern; this->mask = mask;
}

uintptr_t SignatureScanner::Scan()
{
	uintptr_t lastAddress = this->moduleBase + this->moduleSize;
	size_t patternLength = strlen(this->mask);

	for (uintptr_t currentAddress = this->moduleBase; currentAddress < lastAddress; currentAddress++)
	{
		bool found = true;

		for (size_t currentPattern = 0; currentPattern < patternLength; currentPattern++)
		{
			__try
			{
				*(char*)(currentAddress + currentPattern) == this->pattern[currentPattern] || mask[currentPattern] == '?';
			}
			__except (EXCEPTION_EXECUTE_HANDLER)
			{
				found = false;
				break;
			}

			if (*(char*)(currentAddress + currentPattern) == this->pattern[currentPattern] || mask[currentPattern] == '?')
			{

			}
			else
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return currentAddress;
		}
	}

	return 0;
}

uintptr_t SignatureScanner::ScanRepeatable(size_t size)
{
	uintptr_t lastAddress = this->moduleBase + this->moduleSize;
	size_t patternLength = strlen(this->mask);

	for (uintptr_t currentAddress = this->moduleBase; currentAddress < lastAddress; currentAddress++)
	{
		bool found = true;

		for (size_t currentPattern = 0; currentPattern < size; currentPattern++)
		{

			__try
			{
				*(char*)(currentAddress + currentPattern) == this->pattern[0] || mask[0] == '?';
			}
			__except (EXCEPTION_EXECUTE_HANDLER)
			{
				found = false;
				break;
			}

			if (*(char*)(currentAddress + currentPattern) == this->pattern[0] || mask[0] == '?')
			{

			}
			else
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return currentAddress;
		}
	}

	return 0;
}

uintptr_t SignatureScanner::ScanNotAllocatedMemory(size_t size)
{
	uintptr_t lastAddress = this->moduleBase + this->moduleSize;

	for (uintptr_t currentAddress = this->moduleBase; currentAddress < lastAddress; currentAddress++)
	{
		bool found = true;

		for (size_t succesTimes = 0; succesTimes < size; succesTimes++)
		{
			__try
			{
				*(char*)(currentAddress) == this->pattern[0] || mask[0] == '?';
			}
			__except (EXCEPTION_EXECUTE_HANDLER)
			{
				continue;
			}
			found = false;
			break;
		}
		if (found)
		{
			return currentAddress;
		}
	}

	return 0;
}