#include <Renderer/Renderer.h>
#include <Base/Logger.h>

int main()
{
	using Tartae::Renderer;

	Renderer renderer{};

	renderer.RunTheLoop();

	TARTAE_INFO("SDL Context Destroyed");
}