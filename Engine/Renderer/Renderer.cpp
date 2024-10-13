#include "Renderer.h"

#include <Base/Logger.h>
#include <Base/Game.h>

#include "SDL2/SDL.h"

using namespace Tartae;

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
		TARTAE_FATAL("{}", SDL_GetError());
		return;
	}

	EngineSpec _context{};

	_context.window = SDL_CreateWindow(
		"Tartae Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		900, 460,
		SDL_WINDOW_RESIZABLE
	);

	if (!_context.window)
	{
		TARTAE_FATAL("{}", SDL_GetError());
		SDL_Quit();
		return;
	}

	_context.renderer = SDL_CreateRenderer(_context.window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (!_context.renderer)
	{
		TARTAE_FATAL("{}", SDL_GetError());
		SDL_DestroyWindow(_context.window);
		SDL_Quit();
		return;
	}

	_context.state = 1u;

	TARTAE_INFO("SDL Initialized");

	this->EngineContext = &_context;
	Game GameContext;

	GameContext.Start();

	SDL_Event evnt{};

	while (_context.state)
	{
		while (SDL_PollEvent(&evnt))
		{
			if (evnt.type == SDL_QUIT || evnt.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				TARTAE_TRACE("Context State set to 0");
				_context.state = 0u;
			}
		}

		GameContext.Update();

		SDL_RenderClear(_context.renderer);

		GameContext.Render();
		SDL_RenderPresent(_context.renderer);
	}

	SDL_DestroyRenderer(_context.renderer);
	SDL_DestroyWindow(_context.window);

	SDL_Quit();

}
