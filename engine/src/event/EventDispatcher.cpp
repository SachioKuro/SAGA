#include "EventDispatcher.hpp"

namespace SAGA {
    void EventDispatcher::Dispatch(uint32_t event_mask) {
        for (const auto* event : m_events) {
            if (event->GetType() & event_mask) {
                SAGA_ASSERT(
                    m_callbacks.find(event->GetType()) != m_callbacks.end(),
                    "No callback registered for event type: %s", 
                    EventTypeToString(event->GetType())
                );
                m_callbacks[event->GetType()](event);
            }
        }
    }
}