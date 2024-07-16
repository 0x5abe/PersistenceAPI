#include "hooks/DynamicObjectAction.hpp"
#include "Geode/binding/GameObject.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PADynamicObjectAction::load(Stream& i_stream) {
	i_stream >> *this;
}

void PADynamicObjectAction::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PADynamicObjectAction& o_value) {
	i_stream >> o_value.m_gameObject1;
	SEPARATOR_I
	i_stream >> o_value.m_gameObject2;
	SEPARATOR_I
	i_stream >> o_value.m_gameObject3;
	SEPARATOR_I
	i_stream >> o_value.m_gameObject4;
	SEPARATOR_I
	i_stream >> o_value.m_gameObject5;
	SEPARATOR_I
	i_stream >> o_value.m_gameObject6;
	SEPARATOR_I
	i_stream >> o_value.m_gameObject7;
	SEPARATOR_I
	i_stream >> o_value.m_gameObject8;
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PADynamicObjectAction,m_gameObject8) + sizeof(GameObject*), 32);
	SEPARATOR_I	
}

inline void persistenceAPI::operator<<(Stream& o_stream, PADynamicObjectAction& i_value) {
	o_stream << i_value.m_gameObject1;
	SEPARATOR_O
	o_stream << i_value.m_gameObject2;
	SEPARATOR_O
	o_stream << i_value.m_gameObject3;
	SEPARATOR_O
	o_stream << i_value.m_gameObject4;
	SEPARATOR_O
	o_stream << i_value.m_gameObject5;
	SEPARATOR_O
	o_stream << i_value.m_gameObject6;
	SEPARATOR_O
	o_stream << i_value.m_gameObject7;
	SEPARATOR_O
	o_stream << i_value.m_gameObject8;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PADynamicObjectAction,m_gameObject8) + sizeof(GameObject*), 32);
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PADynamicObjectAction::describe() {
	int l_object1Index = -1;
	if (!m_gameObject1) {
		log::info("[PADynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object1Index = l_playLayer->getGameObjectIndex(m_gameObject1);
	}
	if (!m_gameObject2) {
		log::info("[PADynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object2Index = l_playLayer->getGameObjectIndex(m_gameObject2);
	}
	if (!m_gameObject3) {
		log::info("[PADynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object3Index = l_playLayer->getGameObjectIndex(m_gameObject3);
	}
	if (!m_gameObject4) {
		log::info("[PADynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object4Index = l_playLayer->getGameObjectIndex(m_gameObject4);
	}
	if (!m_gameObject5) {
		log::info("[PADynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object5Index = l_playLayer->getGameObjectIndex(m_gameObject5);
	}
	if (!m_gameObject6) {
		log::info("[PADynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object6Index = l_playLayer->getGameObjectIndex(m_gameObject6);
	}
	if (!m_gameObject7) {
		log::info("[PADynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object7Index = l_playLayer->getGameObjectIndex(m_gameObject7);
	}
	if (!m_gameObject8) {
		log::info("[PADynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object8Index = l_playLayer->getGameObjectIndex(m_gameObject8);
	}
	
	log::info("[PADynamicObjectAction - describe] l_object1Index: {}", l_object1Index);
	log::info("[PADynamicObjectAction - describe] l_object2Index: {}", l_object2Index);
	log::info("[PADynamicObjectAction - describe] l_object3Index: {}", l_object3Index);
	log::info("[PADynamicObjectAction - describe] l_object4Index: {}", l_object4Index);
	log::info("[PADynamicObjectAction - describe] l_object5Index: {}", l_object5Index);
	log::info("[PADynamicObjectAction - describe] l_object6Index: {}", l_object6Index);
	log::info("[PADynamicObjectAction - describe] l_object7Index: {}", l_object7Index);
	log::info("[PADynamicObjectAction - describe] l_object8Index: {}", l_object8Index);
	log::info("[PADynamicObjectAction - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PADynamicObjectAction,m_gameObject8) + sizeof(GameObject*), 32));
}
#endif