#include "Renderer.h"

#include <Base/Logger.h>
#include <Base/Game.h>

#include "SDL2/SDL.h"

#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

using namespace Tartae;

#include "Editor.hpp"

struct Renderer::EngineSpec
{
	SDL_Renderer* renderer;
	SDL_Window* window;
	Uint16 state;
};

void Renderer::RunTheLoop()
{
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
	{
		TARTAE_FATAL("%s", SDL_GetError());
		return;
	}

	EngineSpec _context{};

	auto& [renderer, window, engine_state] = _context;

	window = SDL_CreateWindow(
		"Tartae Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		900, 460,
		SDL_WINDOW_RESIZABLE
	);

	if (!window)
	{
		TARTAE_FATAL("%s", SDL_GetError());
		SDL_Quit();
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)
	{
		TARTAE_FATAL("%s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return;
	}

	TARTAE_INFO("SDL Initialized");

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	ImGui::GetIO().FontGlobalScale = 1.0f;


	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init(renderer);
	
	ImGui::StyleColorsDark();

	this->EngineContext = &_context;
	
	engine_state = 1u;

	SDL_Event evnt{};

	Editor::EditorClass editor_inst{};

	while (engine_state)
	{
		while (SDL_PollEvent(&evnt))
		{
			ImGui_ImplSDL2_ProcessEvent(&evnt);

			if (evnt.type == SDL_QUIT || evnt.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				TARTAE_TRACE("Context engine_state set to 0");
				engine_state = 0u;
			}
		}

		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();

		ImGui::DockSpaceOverViewport(0u,
			ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode
		);

		// Editor ImGui Calls
		editor_inst.RenderImGui();

		ImGui::Render();
		SDL_RenderClear(renderer);

		ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
		SDL_RenderPresent(renderer);
	}

	ImGui_ImplSDLRenderer2_Shutdown();
	ImGui_ImplSDL2_Shutdown();

	ImGui::DestroyContext();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

}
