#pragma once



//windows includes
#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
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

typedef uintptr_t PTR;


//backend structs
#include "../backend/Structs.h"
#include "Types/Vector3.h"
#include "../backend/HookManager/HookManager.h"
//sdk
#include "SDK/SDK.h"
#include "functiontypedefs.h"
//il2cpp_resolver


//other custom includes
#include "FeatureManager/FeatureBase/FeatureBase.h"
#include "FeatureManager/FeatureManager.h"
#include "mem/mem.h"
#include "mem/mempatch.h"
#include "SigScan/Sig.h"
#include "Types/INCLUDE_TYPES.h"
#include "il2cpp/il2cpp.h"

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
#include "../features/Account/Account.h"
#include "../features/ESP/ESP.h"
#include "../features/Misc/Misc.h"
#include "../features/Movement/Movement.h"
#include "../features/Player/Player.h"
#include "../features/Weapon/Weapon.h"
#include "../features/Debug/Debug.h"

//menu feature always last
#include "../features/menu/menu.h"

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
