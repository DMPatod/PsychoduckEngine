# CMakeList.txt : CMake project for PsyduckEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable(Sandbox "src/Application.cpp")
target_include_directories(Sandbox PUBLIC "${PROJECT_SOURCE_DIR}/PsyduckEngine/src")
target_link_libraries(Sandbox PsyduckEngine)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sandbox PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
