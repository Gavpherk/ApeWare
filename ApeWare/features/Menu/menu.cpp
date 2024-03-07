#pragma once
#include "menu.h"


void Menu::OnInit()
{
	g_menu = (Menu*)Globals::featureManager.FindFeature("Menu");
	g_weapon = (Weapon*)Globals::featureManager.FindFeature("Weapon");
	g_player = (Player*)Globals::featureManager.FindFeature("Player");
}


void Menu::OnLoop()
{

}

void Menu::OnUnInit()
{

}

void Menu::OnRender()
{
	if (Globals::ref_menu->bToggle)
	{
		//PRE-RENDER
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();


		//THEME
		ImGuiStyle& style = ImGui::GetStyle();
		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
		style.Colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		style.Colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style.Colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
		style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
		style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
		style.Colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
		style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
		style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
		style.Colors[ImGuiCol_CheckMark] = ImVec4(0.05f, 0.65f, 0.69f, 1.00f);
		style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.05f, 0.65f, 0.69f, 1.00f);
		style.Colors[ImGuiCol_Button] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.05f, 0.65f, 0.69f, 1.00f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_Header] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_Separator] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_Tab] = ImVec4(0.70f, 0.18f, 0.33f, 1.00f);
		style.Colors[ImGuiCol_TabHovered] = ImVec4(0.05f, 0.65f, 0.69f, 1.00f);
		style.Colors[ImGuiCol_TabActive] = ImVec4(0.05f, 0.65f, 0.69f, 1.00f);
		style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.05f, 0.65f, 0.69f, 1.00f);
		style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
		//style.Colors[ImGuiCol_DockingPreview] = ImVec4(0.26f, 0.59f, 0.98f, 0.70f);
		//style.Colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
		style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		//style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
		//style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
		//style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
		//style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		//style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
		style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
		style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
		style.ChildRounding = 12.00f;
		style.FrameRounding = 12.00f;
		style.GrabRounding = 12.00f;
		style.PopupRounding = 7.00f;
		style.ScrollbarRounding = 9.00f;
		style.TabRounding = 12.00f;
		style.WindowRounding = 12.00f;
		style.WindowPadding = ImVec2(3, 6);
		style.FramePadding = ImVec2(20, 7);
		//style.CellPadding = ImVec2(8, 4);
		style.ItemSpacing = ImVec2(20, 9);
		style.ItemInnerSpacing = ImVec2(10, 13);
		style.TouchExtraPadding = ImVec2(0, 0);
		style.IndentSpacing = 21.00f;
		style.ScrollbarSize = 1.00f;
		style.GrabMinSize = 13.00f;
		style.WindowBorderSize = 1.00f;
		style.ChildBorderSize = 1.00f;
		style.PopupBorderSize = 1.00f;
		style.FrameBorderSize = 1.00f;
		style.TabBorderSize = 1.00;
		style.WindowTitleAlign = ImVec2(0.5, 0.5);
		ImGui::SetNextWindowSize(ImVec2{ 1600, 600 }, ImGuiCond_Once);
		ImGui::SetNextWindowBgAlpha(1.0f);

		//menu
		ImGui::Begin("Apeware");
		{
			ImVec2 mouse_pos = ImGui::GetMousePos();
			ImVec2 circle_center = ImVec2(mouse_pos.x, mouse_pos.y + 4);

			ImGui::GetForegroundDrawList()->AddCircleFilled(circle_center, 4, IM_COL32(255, 255, 255, 255)); 

			
			ImVec2 p1(mouse_pos.x, mouse_pos.y - 8);
			ImVec2 p2(mouse_pos.x - 5, mouse_pos.y + 2);
			ImVec2 p3(mouse_pos.x + 5, mouse_pos.y + 2);
			ImGui::GetForegroundDrawList()->AddTriangleFilled(p1, p2, p3, IM_COL32(255, 255, 255, 255));

			if (ImGui::BeginTabBar("Features")) 
			{
				if (ImGui::BeginTabItem("Player")) 
				{
					if (ImGui::Button("Unlock All"))
					{
						g_player->UnlockAll(true);
					}

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("Weapon")) 
				{
					if (ImGui::Checkbox("Instant Reload", &g_InstantReload))
					{
						g_weapon->InstantReload(g_InstantReload);
					}

					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("Debug"))
				{

					if (ImGui::BeginChild("DebugTab"))
					{
						if (ImGui::Button("TypeInfos"))
						{
							debugtypeinfos = !debugtypeinfos;
						}

						if (ImGui::Button("Methods"))
						{
							debugmethods = !debugmethods;
						}

						if (ImGui::Button("TestButton"))
						{
							
						}

						if (debugtypeinfos)
						{
							for (size_t i = 0; i < Globals::typeinfos.size(); ++i) {
								const auto& typeinfo = Globals::typeinfos[i];

								if (typeinfo->populated == false)
									continue;
								if (ImGui::TreeNode((typeinfo->name.c_str())))
								{
									ImGui::Text("Address: %d", typeinfo->address);
									ImGui::Text("Name: %s", typeinfo->name.c_str());
									ImGui::Text("Static Field: %p", typeinfo->staticfield);
									ImGui::Text("Populated: %s", typeinfo->populated ? "True" : "False");
									if (ImGui::Button("Turn Off"))
									{
										debugtypeinfos = !debugtypeinfos;
									}
									ImGui::TreePop();
								}
							}
						}

						if (debugmethods)
						{
							for (size_t i = 0; i < Globals::functions.size(); ++i) {
								const auto& function = Globals::functions[i];

								if (!function)
									continue;
								std::string name = function->ClassName + "$$" + function->MethodName;
								if (ImGui::TreeNode((name.c_str())))
								{
									ImGui::Text("Address: %d", function->address);
									ImGui::Text("Class Name: %s", function->ClassName);
									ImGui::Text("Method Name: %s", function->MethodName.c_str());
									ImGui::Text("Method RVA: %p", function->RVA);
									if (ImGui::Button("Turn Off"))
									{
										debugtypeinfos = !debugtypeinfos;
									}
									ImGui::TreePop();
								}
							}
						}
					}
					ImGui::EndChild();
					ImGui::EndTabItem();
				}

				ImGui::EndTabBar();
			}

		}

		ImGui::End();

		ImGui::Render();

		Globals::pContext->OMSetRenderTargets(1, &Globals::mainRenderTargetView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}
}

