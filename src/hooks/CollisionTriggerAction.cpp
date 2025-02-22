#include "hooks/CollisionTriggerAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PACollisionTriggerAction::load(Stream& i_stream) {
	i_stream >> *this;
}

void PACollisionTriggerAction::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PACollisionTriggerAction& o_value) {
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_disabled;
		SEPARATOR_I
    	i_stream >> o_value.m_blockAID;
		SEPARATOR_I
    	i_stream >> o_value.m_blockBID;
		SEPARATOR_I
    	i_stream >> o_value.m_targetGroupID;
		SEPARATOR_I
    	i_stream >> o_value.m_triggerOnExit;
		SEPARATOR_I
    	i_stream >> o_value.m_activateGroup;
		SEPARATOR_I
    	i_stream >> o_value.m_triggerUniqueID;
		SEPARATOR_I
    	i_stream >> o_value.m_controlID;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value), 32);
	}
	VEC_SEPARATOR_I
	i_stream >> o_value.m_remapKeys;
	VEC_SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PACollisionTriggerAction& i_value) {
	o_stream << i_value.m_disabled;
	SEPARATOR_O
    o_stream << i_value.m_blockAID;
	SEPARATOR_O
    o_stream << i_value.m_blockBID;
	SEPARATOR_O
    o_stream << i_value.m_targetGroupID;
	SEPARATOR_O
    o_stream << i_value.m_triggerOnExit;
	SEPARATOR_O
    o_stream << i_value.m_activateGroup;
	SEPARATOR_O
    o_stream << i_value.m_triggerUniqueID;
	SEPARATOR_O
    o_stream << i_value.m_controlID;
	VEC_SEPARATOR_O
	o_stream << i_value.m_remapKeys;
	VEC_SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PACollisionTriggerAction::describe() {
	log::info("[PACollisionTriggerAction - describe] m_disabled: {}", m_disabled);
	log::info("[PACollisionTriggerAction - describe] m_blockAID: {}", m_blockAID);
	log::info("[PACollisionTriggerAction - describe] m_disabled: {}", m_blockBID);
	log::info("[PACollisionTriggerAction - describe] m_disabled: {}", m_targetGroupID);
	log::info("[PACollisionTriggerAction - describe] m_disabled: {}", m_triggerOnExit);
	log::info("[PACollisionTriggerAction - describe] m_disabled: {}", m_activateGroup);
	log::info("[PACollisionTriggerAction - describe] m_disabled: {}", m_triggerUniqueID);
	log::info("[PACollisionTriggerAction - describe] m_disabled: {}", m_controlID);
	int l_size = m_remapKeys.size();
	log::info("[PACollisionTriggerAction - describe] m_remapKeys.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PACollisionTriggerAction - describe] m_remapKeys[{}]: {}", i, m_remapKeys[i]);
	}
}
#endif