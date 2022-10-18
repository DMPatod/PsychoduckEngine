cmake_minimum_required (VERSION 3.8)

add_subdirectory("include")

# project's executable.
add_library(PsychoduckEngine SHARED "src/PsychoduckEngine.h" "src/Core/Application.h" "src/Core/Application.cpp" "src/Core/Base.h" "src/Core/EntryPoint.h" "src/Core/Log.h" "src/Core/Log.cpp" "src/Core/KeyCodes.h" "src/Events/Event.h" "src/Events/KeyEvent.h" "src/Events/MouseEvent.h" "src/Core/MouseCodes.h" "src/Events/ApplicationEvent.h"  "src/Core/Window.h" "src/Core/Window.cpp" "src/PlatformEspecifics/Windows/WindowsWindow.h" "src/PlatformEspecifics/Windows/WindowsWindow.cpp")

target_precompile_headers(PsychoduckEngine PUBLIC "src/pepch.h")

target_link_libraries(PsychoduckEngine spdlog)

target_link_libraries(PsychoduckEngine SDL2)
target_link_libraries(PsychoduckEngine SDL2main)
target_link_libraries(PsychoduckEngine Opengl32)

target_include_directories(PsychoduckEngine PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>" "$<INSTALL_INTERFACE:include>")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PsychoduckEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

if(WIN32)
	target_compile_definitions(PsychoduckEngine PUBLIC PsychoduckEngine_BUILD_PLATFORM_WINDOWS ON)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	#target_compile_definitions(PsychoduckEngine PUBLIC ENABLE_ASSERTS)
endif()

#define obj and bin dir