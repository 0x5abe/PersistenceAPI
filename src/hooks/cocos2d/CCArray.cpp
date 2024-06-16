#include "hooks/cocos2d/CCArray.hpp"
#include "hooks/cocos2d/CCObject.hpp"
#include "hooks/PlayLayer.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

template <class T>
void PUCCArray::load(InputStream& i_stream) {
	removeAllObjects();
	unsigned int l_size;
	i_stream >> l_size;
	T* l_objects = reinterpret_cast<T*>(malloc(l_size*sizeof(T)));
	//geode::log::info("CCARRAY SIZE in: {}", l_size);
	for (int i = 0; i < l_size; i++) {
		reinterpret_cast<T*>(l_objects)->load(i_stream); 
		addObject(l_objects);
		l_objects++;
	}
}

template <class T>
void PUCCArray::save(OutputStream& o_stream) {
	unsigned int l_size = count();
	o_stream << l_size;
	//geode::log::info("CCARRAY SIZE out: {}", l_size);
	for (int i = 0; i < l_size; i++) {
	   reinterpret_cast<T*>(objectAtIndex(i))->save(o_stream); 
	}
}

template <>
void PUCCArray::load<GradientTriggerObject>(InputStream& i_stream) {
	removeAllObjects();
	unsigned int l_size;
	i_stream >> l_size;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	//geode::log::info("CCARRAY GradientTriggerObject SIZE in: {}", l_size);
	for (int i = 0; i < l_size; i++) {
		int l_objectIndex;
		i_stream >> l_objectIndex;
		if (l_playLayer) addObject(l_playLayer->getGameObject(l_objectIndex));
	}
}

template <>
void PUCCArray::save<GradientTriggerObject>(OutputStream& o_stream) {
	unsigned int l_size = count();
	o_stream << l_size;
	//geode::log::info("CCARRAY GradientTriggerObject SIZE out: {}", l_size);
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	for (int i = 0; i < l_size; i++) {
		int l_objectIndex = -1;
		if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(static_cast<GameObject*>(objectAtIndex(i)));
		o_stream << l_objectIndex;
	}
}

template <class T>
void PUCCArray::loadOne(InputStream& i_stream) {
	T* l_object = reinterpret_cast<T*>(malloc(sizeof(T)));
	reinterpret_cast<T*>(l_object)->load(i_stream); 
	addObject(l_object);
}

template <class T>
void PUCCArray::saveOne(OutputStream& o_stream, unsigned int i_index) {
	reinterpret_cast<T*>(objectAtIndex(i_index))->save(o_stream); 
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
// template <>
// void PUCCArray::describe<PUCheckpointObject>() {
// 	int l_size = this->count();
// 	log::info("[PUCCArray CheckpointObject - describe] count(): {}", l_size);
// 	for (int i = 0; i < l_size; i++) {
// 		log::info("[PUCCArray CheckpointObject - describe] this[{}]:", i);
// 		reinterpret_cast<PUCheckpointObject*>(objectAtIndex(i))->describe();
// 	}
// } 

template <>
void PUCCArray::describe<GradientTriggerObject>() {
	int l_size = this->count();
	log::info("[PUCCArray GradientTriggerObject - describe] count(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		int l_objectIndex = -1;
		PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
		if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(static_cast<GameObject*>(objectAtIndex(i)));
		log::info("[PUCCArray GradientTriggerObject - describe] l_objectIndex[{}]: {}", i, l_objectIndex);
	}
}
#endif