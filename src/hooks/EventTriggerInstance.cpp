#include "hooks/EventTriggerInstance.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAEventTriggerInstance::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAEventTriggerInstance::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAEventTriggerInstance& o_value) {
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_targetID;
		SEPARATOR_I
		i_stream >> o_value.m_uniqueID;
		SEPARATOR_I
		i_stream >> o_value.m_controlID;
		SEPARATOR_I
		i_stream >> o_value.m_inactive;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value), 16);
	}
	VEC_SEPARATOR_I
	i_stream >> o_value.m_remapKeys;
	VEC_SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAEventTriggerInstance& i_value) {
	o_stream << i_value.m_targetID;
	SEPARATOR_O
	o_stream << i_value.m_uniqueID;
	SEPARATOR_O
	o_stream << i_value.m_controlID;
	SEPARATOR_O
	o_stream << i_value.m_inactive;
	VEC_SEPARATOR_O
	o_stream << i_value.m_remapKeys;
	VEC_SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAEventTriggerInstance::describe() {
	log::info("[PAEventTriggerInstance - describe] m_targetID: {}", m_targetID);
	log::info("[PAEventTriggerInstance - describe] m_uniqueID: {}", m_uniqueID);
	log::info("[PAEventTriggerInstance - describe] m_controlID: {}", m_controlID);
	log::info("[PAEventTriggerInstance - describe] m_inactive: {}", m_inactive);
	int l_size = m_remapKeys.size();
	log::info("[PAEventTriggerInstance - describe] m_remapKeys.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEventTriggerInstance - describe] m_remapKeys[{}]: {}", i, m_remapKeys[i]);
	}
}
#endif