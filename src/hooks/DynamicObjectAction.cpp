#include "hooks/DynamicObjectAction.hpp"
#include "Geode/binding/GameObject.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistencyUtils;

void PUDynamicObjectAction::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUDynamicObjectAction::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistencyUtils::operator>>(InputStream& i_stream, PUDynamicObjectAction& o_value) {
	int l_object1Index;
	int l_object2Index;
	int l_object3Index;
	int l_object4Index;
	int l_object5Index;
	int l_object6Index;
	int l_object7Index;
	int l_object8Index;
	i_stream >> l_object1Index;
	SEPARATOR_I
	i_stream >> l_object2Index;
	SEPARATOR_I
	i_stream >> l_object3Index;
	SEPARATOR_I
	i_stream >> l_object4Index;
	SEPARATOR_I
	i_stream >> l_object5Index;
	SEPARATOR_I
	i_stream >> l_object6Index;
	SEPARATOR_I
	i_stream >> l_object7Index;
	SEPARATOR_I
	i_stream >> l_object8Index;
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUDynamicObjectAction,m_gameObject8) + sizeof(GameObject*), 32);
	SEPARATOR_I

	// get the pointer to the gameObject

	PlayLayer* l_playLayer = PlayLayer::get();
	if (l_playLayer && l_object1Index != -1) {
		o_value.m_gameObject1 = static_cast<GameObject*>(l_playLayer->m_objects->objectAtIndex(l_object1Index));
	} else {
		o_value.m_gameObject1 = nullptr;
	}
	if (l_playLayer && l_object2Index != -1) {
		o_value.m_gameObject2 = static_cast<GameObject*>(l_playLayer->m_objects->objectAtIndex(l_object2Index));
	} else {
		o_value.m_gameObject2 = nullptr;
	}
	if (l_playLayer && l_object3Index != -1) {
		o_value.m_gameObject3 = static_cast<GameObject*>(l_playLayer->m_objects->objectAtIndex(l_object3Index));
	} else {
		o_value.m_gameObject3 = nullptr;
	}
	if (l_playLayer && l_object4Index != -1) {
		o_value.m_gameObject4 = static_cast<GameObject*>(l_playLayer->m_objects->objectAtIndex(l_object4Index));
	} else {
		o_value.m_gameObject4 = nullptr;
	}
	if (l_playLayer && l_object5Index != -1) {
		o_value.m_gameObject5 = static_cast<GameObject*>(l_playLayer->m_objects->objectAtIndex(l_object5Index));
	} else {
		o_value.m_gameObject5 = nullptr;
	}
	if (l_playLayer && l_object6Index != -1) {
		o_value.m_gameObject6 = static_cast<GameObject*>(l_playLayer->m_objects->objectAtIndex(l_object6Index));
	} else {
		o_value.m_gameObject6 = nullptr;
	}
	if (l_playLayer && l_object7Index != -1) {
		o_value.m_gameObject7 = static_cast<GameObject*>(l_playLayer->m_objects->objectAtIndex(l_object7Index));
	} else {
		o_value.m_gameObject7 = nullptr;
	}
	if (l_playLayer && l_object8Index != -1) {
		o_value.m_gameObject8 = static_cast<GameObject*>(l_playLayer->m_objects->objectAtIndex(l_object8Index));
	} else {
		o_value.m_gameObject8 = nullptr;
	}
}

