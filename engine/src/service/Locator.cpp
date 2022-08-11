#include "Locator.hpp"

namespace SAGA {
    std::unordered_map<uint32_t, void*> Locator::s_services = {};
}