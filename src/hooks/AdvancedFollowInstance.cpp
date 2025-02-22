#include "hooks/AdvancedFollowInstance.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAAdvancedFollowInstance::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAAdvancedFollowInstance::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAAdvancedFollowInstance& o_value) {
	i_stream >> o_value.m_gameObject;
	SEPARATOR_I
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_group;
		SEPARATOR_I
		i_stream >> o_value.m_objectKey;
		SEPARATOR_I
		i_stream >> o_value.m_controlId;
		SEPARATOR_I
		i_stream >> o_value.m_otherObjectKey;
		SEPARATOR_I
		i_stream >> o_value.m_relatedToGJGameStateUnkUint7;
		SEPARATOR_I
		i_stream >> o_value.m_finished;
		SEPARATOR_I
		i_stream >> o_value.m_doStart;
		SEPARATOR_I
		i_stream >> o_value.m_started;
		SEPARATOR_I
		i_stream >> o_value.m_processed;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAAdvancedFollowInstance,m_gameObject) + sizeof(GameObject*), 24);
	}
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAAdvancedFollowInstance& i_value) {
	o_stream << i_value.m_gameObject;
	SEPARATOR_O
	o_stream << i_value.m_group;
	SEPARATOR_O
	o_stream << i_value.m_objectKey;
	SEPARATOR_O
	o_stream << i_value.m_controlId;
	SEPARATOR_O
	o_stream << i_value.m_otherObjectKey;
	SEPARATOR_O
	o_stream << i_value.m_relatedToGJGameStateUnkUint7;
	SEPARATOR_O
	o_stream << i_value.m_finished;
	SEPARATOR_O
	o_stream << i_value.m_doStart;
	SEPARATOR_O
	o_stream << i_value.m_started;
	SEPARATOR_O
	o_stream << i_value.m_processed;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAAdvancedFollowInstance::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PAAdvancedFollowInstance - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
	log::info("[PAAdvancedFollowInstance - describe] m_group: {}", m_group);
	log::info("[PAAdvancedFollowInstance - describe] m_objectKey: {}", m_objectKey);
	log::info("[PAAdvancedFollowInstance - describe] m_controlId: {}", m_controlId);
	log::info("[PAAdvancedFollowInstance - describe] m_otherObjectKey: {}", m_otherObjectKey);
	log::info("[PAAdvancedFollowInstance - describe] m_relatedToGJGameStateUnkUint7: {}", m_relatedToGJGameStateUnkUint7);
	log::info("[PAAdvancedFollowInstance - describe] m_finished: {}", m_finished);
	log::info("[PAAdvancedFollowInstance - describe] m_doStart: {}", m_doStart);
	log::info("[PAAdvancedFollowInstance - describe] m_started: {}", m_started);
	log::info("[PAAdvancedFollowInstance - describe] m_processed: {}", m_processed);
	log::info("[PAAdvancedFollowInstance - describe] m_group: {}", m_group);
}
#endif