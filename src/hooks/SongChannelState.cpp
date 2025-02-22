#include "hooks/SongChannelState.hpp"
#include "Geode/binding/SongTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASongChannelState::load(Stream& i_stream) {
	i_stream >> *this;
}

void PASongChannelState::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASongChannelState& o_value) {
	int l_objectIndex;
	i_stream >> o_value.m_songTriggerGameObject1;
	SEPARATOR_I
	i_stream >> o_value.m_unkDouble1;
	SEPARATOR_I
	i_stream >> o_value.m_songTriggerGameObject2;
	SEPARATOR_I
	i_stream >> o_value.m_unkDouble2;
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASongChannelState& i_value) {
	int l_objectIndex = -1;
	o_stream << i_value.m_songTriggerGameObject1;
	SEPARATOR_O
	o_stream << i_value.m_unkDouble1;
	SEPARATOR_O
	o_stream << i_value.m_songTriggerGameObject2;
	SEPARATOR_O
	o_stream << i_value.m_unkDouble2;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASongChannelState::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_songTriggerGameObject1);
	log::info("[PASongChannelState - describe] m_songTriggerGameObject1 l_objectIndex: {}", l_objectIndex);
	log::info("[PASongChannelState - describe] m_unkDouble1: {}", m_unkDouble1);
	l_objectIndex = -1;
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_songTriggerGameObject2);
	log::info("[PASongChannelState - describe] m_songTriggerGameObject2 l_objectIndex: {}", l_objectIndex);
	log::info("[PASongChannelState - describe] m_unkDouble2: {}", m_unkDouble2);
}
#endif