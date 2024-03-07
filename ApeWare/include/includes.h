#pragma once

//windows includes
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cmath>
#include <chrono>
#include <random>
#include <fstream>
#include <stdio.h>
#include <Windows.h>
#include <unordered_map>

//nhloman json
#include "json/json.h"
using json = nlohmann::json;

//HookManager
//#include "Hooking/Hook.h"

//backend structs
#include "../backend/Structs.h"

//sdk
#include "SDK/SDK.h"

//il2cpp_resolver

//other custom includes
#include "FeatureManager/FeatureBase/FeatureBase.h"
#include "FeatureManager/FeatureManager.h"
#include "mem/mem.h"
#include "SigScan/Sig.h"
#include "Types/INCLUDE_TYPES.h"
#include "il2cpp/il2cpp.h"
#include "functiontypedefs.h"

//imgui /keiro includes
#include <d3d11.h>
#include <dxgi.h>
#include "kiero/kiero.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"

//globals
#include "Globals.h"

//feature includes
#include "../features/Player/player.h"
#include "../features/Weapon/weapon.h"
//menu feature last
#include "../features/menu/menu.h"

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;