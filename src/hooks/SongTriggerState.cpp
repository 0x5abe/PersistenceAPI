#include "hooks/SongTriggerState.hpp"
#include "Geode/binding/SongTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASongTriggerState::load(Stream& i_stream) {
    i_stream >> *this;
}

void PASongTriggerState::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASongTriggerState& o_value) {
    i_stream >> o_value.m_songTriggerGameObject;
    SEPARATOR_I
    i_stream >> o_value.m_unkDouble;
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASongTriggerState& i_value) {
    o_stream << i_value.m_songTriggerGameObject;
    SEPARATOR_O
    o_stream << i_value.m_unkDouble;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASongTriggerState::describe() {
    int l_objectIndex = -1;
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_songTriggerGameObject);
    log::info("[PASongTriggerState - describe] m_songTriggerGameObject l_objectIndex: {}", l_objectIndex);
    log::info("[PASongTriggerState - describe] m_unkDouble: {}", m_unkDouble);
}
#endif