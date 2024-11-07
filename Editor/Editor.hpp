#pragma once

#include "Inspector/Panel.hpp"

namespace Tartae::Editor
{
	class EditorClass
	{
	public:
		void RenderImGui();

		EditorClass();
	private:
		void SetEditorStyle();

	private:
		Inspector e_panel;
	};
}