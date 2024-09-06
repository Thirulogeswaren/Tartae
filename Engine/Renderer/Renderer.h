#pragma once

namespace Tartae
{
	class Renderer
	{
	public:
		void RunTheLoop();

	private:
		struct EngineSpec;

		EngineSpec* EngineContext;
	};
}