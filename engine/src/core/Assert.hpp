#pragma once

#ifdef SAGA_DEBUG
    #define SAGA_ASSERT(condition, message, ...) \
        fprintf(stderr, "[ASSERT] %s:%d: %s\n", __FILE__, __LINE__, message); \
        if (!(condition)) { \
            assert(condition); \
        }
    #define SAGA_STATIC_ASSERT(condition, message) \
        static_assert(condition, message)
#else
    #define SAGA_ASSERT(condition, message, ...)
    #define SAGA_STATIC_ASSERT(condition, message)
#endif