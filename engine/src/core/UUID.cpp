#include "UUID.hpp"

namespace SAGA {
    uuid64 GenerateUUID() {
        static uuid64 uuid = 0;
        return ++uuid;
    }
}