#pragma once
#include "../include/includes.h"
#include "../backend/HookManager/HookManager.h"

namespace Globals
{
	inline LONG64* g_hookmanager;
	inline ID3D11DeviceContext* pContext = NULL;
	inline ID3D11RenderTargetView* mainRenderTargetView;
	inline FeatureManager featureManager;
	inline FeatureBase* ref_menu;
	inline bool allfieldspopulated = false;
	inline std::vector<std::shared_ptr<jTypeinfo>> typeinfos;
	inline std::vector<std::string> requestedtypeinfos;
	inline std::vector<std::shared_ptr<JFunction>> functions;
	inline std::vector<std::string> requestedClasses;


	namespace Game
	{

		inline uintptr_t moduleBase = 0xDEADBEEF;

		namespace FeatureGlobals
		{

		}

		namespace Offsets
		{

		}
	}
}

