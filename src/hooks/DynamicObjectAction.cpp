#include "hooks/DynamicObjectAction.hpp"
#include "Geode/binding/GameObject.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PADynamicObjectAction::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PADynamicObjectAction::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PADynamicObjectAction& o_value) {
	int l_objectIndex;

	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) {
		i_stream >> l_objectIndex;
		o_value.m_gameObject1 = l_playLayer->getGameObject(l_objectIndex);
		SEPARATOR_I
		i_stream >> l_objectIndex;
		o_value.m_gameObject2 = l_playLayer->getGameObject(l_objectIndex);
		SEPARATOR_I
		i_stream >> l_objectIndex;
		o_value.m_gameObject3 = l_playLayer->getGameObject(l_objectIndex);
		SEPARATOR_I
		i_stream >> l_objectIndex;
		o_value.m_gameObject4 = l_playLayer->getGameObject(l_objectIndex);
		SEPARATOR_I
		i_stream >> l_objectIndex;
		o_value.m_gameObject5 = l_playLayer->getGameObject(l_objectIndex);
		SEPARATOR_I
		i_stream >> l_objectIndex;
		o_value.m_gameObject6 = l_playLayer->getGameObject(l_objectIndex);
		SEPARATOR_I
		i_stream >> l_objectIndex;
		o_value.m_gameObject7 = l_playLayer->getGameObject(l_objectIndex);
		SEPARATOR_I
		i_stream >> l_objectIndex;
		o_value.m_gameObject8 = l_playLayer->getGameObject(l_objectIndex);
		SEPARATOR_I
	}
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PADynamicObjectAction,m_gameObject8) + sizeof(GameObject*), 32);
	SEPARATOR_I	
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PADynamicObjectAction& i_value) {
	int l_objectIndex = -1;

	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) {
		l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject1);
		log::info("object1Index: {}", l_objectIndex);
		o_stream << l_objectIndex;
		SEPARATOR_O
		l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject2);
		log::info("object2Index: {}", l_objectIndex);
		o_stream << l_objectIndex;
		SEPARATOR_O
	 	l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject3);
		log::info("object3 uniqueId: {}", i_value.m_gameObject3->m_uniqueID);
		log::info("object3Index: {}", l_objectIndex);
		o_stream << l_objectIndex;
		SEPARATOR_O
		l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject4);
		log::info("object4Index: {}", l_objectIndex);
		o_stream << l_objectIndex;
		SEPARATOR_O
		l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject5);
		log::info("object5Index: {}", l_objectIndex);
		o_stream << l_objectIndex;
		SEPARATOR_O
		l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject6);
		log::info("object6Index: {}", l_objectIndex);
		o_stream << l_objectIndex;
		SEPARATOR_O
		l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject7);
		log::info("object7Index: {}", l_objectIndex);
		o_stream << l_objectIndex;
		SEPARATOR_O
		l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject8);
		log::info("object8Index: {}", l_objectIndex);
		o_stream << l_objectIndex;
		SEPARATOR_O
	}
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
	log::info("[PAEnterEffectInstance - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PADynamicObjectAction,m_gameObject8) + sizeof(GameObject*), 32));
}
#endif