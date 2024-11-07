#include <Renderer/Renderer.h>
#include <Base/Logger.h>

#include "SDL2/SDL_main.h"

int main(int argc, char* argv[])
{
	using Tartae::Renderer;

	Renderer renderer{};

	renderer.RunTheLoop();

	TARTAE_INFO("SDL Context Destroyed");

	return EXIT_SUCCESS;
}
