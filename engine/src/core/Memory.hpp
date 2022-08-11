#pragma once

#ifdef SAGA_DEBUG
    #define SAGA_DELETE(object) \
        if (object != nullptr) { \
            delete object; \
            object = nullptr; \
        } else { \
            SAGA_ERROR("Tried to delete nullptr: %s", object); \
        }
#else
    #define SAGA_DELETE(object) \
        delete object; \
        object = nullptr;
#endif