#include "hooks/TouchToggleAction.hpp"
#include "Geode/loader/Log.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PATouchToggleAction::load(Stream& i_stream) {
    i_stream >> *this;
}

void PATouchToggleAction::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PATouchToggleAction& o_value) {
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_disabled;
        SEPARATOR_I
        i_stream >> o_value.m_targetGroupID;
        SEPARATOR_I
        i_stream >> o_value.m_holdMode;
        SEPARATOR_I
        i_stream >> o_value.m_touchTriggerType;
        SEPARATOR_I
        i_stream >> o_value.m_touchTriggerControl;
        SEPARATOR_I
        i_stream >> o_value.m_triggerUniqueID;
        SEPARATOR_I
        i_stream >> o_value.m_controlID;
        SEPARATOR_I
        i_stream >> o_value.m_dualMode;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value), 32);
    }
    VEC_SEPARATOR_I
    i_stream >> o_value.m_remapKeys;
    VEC_SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PATouchToggleAction& i_value) {
    o_stream << i_value.m_disabled;
    SEPARATOR_O
    o_stream << i_value.m_targetGroupID;
    SEPARATOR_O
    o_stream << i_value.m_holdMode;
    SEPARATOR_O
    o_stream << i_value.m_touchTriggerType;
    SEPARATOR_O
    o_stream << i_value.m_touchTriggerControl;
    SEPARATOR_O
    o_stream << i_value.m_triggerUniqueID;
    SEPARATOR_O
    o_stream << i_value.m_controlID;
    SEPARATOR_O
    o_stream << i_value.m_dualMode;
    VEC_SEPARATOR_O
    o_stream << i_value.m_remapKeys;
    VEC_SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PATouchToggleAction::describe() {
    log::info("[PATouchToggleAction - describe] m_disabled: {}", m_disabled);
    log::info("[PATouchToggleAction - describe] m_targetGroupID: {}", m_targetGroupID);
    log::info("[PATouchToggleAction - describe] m_holdMode: {}", m_holdMode);
    log::info("[PATouchToggleAction - describe] m_touchTriggerType: {}", *reinterpret_cast<int*>(&m_touchTriggerType));
    log::info("[PATouchToggleAction - describe] m_touchTriggerControl: {}", *reinterpret_cast<int*>(&m_touchTriggerControl));
    log::info("[PATouchToggleAction - describe] m_triggerUniqueID: {}", m_triggerUniqueID);
    log::info("[PATouchToggleAction - describe] m_controlID: {}", m_controlID);
    log::info("[PATouchToggleAction - describe] m_dualMode: {}", m_dualMode);
    int l_size = m_remapKeys.size();
    log::info("[PATouchToggleAction - describe] m_remapKeys.size(): {}", l_size);
    for (int i = 0; i < l_size; i++) {
        log::info("[PATouchToggleAction - describe] m_remapKeys[{}]: {}", i, m_remapKeys[i]);
    }
}
#endif