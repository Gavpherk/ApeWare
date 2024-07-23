#include "include/includes.h"
#include "backend/interface/interface.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Cheat APEWARE; // Init cheat objext
std::vector<const char*> typeinfos = {""}; // for filters, so little in this game filters are not needed.
std::vector<const char*> classes = {"UnityEngine.Display", "UnityEngine.Camera", "UnityEngine.Transform", "UnityEngine.Cursor"};
std::vector<std::pair<const char*, FeatureBase*>> Features =
{
	{"Menu", new Menu},
	{"Player", new Player},
	{"ESP", new ESP},
	{"Weapon", new Weapon},
	{"Movement", new Movement},
	{"Misc", new Misc},
	{"Account", new Account},
	{"Debug", new DEBUG}
};

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, Globals::pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool init = false;

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			APEWARE.RegisterTypeInfos(typeinfos); // sets up filters for parsing typeinfos
			APEWARE.RegisterFunctionClasses(classes); // sets up filters for parsing functions

			APEWARE.InitTypeInfoSystem(false);
			APEWARE.InitFunctionSystem(false);

			APEWARE.SetupCheat(Features); // Init cheat classes, init typeinfo and function filters, parse jsons, populate function and typeinfo vectors.

			pDevice->GetImmediateContext(&Globals::pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &Globals::mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;

		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}
	
	APEWARE.UpdateBackendTypeInfos();
	bool CheatLooping = APEWARE.LoopCheat(); // Loops all the features, tracks menu state.

	if (!CheatLooping)
	{
		Globals::featureManager.RemoveAll();
		APEWARE.DisableALLHooks();
		kiero::shutdown();
		return 0;
	}

	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			init_hook = true;
			AllocConsole();
			FILE * f;
			freopen_s(&f, "CONOUT$", "w", stdout);
		}

	}
	while (!init_hook);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}