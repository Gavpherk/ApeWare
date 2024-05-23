#pragma once
#include "../include/includes.h"

typedef LONG64 Transform;

typedef UnityEngine_Camera_o* (__stdcall* tGetMainCamera)(void* method);
typedef Vector3(__stdcall* tW2S)(UnityEngine_Camera_o* _this, UnityEngine_Vector3_o target, void* method);
typedef Vector3(__stdcall* tWorldToScreenVec)(UnityEngine_Camera_o* _this, Vector3 target, void* method);
typedef uintptr_t(__stdcall* tGetVector3FroMuintptr_t)(UnityEngine_Animator_o* _this, int humanBoneId, void* method);
typedef void(__stdcall* tTransformSetEulerAngles)(Transform* _this, Vector3 value, void* method);
typedef void(__stdcall* tTransformSetLocalEulerAngles)(Transform* _this, Vector3 value, void* method);
typedef Vector3(__stdcall* tTransformGetEulerAngles)(Transform* _this, void* _Method);
typedef Vector3(__stdcall* tTransformGetLocalEulerAngles)(Transform* _this, void* method);
typedef void(__stdcall* tRotateTransform)(uintptr_t* _this, UnityEngine_Vector3_o eulers, void* method);
typedef System_String_o* (__stdcall* tGetName)(uintptr_t GameObject, void* _Method);
typedef void(__stdcall* tGetNetworkManager)(uintptr_t _this, void* _Method);
typedef Transform* (__stdcall* tGetRootTransform)(Transform* _this, void* _Method);
typedef Transform* (__stdcall* tGetParentTransform)(Transform* uintptr_t, void* _Method);
typedef int32_t(__stdcall* tTransformCountChildren)(Transform* _this, void* _Method);
typedef Transform* (__stdcall* tTransformGetChild)(Transform* _this, int32_t Child, void* _Method);
typedef uintptr_t(__stdcall* tGetGameObject)(uintptr_t component, void* _Method);
typedef Transform* (__stdcall* tGetTransformComponent)(uintptr_t object, void* _Method);
typedef Vector3(__stdcall* tGetTransformPosition)(Transform* _Transform, void* _Method);
typedef void(__stdcall* tTransformSetPosition)(Transform* _this, Vector3 pos, void* _Method);
typedef void(__stdcall* tDestroyObject)(uintptr_t obj, void* _Method);
typedef void* (__stdcall* tGetMainDisplay)(void* _Method);
typedef int(__stdcall* tGetDisplayRenderWidth)(void* _Display, void* _Method);
typedef int(__stdcall* tGetDisplayRenderHeight)(void* _Display, void* _Method);
typedef int(__stdcall* tGetDisplaySystemWidth)(void* _Display, void* _Method);
typedef int(__stdcall* tGetDisplaySystemHeight)(void* _Display, void* _Method);
typedef void(__stdcall* tCreateProjectile)(uintptr_t _this, int type, Vector3 position, Vector3 direction, Vector3 rotation, float force, float upwardForce, void* _Method);
typedef Vector3(__stdcall* tGetTransformForward)(Transform* _this, void* _Method);
typedef Vector3(__stdcall* tGetTransformUp)(Transform* _this, void* _Method);
typedef Transform* (__stdcall* tGetTransformFromComponent)(uintptr_t component, void* _Method);

typedef void(__stdcall* tContactUsClicked)(void* _this, void* _Method);
typedef void(__stdcall* tChestAccrueReward)(void* _this, int value, void* _method);
typedef void(__stdcall* tStartNewGame)(void* _this, void* _method);


inline tGetMainCamera oGetMainCamera = 0;
inline tW2S oW2S = 0;
inline tTransformSetEulerAngles oTransformSetEulerAngles = 0;
inline tTransformSetLocalEulerAngles oTransformSetLocalEulerAngles = 0;
inline tTransformGetEulerAngles oTransformGetEulerAngles = 0;
inline tTransformGetLocalEulerAngles oTransformGetLocalEulerAngles = 0;
inline tGetName oGetName = 0;
inline tGetNetworkManager oGetNetworkManager = 0;
inline tGetParentTransform oGetParentTransform = 0;
inline tTransformGetChild oTransformGetChild = 0;
inline tTransformCountChildren oTransformCountChildren = 0;
inline tGetRootTransform oGetRootTransform = 0;
inline tGetGameObject oGetGameObject = 0;
inline tGetTransformComponent oGetTransformComponent = 0;
inline tGetTransformPosition oGetTransformPosition = 0;
inline tTransformSetPosition oTransformSetPosition = 0;
inline tDestroyObject oDestroyObject = 0;
inline tWorldToScreenVec oWorldToScreenVec = 0;
inline tGetMainDisplay oGetMainDisplay = 0;
inline tGetDisplayRenderWidth oGetDisplayRenderWidth = 0;
inline tGetDisplayRenderHeight oGetDisplayRenderHeight = 0;
inline tGetDisplaySystemWidth oGetDisplaySystemWidth = 0;
inline tGetDisplaySystemHeight oGetDisplaySystemHeight = 0;
inline tCreateProjectile oCreateProjectile = 0;
inline tGetTransformForward oGetTransformForward = 0;
inline tGetTransformUp oGetTransformUp = 0;
inline tGetTransformFromComponent oGetTransformFromComponent = 0;

inline tChestAccrueReward oChestAccrueReward = 0;
inline tContactUsClicked oContactUsClicked = 0;
inline tStartNewGame oStartNewGame = 0;