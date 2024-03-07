#include "il2cpp.h"

LONG64* GetUnityStaticField(LONG64 offsetTypeinfo)
{
	__try
	{
		return *(LONG64**)(*(LONG64*)(Globals::Game::moduleBase + offsetTypeinfo) + 0xA8);
	}
	__except (1)
	{
		return nullptr;
	}
}

char* SystemStringToStdString(System_String_o* _Str)
{
	char* buf = new char[_Str->fields._stringLength + 1];

	for (size_t i = 0; i < _Str->fields._stringLength; i++)
	{
		buf[i] = *(char*)(&_Str->fields._firstChar + i);
	}
	buf[_Str->fields._stringLength] = '\0';
	return buf;
}

Vector3 UnityVector3ToCPPVector3(UnityEngine_Vector3_o* unityVec)
{
	Vector3 cppVec;

	cppVec.x = unityVec->fields.x;
	cppVec.y = unityVec->fields.y;
	cppVec.z = unityVec->fields.z;
	return cppVec;
}

UnityEngine_Vector3_o* CPPVector3ToUnityVector3(Vector3 cppVec)
{
	UnityEngine_Vector3_o* unityVec = new UnityEngine_Vector3_o;

	unityVec->fields.x = cppVec.x;
	unityVec->fields.y = cppVec.y;
	unityVec->fields.z = cppVec.z;
	return unityVec;
}