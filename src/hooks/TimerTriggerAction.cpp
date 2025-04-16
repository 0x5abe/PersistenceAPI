#include "hooks/TimerTriggerAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PATimerTriggerAction::load(Stream& i_stream) {
    i_stream >> *this;
}

void PATimerTriggerAction::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PATimerTriggerAction& o_value) {
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_disabled;
        SEPARATOR_I
        i_stream >> o_value.m_time;
        SEPARATOR_I
        i_stream >> o_value.m_targetTime;
        SEPARATOR_I
        i_stream >> o_value.m_targetGroupID;
        SEPARATOR_I
        i_stream >> o_value.m_triggerUniqueID;
        SEPARATOR_I
        i_stream >> o_value.m_controlID;
        SEPARATOR_I
        i_stream >> o_value.m_itemID;
        SEPARATOR_I
        i_stream >> o_value.m_multiActivate;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value), 32);
    }
    VEC_SEPARATOR_I
    i_stream >> o_value.m_remapKeys;
    VEC_SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PATimerTriggerAction& i_value) {
    o_stream << i_value.m_disabled;
    SEPARATOR_O
    o_stream << i_value.m_time;
    SEPARATOR_O
    o_stream << i_value.m_targetTime;
    SEPARATOR_O
    o_stream << i_value.m_targetGroupID;
    SEPARATOR_O
    o_stream << i_value.m_triggerUniqueID;
    SEPARATOR_O
    o_stream << i_value.m_controlID;
    SEPARATOR_O
    o_stream << i_value.m_itemID;
    SEPARATOR_O
    o_stream << i_value.m_multiActivate;
    VEC_SEPARATOR_O
    o_stream << i_value.m_remapKeys;
    VEC_SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PATimerTriggerAction::describe() {
    log::info("[PATimerTriggerAction - describe] m_disabled: {}", m_disabled);
    log::info("[PATimerTriggerAction - describe] m_time: {}", m_time);
    log::info("[PATimerTriggerAction - describe] m_targetTime: {}", m_targetTime);
    log::info("[PATimerTriggerAction - describe] m_targetGroupID: {}", m_targetGroupID);
    log::info("[PATimerTriggerAction - describe] m_triggerUniqueID: {}", m_triggerUniqueID);
    log::info("[PATimerTriggerAction - describe] m_controlID: {}", m_controlID);
    log::info("[PATimerTriggerAction - describe] m_itemID: {}", m_itemID);
    log::info("[PATimerTriggerAction - describe] m_multiActivate: {}", m_multiActivate);
    int l_size = m_remapKeys.size();
    log::info("[PATimerTriggerAction - describe] m_remapKeys.size(): {}", l_size);
    for (int i = 0; i < l_size; i++) {
        log::info("[PATimerTriggerAction - describe] m_remapKeys[{}]: {}", i, m_remapKeys[i]);
    }
}
#endif