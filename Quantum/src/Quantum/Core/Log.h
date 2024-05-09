#pragma once
#include "Quantum/Core/Base.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "gtx/string_cast.hpp"
// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Quantum {
	class Log
	{
	public:
		static void Init();
		inline static Ref<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}
		inline static Ref<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}
		
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;

	};

}

//-----------------core logger macros------------------------
#define QT_CORE_TRACE(...)	 ::Quantum::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QT_CORE_INFO(...)	 ::Quantum::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QT_CORE_WARN(...)	 ::Quantum::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QT_CORE_ERROR(...)	 ::Quantum::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QT_CORE_FATAL(...)	 ::Quantum::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//-----------------core logger macros for objects------------

//-----------------client logger macros------------------------
#define QT_TRACE(...) ::Quantum::Log::GetClientLogger()->trace(__VA_ARGS__)
#define QT_INFO(...)	 ::Quantum::Log::GetClientLogger()->info(__VA_ARGS__)
#define QT_WARN(...)  ::Quantum::Log::GetClientLogger()->warn(__VA_ARGS__)
#define QT_ERROR(...) ::Quantum::Log::GetClientLogger()->error(__VA_ARGS__)
#define QT_FATAL(...) ::Quantum::Log::GetClientLogger()->fatal(__VA_ARGS__)
//
