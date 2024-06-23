#include "hooks/SongTriggerState.hpp"
#include "Geode/binding/SongTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASongTriggerState::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PASongTriggerState::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PASongTriggerState& o_value) {
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_songTriggerGameObject = static_cast<SongTriggerGameObject*>(l_playLayer->getGameObject(l_objectIndex));
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PASongTriggerState,m_songTriggerGameObject) + sizeof(SongTriggerGameObject*), 8);
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PASongTriggerState& i_value) {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_songTriggerGameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PASongTriggerState,m_songTriggerGameObject) + sizeof(SongTriggerGameObject*), 8);
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASongTriggerState::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_songTriggerGameObject);
	log::info("[PASongTriggerState - describe] m_songTriggerGameObject l_objectIndex: {}", l_objectIndex);
	log::info("[PASongTriggerState - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PASongTriggerState,m_songTriggerGameObject) + sizeof(SongTriggerGameObject*), 8));
}
#endif