project(SAGA_engine VERSION 0.0.1)

file(GLOB_RECURSE SRC_FILES src/*.cpp CMAKE_CONFIGURE_DEPENDS)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)
add_library(${PROJECT_NAME} ${SRC_FILES})

add_definitions(-D_DEBUG)
add_definitions(-DSAGA_DEBUG)
add_definitions(-DSAGA_EXPORT)

set(CMAKE_CXX_FLAGS  "-L/opt/homebrew/Cellar/sdl2/2.0.22/lib -lSDL2 -L/opt/homebrew/Cellar/sdl2_image/2.6.0_1/lib -lSDL2_image -L/opt/homebrew/Cellar/sdl2_mixer/2.6.0/lib -lSDL2_mixer -L/opt/homebrew/Cellar/sdl2_ttf/2.20.0/lib -lSDL2_ttf")

target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
