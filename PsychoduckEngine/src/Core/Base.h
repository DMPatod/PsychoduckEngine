#pragma once

#include <filesystem>

#ifdef PsychoduckEngine_BUILD_PLATFORM_WINDOWS
#ifdef PsychoduckEngine_EXPORTS
#define PsychoduckEngine_API __declspec(dllexport)
#else
#define PsychoduckEngine_API __declspec(dllimport)
#endif //PsychoduckEngine_EXPORTS
#else
#error Only Windows Application is Supported!
#endif //PsychoduckEngine_BUILD_PLATFORM_WINDOWS

#ifdef ENABLE_ASSERTS
#define ENGINE_ASSERT(x, ...) { if(!(x)) { CONSOLE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define CORE_ASSERT(x, ...) { if(!(x)) { CONSOLE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define ENGINE_ASSERT(x, ...)
#define CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

namespace PsychoduckEngine {
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}