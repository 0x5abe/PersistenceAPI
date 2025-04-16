#include "hooks/ToggleTriggerAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAToggleTriggerAction::load(Stream& i_stream) {
    i_stream >> *this;
}

void PAToggleTriggerAction::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAToggleTriggerAction& o_value) {
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_disabled;
        SEPARATOR_I
        i_stream >> o_value.m_targetGroupID;
        SEPARATOR_I
        i_stream >> o_value.m_activateGroup;
        SEPARATOR_I
        i_stream >> o_value.m_triggerUniqueID;
        SEPARATOR_I
        i_stream >> o_value.m_controlID;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value), 20);
    }
    VEC_SEPARATOR_I
    i_stream >> o_value.m_remapKeys;
    VEC_SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAToggleTriggerAction& i_value) {
    o_stream << i_value.m_disabled;
    SEPARATOR_O
    o_stream << i_value.m_targetGroupID;
    SEPARATOR_O
    o_stream << i_value.m_activateGroup;
    SEPARATOR_O
    o_stream << i_value.m_triggerUniqueID;
    SEPARATOR_O
    o_stream << i_value.m_controlID;
    VEC_SEPARATOR_O
    o_stream << i_value.m_remapKeys;
    VEC_SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAToggleTriggerAction::describe() {
    log::info("[PAToggleTriggerAction - describe] m_disabled: {}", m_disabled);
    log::info("[PAToggleTriggerAction - describe] m_targetGroupID: {}", m_targetGroupID);
    log::info("[PAToggleTriggerAction - describe] m_activateGroup: {}", m_activateGroup);
    log::info("[PAToggleTriggerAction - describe] m_triggerUniqueID: {}", m_triggerUniqueID);
    log::info("[PAToggleTriggerAction - describe] m_controlID: {}", m_controlID);
    int l_size = m_remapKeys.size();
    log::info("[PAToggleTriggerAction - describe] m_remapKeys.size(): {}", l_size);
    for (int i = 0; i < l_size; i++) {
        log::info("[PAToggleTriggerAction - describe] m_remapKeys[{}]: {}", i, m_remapKeys[i]);
    }
}
#endif