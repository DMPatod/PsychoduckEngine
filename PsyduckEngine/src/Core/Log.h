#pragma once

#include "Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace PsyduckEngine {
	class PsyduckEngine_API Log {
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

#define CONSOLE_CORE_TRACE(...) ::PsyduckEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CONSOLE_CORE_INFO(...) ::PsyduckEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CONSOLE_CORE_WARN(...) ::PsyduckEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CONSOLE_CORE_ERROR(...) ::PsyduckEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CONSOLE_CORE_CRITICAL(...) ::PsyduckEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define CONSOLE_TRACE(...) ::PsyduckEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CONSOLE_INFO(...) ::PsyduckEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CONSOLE_WARN(...) ::PsyduckEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CONSOLE_ERROR(...) ::PsyduckEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CONSOLE_CRITICAL(...) ::PsyduckEngine::Log::GetClientLogger()->critical(__VA_ARGS__)