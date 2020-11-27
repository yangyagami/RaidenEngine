cmake_minimum_required(VERSION 2.6)

project(RaidenEngine)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(RaidenEngine/src/core)
include_directories(RaidenEngine/src/external)
include_directories(RaidenEngine/src/renderer)

aux_source_directory(RaidenEngine/src/core RAIDEN_CORE_SRC)
aux_source_directory(RaidenEngine/src/renderer RAIDEN_RENDERER_SRC)
aux_source_directory(RaidenEngine/src/external RAIDEN_EXTERNAL_SRC)
aux_source_directory(Sandbox/src SANDBOX_SRC)

add_executable(Sandbox ${SANDBOX_SRC} ${RAIDEN_CORE_SRC} ${RAIDEN_RENDERER_SRC} ${RAIDEN_EXTERNAL_SRC})

target_link_libraries(Sandbox GL dl X11 Xrandr glfw m)
