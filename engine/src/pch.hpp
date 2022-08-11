#pragma once

#include <set>
#include <random>
#include <limits>
#include <vector>
#include <string>
#include <bitset>
#include <cassert>
#include <assert.h>
#include <memory>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <utility>
#include <format>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "core/Logging.hpp"
#include "core/Assert.hpp"

#ifdef SAGA_EXPORT
    #ifdef _MSC_VER
        #define SAGA_API __declspec(dllexport)
    #else
        #define SAGA_API __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define SAGA_API __declspec(dllimport)
    #else
        #define SAGA_API
    #endif
#endif

#if defined(__clang__) || defined(__gcc__)
    #define SAGA_INLINE __attribute__((always_inline)) inline
    #define SAGA_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
    #define SAGA_INLINE __forceinline
    #define SAGA_NOINLINE __declspec(noinline)
#else
    #define SAGA_INLINE inline
    #define SAGA_NOINLINE
#endif