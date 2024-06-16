#include "hooks/SongTriggerState.hpp"
#include "Geode/binding/SongTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

void PUSongTriggerState::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUSongTriggerState::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceUtils::operator>>(InputStream& i_stream, PUSongTriggerState& o_value) {
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_songTriggerGameObject = static_cast<SongTriggerGameObject*>(l_playLayer->getGameObject(l_objectIndex));
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUSongTriggerState,m_songTriggerGameObject) + sizeof(SongTriggerGameObject*), 8);
	SEPARATOR_I
}

inline void persistenceUtils::operator<<(OutputStream& o_stream, PUSongTriggerState& i_value) {
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_songTriggerGameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUSongTriggerState,m_songTriggerGameObject) + sizeof(SongTriggerGameObject*), 8);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUSongTriggerState::describe() {
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_songTriggerGameObject);
	log::info("[PUSongTriggerState - describe] m_songTriggerGameObject l_objectIndex: {}", l_objectIndex);
	log::info("[PUSongTriggerState - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUSongTriggerState,m_songTriggerGameObject) + sizeof(SongTriggerGameObject*), 8));
}
#endif