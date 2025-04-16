#include "hooks/CountTriggerAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PACountTriggerAction::load(Stream& i_stream) {
    i_stream >> *this;
}

void PACountTriggerAction::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PACountTriggerAction& o_value) {
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_disabled;
        SEPARATOR_I
        i_stream >> o_value.m_previousCount;
        SEPARATOR_I
        i_stream >> o_value.m_targetCount;
        SEPARATOR_I
        i_stream >> o_value.m_targetGroupID;
        SEPARATOR_I
        i_stream >> o_value.m_activateGroup;
        SEPARATOR_I
        i_stream >> o_value.m_triggerUniqueID;
        SEPARATOR_I
        i_stream >> o_value.m_controlID;
        SEPARATOR_I
        i_stream >> o_value.m_itemID;
        SEPARATOR_I
        i_stream >> o_value.m_multiActivate;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value), 36);
    }
    VEC_SEPARATOR_I
    i_stream >> o_value.m_remapKeys;
    VEC_SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PACountTriggerAction& i_value) {
    o_stream << i_value.m_disabled;
    SEPARATOR_O
    o_stream << i_value.m_previousCount;
    SEPARATOR_O
    o_stream << i_value.m_targetCount;
    SEPARATOR_O
    o_stream << i_value.m_targetGroupID;
    SEPARATOR_O
    o_stream << i_value.m_activateGroup;
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
void PACountTriggerAction::describe() {
    log::info("[PACountTriggerAction - describe] m_disabled: {}", m_disabled);
    log::info("[PACountTriggerAction - describe] m_previousCount: {}", m_previousCount);
    log::info("[PACountTriggerAction - describe] m_targetCount: {}", m_targetCount);
    log::info("[PACountTriggerAction - describe] m_targetGroupID: {}", m_targetGroupID);
    log::info("[PACountTriggerAction - describe] m_activateGroup: {}", m_activateGroup);
    log::info("[PACountTriggerAction - describe] m_triggerUniqueID: {}", m_triggerUniqueID);
    log::info("[PACountTriggerAction - describe] m_controlID: {}", m_controlID);
    log::info("[PACountTriggerAction - describe] m_itemID: {}", m_itemID);
    log::info("[PACountTriggerAction - describe] m_multiActivate: {}", m_multiActivate);
    int l_size = m_remapKeys.size();
    log::info("[PACountTriggerAction - describe] m_remapKeys.size(): {}", l_size);
    for (int i = 0; i < l_size; i++) {
        log::info("[PACountTriggerAction - describe] m_remapKeys[{}]: {}", i, m_remapKeys[i]);
    }
}
#endif