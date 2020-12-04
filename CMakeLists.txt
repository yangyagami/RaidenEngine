cmake_minimum_required(VERSION 2.6)

project(RaidenEngine)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(RaidenEngine/src/core)
include_directories(RaidenEngine/src/external)
include_directories(RaidenEngine/src/renderer)
include_directories(RaidenEngine/src/input)

aux_source_directory(RaidenEngine/src/core RAIDEN_CORE_SRC)
aux_source_directory(RaidenEngine/src/renderer RAIDEN_RENDERER_SRC)
aux_source_directory(RaidenEngine/src/external RAIDEN_EXTERNAL_SRC)
aux_source_directory(RaidenEngine/src/input RAIDEN_INPUT_SRC)
aux_source_directory(Sandbox/src RAIDEN_SANDBOX_SRC)

add_executable(Sandbox ${RAIDEN_SANDBOX_SRC} ${RAIDEN_CORE_SRC} ${RAIDEN_RENDERER_SRC} ${RAIDEN_EXTERNAL_SRC} ${RAIDEN_INPUT_SRC})

target_link_libraries(Sandbox GL dl X11 Xrandr glfw m)
