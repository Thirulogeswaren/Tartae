#include "Editor.hpp"

#include <Renderer/Renderer.h>
#include <Base/Logger.h>

#include "SDL2/SDL_main.h"

using Tartae::Editor::EditorClass;

void EditorClass::RenderImGui()
{
	this->e_panel.Render();
}

int main(int argc, char* argv[])
{
	using Tartae::Renderer;

	Renderer renderer{};

	renderer.RunTheLoop();

	TARTAE_INFO("SDL Context Destroyed");

	return EXIT_SUCCESS;
}
