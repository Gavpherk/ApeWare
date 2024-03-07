#pragma once
#include "../../include/includes.h"

LONG64* GetUnityStaticField(LONG64 offsetTypeinfo);

char* SystemStringToStdString(System_String_o* _Str);

Vector3 UnityVector3ToCPPVector3(UnityEngine_Vector3_o* unityVec);

UnityEngine_Vector3_o* CPPVector3ToUnityVector3(Vector3 cppVec);