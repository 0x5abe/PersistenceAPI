#include "hooks/SongChannelState.hpp"
#include "Geode/binding/SongTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASongChannelState::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PASongChannelState::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PASongChannelState& o_value) {
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_songTriggerGameObject1 = static_cast<SongTriggerGameObject*>(l_playLayer->getGameObject(l_objectIndex));
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PASongChannelState,m_songTriggerGameObject1) + sizeof(SongTriggerGameObject*), 8);
	SEPARATOR_I
	i_stream >> l_objectIndex;
	if (l_playLayer) o_value.m_songTriggerGameObject2 = static_cast<SongTriggerGameObject*>(l_playLayer->getGameObject(l_objectIndex));
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PASongChannelState,m_songTriggerGameObject2) + sizeof(SongTriggerGameObject*), 8);
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PASongChannelState& i_value) {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_songTriggerGameObject1);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PASongChannelState,m_songTriggerGameObject1) + sizeof(SongTriggerGameObject*), 8);
	SEPARATOR_O
	l_objectIndex = -1;
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_songTriggerGameObject2);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PASongChannelState,m_songTriggerGameObject2) + sizeof(SongTriggerGameObject*), 8);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PASongChannelState::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_songTriggerGameObject1);
	log::info("[PASongChannelState - describe] m_songTriggerGameObject1 l_objectIndex: {}", l_objectIndex);
	log::info("[PASongChannelState - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PASongChannelState,m_songTriggerGameObject1) + sizeof(SongTriggerGameObject*), 8));
	l_objectIndex = -1;
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_songTriggerGameObject2);
	log::info("[PASongChannelState - describe] m_songTriggerGameObject2 l_objectIndex: {}", l_objectIndex);
	log::info("[PASongChannelState - describe] pad_2: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PASongChannelState,m_songTriggerGameObject2) + sizeof(SongTriggerGameObject*), 8));
}
#endif