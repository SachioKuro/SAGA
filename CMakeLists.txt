# Helper function to add preprocesor definition of FILE_BASENAME
# to pass the filename without directory path for debugging use.
#
# Note that in header files this is not consistent with
# __FILE__ and __LINE__ since FILE_BASENAME will be the
# compilation unit source file name (.c/.cpp).
#
# Example:
#
#   define_file_basename_for_sources(my_target)
#
# Will add -DFILE_BASENAME="filename" for each source file depended on
# by my_target, where filename is the name of the file.
#

cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_COMPILER /opt/homebrew/Cellar/llvm/14.0.6_1/bin/clang++)

project(SAGA VERSION 0.0.1)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SDL2_INCLUDE "/opt/homebrew/Cellar/sdl2/2.0.22/include")
set(SDL2_CORE_INCLUDE "/opt/homebrew/Cellar/sdl2/2.0.22/include/SDL2")
set(SDL2_IMAGE_INCLUDE "/opt/homebrew/Cellar/sdl2_image/2.6.0_1/include")
set(SDL2_MIXER_INCLUDE "/opt/homebrew/Cellar/sdl2_mixer/2.6.0/include")
set(SDL2_TTF_INCLUDE "/opt/homebrew/Cellar/sdl2_ttf/2.20.0/include")
set(FMT_INCLUDE "vendor/fmt-9.0.0/include")
set(GLM_INCLUDE "vendor/glm")
include_directories(
    ${SDL2_CORE_INCLUDE}
    ${SDL2_INCLUDE}
    ${SDL2_IMAGE_INCLUDE}
    ${SDL2_MIXER_INCLUDE}
    ${SDL2_TTF_INCLUDE}
    ${FMT_INCLUDE}
    ${GLM_INCLUDE}
)

add_subdirectory(engine)
add_subdirectory(game)
add_subdirectory(vendor/fmt-9.0.0)
add_subdirectory(vendor/glm)