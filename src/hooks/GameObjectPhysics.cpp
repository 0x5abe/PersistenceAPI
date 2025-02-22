#include "hooks/GameObjectPhysics.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAGameObjectPhysics::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAGameObjectPhysics::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAGameObjectPhysics& o_value) {
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_gameObject;
		SEPARATOR_I
		i_stream >> o_value.m_unkPoint1;
		SEPARATOR_I
		i_stream >> o_value.m_unkPoint2;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat1;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat2;
		SEPARATOR_I
		i_stream >> o_value.m_unkInt1;
		SEPARATOR_I
		i_stream >> o_value.m_unkInt2;
		SEPARATOR_I
		i_stream >> o_value.m_unkInt3;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value), 40);
	}
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAGameObjectPhysics& i_value) {
	o_stream << i_value.m_gameObject;
	SEPARATOR_O
	o_stream << i_value.m_unkPoint1;
	SEPARATOR_O
	o_stream << i_value.m_unkPoint2;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat1;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat2;
	SEPARATOR_O
	o_stream << i_value.m_unkInt1;
	SEPARATOR_O
	o_stream << i_value.m_unkInt2;
	SEPARATOR_O
	o_stream << i_value.m_unkInt3;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAGameObjectPhysics::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PAGameObjectPhysics - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
	log::info("[PAGameObjectPhysics - describe] m_unkPoint1: {}", m_unkPoint1);
	log::info("[PAGameObjectPhysics - describe] m_unkPoint2: {}", m_unkPoint2);
	log::info("[PAGameObjectPhysics - describe] m_unkFloat1: {}", m_unkFloat1);
	log::info("[PAGameObjectPhysics - describe] m_unkFloat2: {}", m_unkFloat2);
	log::info("[PAGameObjectPhysics - describe] m_unkInt1: {}", m_unkInt1);
	log::info("[PAGameObjectPhysics - describe] m_unkInt2: {}", m_unkInt2);
	log::info("[PAGameObjectPhysics - describe] m_unkInt3: {}", m_unkInt3);
}
#endif