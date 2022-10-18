#pragma once

#include "Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace PsychoduckEngine {
	class PsychoduckEngine_API Log {
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

#define CONSOLE_CORE_TRACE(...) ::PsychoduckEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CONSOLE_CORE_INFO(...) ::PsychoduckEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CONSOLE_CORE_WARN(...) ::PsychoduckEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CONSOLE_CORE_ERROR(...) ::PsychoduckEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CONSOLE_CORE_CRITICAL(...) ::PsychoduckEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define CONSOLE_TRACE(...) ::PsychoduckEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CONSOLE_INFO(...) ::PsychoduckEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CONSOLE_WARN(...) ::PsychoduckEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CONSOLE_ERROR(...) ::PsychoduckEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CONSOLE_CRITICAL(...) ::PsychoduckEngine::Log::GetClientLogger()->critical(__VA_ARGS__)