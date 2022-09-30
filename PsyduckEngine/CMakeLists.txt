# CMakeList.txt : CMake project for PsyduckEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory("include")

# Add source to this project's executable.
add_library(PsyduckEngine SHARED "src/PsyduckEngine.h" "src/Core/Application.h" "src/Core/Application.cpp" "src/Core/Base.h" "src/Core/EntryPoint.h" "src/Core/Log.h" "src/Core/Log.cpp" "src/Core/KeyCodes.h" "src/Events/Event.h" "src/Events/KeyEvent.h" "src/Events/MouseEvent.h" "src/Core/MouseCodes.h" "src/Events/ApplicationEvent.h")

target_link_libraries(PsyduckEngine spdlog)

target_include_directories(PsyduckEngine PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>" "$<INSTALL_INTERFACE:include>")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PsyduckEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.