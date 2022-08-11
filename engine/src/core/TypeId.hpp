#pragma once

#include "pch.hpp"

namespace SAGA {
    SAGA_INLINE const uint32_t GetUniqueTypeID() {
        static uint32_t type = 0u;
        return ++type;
    }

    template <typename T>
    SAGA_INLINE const uint32_t TypeID() {
        static const uint32_t type = GetUniqueTypeID();
        return type;
    }
}