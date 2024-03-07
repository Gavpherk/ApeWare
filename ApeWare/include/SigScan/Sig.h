#pragma once

class SignatureScanner
{
public:
	uintptr_t moduleBase;
	size_t moduleSize;
	char* pattern;
	char* mask;

	SignatureScanner(const char* moduleName, size_t moduleSize, char* pattern, char* mask);
	SignatureScanner(uintptr_t start, uintptr_t end, char* pattern, char* mask);
	uintptr_t Scan();
	uintptr_t ScanRepeatable(size_t size);
	uintptr_t ScanNotAllocatedMemory(size_t size);
};