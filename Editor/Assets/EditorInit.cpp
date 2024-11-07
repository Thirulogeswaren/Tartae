#include "Editor.hpp"

#include "imgui.h"
#include "imgui_impl_sdl2.h"

using Tartae::Editor::EditorClass;

EditorClass::EditorClass()
{
	ImGui::GetIO().Fonts->AddFontFromFileTTF("cousine.ttf", 18.0f);

	this->SetEditorStyle();
}

void EditorClass::SetEditorStyle()
{
	static constexpr ImVec4 Grey = ImVec4(0.24f, 0.24f, 0.24f, 1.0f);
	static constexpr ImVec4 DarkGrey = ImVec4(0.07f, 0.07f, 0.07f, 1.0f);
	static constexpr ImVec4 RedLike = ImVec4(0.86f, 0.47f, 0.47f, 1.0f);

	auto& color = ImGui::GetStyle().Colors;

	color[ImGuiCol_WindowBg] = DarkGrey;

	color[ImGuiCol_TitleBg] = Grey;
	color[ImGuiCol_TitleBgActive] = Grey;

	color[ImGuiCol_TabActive] = DarkGrey;
	color[ImGuiCol_TabUnfocusedActive] = DarkGrey;

	color[ImGuiCol_TabHovered] = RedLike;

	color[ImGuiCol_FrameBg] = Grey;
	color[ImGuiCol_FrameBgHovered] = RedLike;
	color[ImGuiCol_FrameBgActive] = Grey;

	color[ImGuiCol_Button] = Grey;
	color[ImGuiCol_ButtonHovered] = RedLike;
	color[ImGuiCol_ButtonActive] = Grey;

	color[ImGuiCol_SliderGrab] = Grey;
	color[ImGuiCol_SliderGrabActive] = RedLike;

	color[ImGuiCol_ResizeGrip] = Grey;
	color[ImGuiCol_ResizeGripActive] = Grey;
	color[ImGuiCol_ResizeGripHovered] = RedLike;

	color[ImGuiCol_Header] = Grey;
	color[ImGuiCol_HeaderActive] = Grey;
	color[ImGuiCol_HeaderHovered] = RedLike;

	color[ImGuiCol_CheckMark] = RedLike;
	color[ImGuiCol_DockingPreview] = Grey;
}