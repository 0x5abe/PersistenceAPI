#include "hooks/OpacityEffectAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAOpacityEffectAction::load(Stream& i_stream) {
    i_stream >> *this;
}

void PAOpacityEffectAction::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAOpacityEffectAction& o_value) {
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_duration;
        SEPARATOR_I;
        i_stream >> o_value.m_fromValue;
        SEPARATOR_I;
        i_stream >> o_value.m_toValue;
        SEPARATOR_I;
        i_stream >> o_value.m_finished;
        SEPARATOR_I;
        i_stream >> o_value.m_disabled;
        SEPARATOR_I;
        i_stream >> o_value.m_deltaTime;
        SEPARATOR_I;
        i_stream >> o_value.m_targetGroupID;
        SEPARATOR_I;
        i_stream >> o_value.m_currentValue;
        SEPARATOR_I;
        i_stream >> o_value.m_triggerUniqueID;
        SEPARATOR_I;
        i_stream >> o_value.m_controlID;
        SEPARATOR_I;
        i_stream >> o_value.m_deltaTimeRelated;
        SEPARATOR_I;
        i_stream >> o_value.m_durationRelated;
        SEPARATOR_I;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value), sizeof(OpacityEffectAction));
    }
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAOpacityEffectAction& i_value) {
    o_stream << i_value.m_duration;
    SEPARATOR_O;
    o_stream << i_value.m_fromValue;
    SEPARATOR_O;
    o_stream << i_value.m_toValue;
    SEPARATOR_O;
    o_stream << i_value.m_finished;
    SEPARATOR_O;
    o_stream << i_value.m_disabled;
    SEPARATOR_O;
    o_stream << i_value.m_deltaTime;
    SEPARATOR_O;
    o_stream << i_value.m_targetGroupID;
    SEPARATOR_O;
    o_stream << i_value.m_currentValue;
    SEPARATOR_O;
    o_stream << i_value.m_triggerUniqueID;
    SEPARATOR_O;
    o_stream << i_value.m_controlID;
    SEPARATOR_O;
    o_stream << i_value.m_deltaTimeRelated;
    SEPARATOR_O;
    o_stream << i_value.m_durationRelated;
    SEPARATOR_O;
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAOpacityEffectAction::describe() {
    log::info("[PAOpacityEffectAction - describe] m_duration: {}", m_duration);
    log::info("[PAOpacityEffectAction - describe] m_fromValue: {}", m_fromValue);
    log::info("[PAOpacityEffectAction - describe] m_toValue: {}", m_toValue);
    log::info("[PAOpacityEffectAction - describe] m_finished: {}", m_finished);
    log::info("[PAOpacityEffectAction - describe] m_disabled: {}", m_disabled);
    log::info("[PAOpacityEffectAction - describe] m_deltaTime: {}", m_deltaTime);
    log::info("[PAOpacityEffectAction - describe] m_targetGroupID: {}", m_targetGroupID);
    log::info("[PAOpacityEffectAction - describe] m_currentValue: {}", m_currentValue);
    log::info("[PAOpacityEffectAction - describe] m_triggerUniqueID: {}", m_triggerUniqueID);
    log::info("[PAOpacityEffectAction - describe] m_controlID: {}", m_controlID);
    log::info("[PAOpacityEffectAction - describe] m_deltaTimeRelated: {}", m_deltaTimeRelated);
    log::info("[PAOpacityEffectAction - describe] m_durationRelated: {}", m_durationRelated);
}
#endif