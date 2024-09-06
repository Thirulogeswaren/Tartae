#pragma once

#include <fmt/base.h>
#include <fmt/color.h>

#define TARTAE_INFO(x, ...) \
	fmt::print(fg(fmt::color::light_green), "[INFO]> "); TARTAELOG(x, __VA_ARGS__)

#define TARTAE_TRACE(x, ...) \
	fmt::print(fg(fmt::color::light_coral), "[TRACE]> "); TARTAELOG(x, __VA_ARGS__)

#define TARTAE_WARN(x, ...) \
	fmt::print(fg(fmt::color::yellow), "[WARN]> "); TARTAELOG(x, __VA_ARGS__)

#define TARTAE_ERROR(x, ...) \
	fmt::print(fg(fmt::color::red), "[ERROR]> "); TARTAELOG(x, __VA_ARGS__)

#define TARTAE_FATAL(x, ...) \
	fmt::print(fg(fmt::color::red), "[FATAL]> "); TARTAELOG(x, __VA_ARGS__)

#define TARTAELOG(x, ...) fmt::println(x, __VA_ARGS__)
