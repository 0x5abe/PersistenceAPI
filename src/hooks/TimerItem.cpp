#include "hooks/TimerItem.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PATimerItem::load(Stream& i_stream) {
    i_stream >> *this;
}

void PATimerItem::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PATimerItem& o_value) {
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_itemID;
        SEPARATOR_I
        i_stream >> o_value.m_time;
        SEPARATOR_I
        i_stream >> o_value.m_active;
        SEPARATOR_I
        i_stream >> o_value.m_timeMod;
        SEPARATOR_I
        i_stream >> o_value.m_ignoreTimeWarp;
        SEPARATOR_I
        i_stream >> o_value.m_targetTime;
        SEPARATOR_I
        i_stream >> o_value.m_stopTimeEnabled;
        SEPARATOR_I
        i_stream >> o_value.m_targetGroupID;
        SEPARATOR_I
        i_stream >> o_value.m_triggerUniqueID;
        SEPARATOR_I
        i_stream >> o_value.m_controlID;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value), 56);
    }
    VEC_SEPARATOR_I
    i_stream >> o_value.m_remapKeys;
    VEC_SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_disabled;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PATimerItem,m_remapKeys) + sizeof(gd::vector<int>), 4);
    }
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PATimerItem& i_value) {
    o_stream << i_value.m_itemID;
    SEPARATOR_O
    o_stream << i_value.m_time;
    SEPARATOR_O
    o_stream << i_value.m_active;
    SEPARATOR_O
    o_stream << i_value.m_timeMod;
    SEPARATOR_O
    o_stream << i_value.m_ignoreTimeWarp;
    SEPARATOR_O
    o_stream << i_value.m_targetTime;
    SEPARATOR_O
    o_stream << i_value.m_stopTimeEnabled;
    SEPARATOR_O
    o_stream << i_value.m_targetGroupID;
    SEPARATOR_O
    o_stream << i_value.m_triggerUniqueID;
    SEPARATOR_O
    o_stream << i_value.m_controlID;
    VEC_SEPARATOR_O
    o_stream << i_value.m_remapKeys;
    VEC_SEPARATOR_O
    o_stream << i_value.m_disabled;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PATimerItem::describe() {
    log::info("[PATimerItem - describe] m_itemID: {}", m_itemID);
    log::info("[PATimerItem - describe] m_time: {}", m_time);
    log::info("[PATimerItem - describe] m_active: {}", m_active);
    log::info("[PATimerItem - describe] m_timeMod: {}", m_timeMod);
    log::info("[PATimerItem - describe] m_ignoreTimeWarp: {}", m_ignoreTimeWarp);
    log::info("[PATimerItem - describe] m_targetTime: {}", m_targetTime);
    log::info("[PATimerItem - describe] m_stopTimeEnabled: {}", m_stopTimeEnabled);
    log::info("[PATimerItem - describe] m_targetGroupID: {}", m_targetGroupID);
    log::info("[PATimerItem - describe] m_triggerUniqueID: {}", m_triggerUniqueID);
    log::info("[PATimerItem - describe] m_controlID: {}", m_controlID);
    int l_size = m_remapKeys.size();
    log::info("[PATimerItem - describe] m_remapKeys.size(): {}", l_size);
    for (int i = 0; i < l_size; i++) {
        log::info("[PATimerItem - describe] m_remapKeys[{}]: {}", i, m_remapKeys[i]);
    }
    log::info("[PATimerItem - describe] m_disabled: {}", m_disabled);
}
#endif