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
	if (i_stream.getFileVersion() > 9) {
		i_stream >> o_value.m_finished;
		SEPARATOR_I
		i_stream >> o_value.m_disabled;
		SEPARATOR_I
		i_stream >> o_value.m_duration;
		SEPARATOR_I
		i_stream >> o_value.m_deltaTime;
		SEPARATOR_I
		i_stream >> o_value.m_targetGroupID;
		SEPARATOR_I
		i_stream >> o_value.m_triggerUniqueID;
		SEPARATOR_I
		i_stream >> o_value.m_controlID;
		SEPARATOR_I
		i_stream >> o_value.m_spawnOrdered;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value), 40);
	}
	SEPARATOR_I
	i_stream >> o_value.m_gameObject;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_remapKeys;
	VEC_SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASpawnTriggerAction& i_value) {
	o_stream << i_value.m_finished;
	SEPARATOR_O
	o_stream << i_value.m_disabled;
	SEPARATOR_O
	o_stream << i_value.m_duration;
	SEPARATOR_O
	o_stream << i_value.m_deltaTime;
	SEPARATOR_O
	o_stream << i_value.m_targetGroupID;
	SEPARATOR_O
	o_stream << i_value.m_triggerUniqueID;
	SEPARATOR_O
	o_stream << i_value.m_controlID;
	SEPARATOR_O
	o_stream << i_value.m_spawnOrdered;
	SEPARATOR_O
	o_stream << i_value.m_gameObject;
	VEC_SEPARATOR_O
	o_stream << i_value.m_remapKeys;
	VEC_SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASpawnTriggerAction::describe() {
	log::info("[PASpawnTriggerAction - describe] m_finished: {}", m_finished);
	log::info("[PASpawnTriggerAction - describe] m_disabled: {}", m_disabled);
	log::info("[PASpawnTriggerAction - describe] m_duration: {}", m_duration);
	log::info("[PASpawnTriggerAction - describe] m_deltaTime: {}", m_deltaTime);
	log::info("[PASpawnTriggerAction - describe] m_targetGroupID: {}", m_targetGroupID);
	log::info("[PASpawnTriggerAction - describe] m_triggerUniqueID: {}", m_triggerUniqueID);
	log::info("[PASpawnTriggerAction - describe] m_controlID: {}", m_controlID);
	log::info("[PASpawnTriggerAction - describe] m_spawnOrdered: {}", m_spawnOrdered);
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PASpawnTriggerAction - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
	int l_size = m_remapKeys.size();
	log::info("[PASpawnTriggerAction - describe] m_remapKeys.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PASpawnTriggerAction - describe] m_remapKeys[{}]: {}", i, m_remapKeys[i]);
	}
}
#endif