inline void persistencyUtils::operator<<(OutputStream& o_stream, PUDynamicObjectAction& i_value) {
	int l_object1Index = -1;
	int l_object2Index = -1;
	int l_object3Index = -1;
	int l_object4Index = -1;
	int l_object5Index = -1;
	int l_object6Index = -1;
	int l_object7Index = -1;
	int l_object8Index = -1;
	if (!i_value.m_gameObject1) {
		//log::info("no game object??");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object1Index = l_playLayer->getGameObjectIndex(i_value.m_gameObject1);
		log::info("object1Index: {}", l_object1Index);
	}
	if (!i_value.m_gameObject2) {
		//log::info("no game object??");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object2Index = l_playLayer->getGameObjectIndex(i_value.m_gameObject2);
		log::info("object2Index: {}", l_object2Index);
	}
	if (!i_value.m_gameObject3) {
		//log::info("no game object??");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object3Index = l_playLayer->getGameObjectIndex(i_value.m_gameObject3);
		log::info("object3 uniqueId: {}", i_value.m_gameObject3->m_uniqueID);
		log::info("object3Index: {}", l_object3Index);
	}
	if (!i_value.m_gameObject4) {
		//log::info("no game object??");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object4Index = l_playLayer->getGameObjectIndex(i_value.m_gameObject4);
		log::info("object4Index: {}", l_object4Index);
	}
	if (!i_value.m_gameObject5) {
		//log::info("no game object??");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object5Index = l_playLayer->getGameObjectIndex(i_value.m_gameObject5);
		log::info("object5Index: {}", l_object5Index);
	}
	if (!i_value.m_gameObject6) {
		//log::info("no game object??");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object6Index = l_playLayer->getGameObjectIndex(i_value.m_gameObject6);
		log::info("object6Index: {}", l_object6Index);
	}
	if (!i_value.m_gameObject7) {
		//log::info("no game object??");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object7Index = l_playLayer->getGameObjectIndex(i_value.m_gameObject7);
		log::info("object7Index: {}", l_object7Index);
	}
	if (!i_value.m_gameObject8) {
		//log::info("no game object??");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object8Index = l_playLayer->getGameObjectIndex(i_value.m_gameObject8);
		log::info("object8Index: {}", l_object8Index);
	}
	o_stream << l_object1Index;
	SEPARATOR_O
	o_stream << l_object2Index;
	SEPARATOR_O
	o_stream << l_object3Index;
	SEPARATOR_O
	o_stream << l_object4Index;
	SEPARATOR_O
	o_stream << l_object5Index;
	SEPARATOR_O
	o_stream << l_object6Index;
	SEPARATOR_O
	o_stream << l_object7Index;
	SEPARATOR_O
	o_stream << l_object8Index;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUDynamicObjectAction,m_gameObject8) + sizeof(GameObject*), 32);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUDynamicObjectAction::describe() {
	int l_object1Index = -1;
	if (!m_gameObject1) {
		log::info("[PUDynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object1Index = l_playLayer->getGameObjectIndex(m_gameObject1);
	}
	if (!m_gameObject2) {
		log::info("[PUDynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object2Index = l_playLayer->getGameObjectIndex(m_gameObject2);
	}
	if (!m_gameObject3) {
		log::info("[PUDynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object3Index = l_playLayer->getGameObjectIndex(m_gameObject3);
	}
	if (!m_gameObject4) {
		log::info("[PUDynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object4Index = l_playLayer->getGameObjectIndex(m_gameObject4);
	}
	if (!m_gameObject5) {
		log::info("[PUDynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object5Index = l_playLayer->getGameObjectIndex(m_gameObject5);
	}
	if (!m_gameObject6) {
		log::info("[PUDynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object6Index = l_playLayer->getGameObjectIndex(m_gameObject6);
	}
	if (!m_gameObject7) {
		log::info("[PUDynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object7Index = l_playLayer->getGameObjectIndex(m_gameObject7);
	}
	if (!m_gameObject8) {
		log::info("[PUDynamicObjectAction - describe] no game object?? @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	} else {
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_object8Index = l_playLayer->getGameObjectIndex(m_gameObject8);
	}
	
	log::info("[PUDynamicObjectAction - describe] l_object1Index: {}", l_object1Index);
	log::info("[PUDynamicObjectAction - describe] l_object2Index: {}", l_object2Index);
	log::info("[PUDynamicObjectAction - describe] l_object3Index: {}", l_object3Index);
	log::info("[PUDynamicObjectAction - describe] l_object4Index: {}", l_object4Index);
	log::info("[PUDynamicObjectAction - describe] l_object5Index: {}", l_object5Index);
	log::info("[PUDynamicObjectAction - describe] l_object6Index: {}", l_object6Index);
	log::info("[PUDynamicObjectAction - describe] l_object7Index: {}", l_object7Index);
	log::info("[PUDynamicObjectAction - describe] l_object8Index: {}", l_object8Index);
	log::info("[PUEnterEffectInstance - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUDynamicObjectAction,m_gameObject8) + sizeof(GameObject*), 32));
}
#endif