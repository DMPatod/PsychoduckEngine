#pragma once

#include <filesystem>

#ifdef PsyduckEngine_EXPORTS
#define PsyduckEngine_API __declspec(dllexport)
#else
#define PsyduckEngine_API __declspec(dllimport)
#endif //PsyduckEngine_EXPORTS

#define BIT(x) (1 << x)

namespace PsyduckEngine {
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