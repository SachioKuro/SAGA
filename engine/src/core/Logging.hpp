#pragma once

#ifdef SAGA_DEBUG
    constexpr int32_t basename_index (const char * const path, const int32_t index = 0, const int32_t slash_index = -1) {
        return path [index]
            ? ( path [index] == '/'
                ? basename_index (path, index + 1, index)
                : basename_index (path, index + 1, slash_index)
            )
            : (slash_index + 1)
        ;
    }
    // stmt-expr version
    #define STRINGIZE_DETAIL(x) #x
    #define STRINGIZE(x) STRINGIZE_DETAIL(x)

    #define __FILELINE__ [](){ \
        static const int32_t basename_idx = basename_index(__FILE__); \
        static_assert (basename_idx >= 0, "compile-time basename"); \
        std::stringstream ss; \
        ss << std::string(__FILE__).substr(basename_idx) << ':' << STRINGIZE(__LINE__) << ": "; \
        return ss.str(); \
    }()

    #define SAGA_LOG(level, message, ...) \
        {std::string msg = "[%s] %s "; \
        msg = msg.append(std::string(message)); \
        printf(msg.c_str(), level, __FILELINE__.c_str(), ##__VA_ARGS__);}
    #define SAGA_INFO(message, ...)       SAGA_LOG("INFO", message, ##__VA_ARGS__)
    #define SAGA_WARNING(message, ...)    SAGA_LOG("WARNING", message, ##__VA_ARGS__)
    #define SAGA_ERROR(message, ...)      SAGA_LOG("ERROR", message, ##__VA_ARGS__)
#else
    #define SAGA_INFO(...)
    #define SAGA_WARNING(...)
    #define SAGA_ERROR(...)
#endif