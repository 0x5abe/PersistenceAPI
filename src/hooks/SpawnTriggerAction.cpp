#include "hooks/SpawnTriggerAction.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistencyUtils;

void PUSpawnTriggerAction::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUSpawnTriggerAction::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistencyUtils::operator>>(InputStream& i_stream, PUSpawnTriggerAction& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 40);
	SEPARATOR_I
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PlayLayer* l_playLayer = PlayLayer::get();
	if (l_playLayer && l_objectIndex != -1) {
		o_value.m_gameObject = static_cast<GameObject*>(l_playLayer->m_objects->objectAtIndex(l_objectIndex));
	} else {
		o_value.m_gameObject = nullptr;
	}
	VEC_SEPARATOR_I
	int l_size = o_value.m_unkVecInt.size();
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
}

inline void persistencyUtils::operator<<(OutputStream& o_stream, PUSpawnTriggerAction& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 40);
	SEPARATOR_O
	int l_objectIndex = -1;
	if (i_value.m_gameObject) {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject);
	}
	o_stream << l_objectIndex;
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUSpawnTriggerAction::describe() {
	log::info("[PUSpawnTriggerAction - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 40));
	int l_objectIndex = -1;
	if (m_gameObject) {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	}
	log::info("[PUSpawnTriggerAction - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
	int l_size = m_unkVecInt.size();
	log::info("[PUSpawnTriggerAction - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PUSpawnTriggerAction - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
}
#endif