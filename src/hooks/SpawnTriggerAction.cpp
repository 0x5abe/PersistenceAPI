#include "hooks/SpawnTriggerAction.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASpawnTriggerAction::load(Stream& i_stream) {
	i_stream >> *this;
}

void PASpawnTriggerAction::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASpawnTriggerAction& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 40);
	SEPARATOR_I
	i_stream >> o_value.m_gameObject;
	VEC_SEPARATOR_I
	int l_size = o_value.m_unkVecInt.size();
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASpawnTriggerAction& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 40);
	SEPARATOR_O
	o_stream << i_value.m_gameObject;
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASpawnTriggerAction::describe() {
	log::info("[PASpawnTriggerAction - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 40));
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PASpawnTriggerAction - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
	int l_size = m_unkVecInt.size();
	log::info("[PASpawnTriggerAction - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PASpawnTriggerAction - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
}
#endif