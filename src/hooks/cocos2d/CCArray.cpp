#include "hooks/cocos2d/CCArray.hpp"
#include "hooks/cocos2d/CCObject.hpp"
#include "hooks/PlayLayer.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

template <class T>
void PACCArray::load(Stream& i_stream) {
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
void PACCArray::save(Stream& o_stream) {
    unsigned int l_size = count();
    o_stream << l_size;
    //geode::log::info("CCARRAY SIZE out: {}", l_size);
    for (int i = 0; i < l_size; i++) {
       reinterpret_cast<T*>(objectAtIndex(i))->save(o_stream);
    }
}

template <>
void PACCArray::load<GameObject>(Stream& i_stream) {
    removeAllObjects();
    unsigned int l_size;
    i_stream >> l_size;
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    for (int i = 0; i < l_size; i++) {
        int l_objectIndex;
        i_stream >> l_objectIndex;
        if (l_playLayer) addObject(l_playLayer->getGameObject(l_objectIndex));
    }
}

template <>
void PACCArray::save<GameObject>(Stream& o_stream) {
    unsigned int l_size = count();
    o_stream << l_size;
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    for (int i = 0; i < l_size; i++) {
        int l_objectIndex = -1;
        if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(static_cast<GameObject*>(objectAtIndex(i)));
        o_stream << l_objectIndex;
    }
}

template <>
void PACCArray::load<GradientTriggerObject>(Stream& i_stream) {
    removeAllObjects();
    unsigned int l_size;
    i_stream >> l_size;
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    //geode::log::info("CCARRAY GradientTriggerObject SIZE in: {}", l_size);
    for (int i = 0; i < l_size; i++) {
        int l_objectIndex;
        i_stream >> l_objectIndex;
        if (l_playLayer) addObject(l_playLayer->getGameObject(l_objectIndex));
    }
}

template <>
void PACCArray::save<GradientTriggerObject>(Stream& o_stream) {
    unsigned int l_size = count();
    o_stream << l_size;
    //geode::log::info("CCARRAY GradientTriggerObject SIZE out: {}", l_size);
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    for (int i = 0; i < l_size; i++) {
        int l_objectIndex = -1;
        if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(static_cast<GameObject*>(objectAtIndex(i)));
        o_stream << l_objectIndex;
    }
}

template <class T>
void PACCArray::loadOne(Stream& i_stream) {
    T* l_object = reinterpret_cast<T*>(malloc(sizeof(T)));
    reinterpret_cast<T*>(l_object)->load(i_stream);
    addObject(l_object);
}

template <class T>
void PACCArray::saveOne(Stream& o_stream, unsigned int i_index) {
    reinterpret_cast<T*>(objectAtIndex(i_index))->save(o_stream);
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
template <>
void PACCArray::describe<GradientTriggerObject>() {
    int l_size = this->count();
    log::info("[PACCArray GradientTriggerObject - describe] count(): {}", l_size);
    for (int i = 0; i < l_size; i++) {
        int l_objectIndex = -1;
        PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
        if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(static_cast<GameObject*>(objectAtIndex(i)));
        log::info("[PACCArray GradientTriggerObject - describe] l_objectIndex[{}]: {}", i, l_objectIndex);
    }
}
#endif