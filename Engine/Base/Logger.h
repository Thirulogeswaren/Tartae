#ifndef TARTAE_LOGGER_HEADER_HH
#define TARTAE_LOGGER_HEADER_HH

#include <fmt/base.h>
#include <fmt/color.h>

#include <string_view>

namespace Tartae
{
	class Logger
	{
	public:
		enum Level : std::uint8_t { INFO = 0, WARN, TRACE, ERROR, FATAL, COUNT };

		template <Level severity, typename... Ts>
		static void DispatchMessage(fmt::format_string<Ts...> fmt, Ts&&... args)
		{
			fmt::print(fmt::fg(defined_levels[severity].first), defined_levels[severity].second.data());
			fmt::println(fmt, std::forward<Ts>(args)...);
		}

	private:
		static constexpr std::pair<fmt::color, std::string_view> defined_levels[] = {
			std::make_pair(fmt::color::light_green, "[INFO] "),
			std::make_pair(fmt::color::light_yellow, "[WARN] "),
			std::make_pair(fmt::color::light_coral, "[TRACE] "),
			std::make_pair(fmt::color::dark_khaki, "[ERROR] "),
			std::make_pair(fmt::color::dark_red, "[FATAL] ")
		};
	};

}

#define TARTAE_INFO(x, ...)		Tartae::Logger::DispatchMessage<Tartae::Logger::INFO>(x, ##__VA_ARGS__)
#define TARTAE_WARN(x, ...)		Tartae::Logger::DispatchMessage<Tartae::Logger::WARN>(x, ##__VA_ARGS__)
#define TARTAE_TRACE(x, ...)	Tartae::Logger::DispatchMessage<Tartae::Logger::TRACE>(x, ##__VA_ARGS__)
#define TARTAE_ERROR(x, ...)	Tartae::Logger::DispatchMessage<Tartae::Logger::ERROR>(x, ##__VA_ARGS__)
#define TARTAE_FATAL(x, ...)	Tartae::Logger::DispatchMessage<Tartae::Logger::FATAL>(x, ##__VA_ARGS__)

#endif
