#include "util/Stream.hpp"
#include "Geode/binding/GameObject.hpp"
#include "hooks/SavedObjectStateRef.hpp"
#include "hooks/SavedActiveObjectState.hpp"
#include "hooks/SavedSpecialObjectState.hpp"
#include "hooks/SequenceTriggerState.hpp"
#include "hooks/FMODQueuedMusic.hpp"
#include "hooks/FMODSoundState.hpp"
#include "hooks/TimerItem.hpp"
#include "hooks/TimerTriggerAction.hpp"
#include "hooks/KeyframeObject.hpp"
#include "hooks/GroupCommandObject2.hpp"
#include "hooks/SpawnTriggerAction.hpp"
#include "hooks/ToggleTriggerAction.hpp"
#include "hooks/CollisionTriggerAction.hpp"
#include "hooks/TouchToggleAction.hpp"
#include "hooks/CountTriggerAction.hpp"
#include "hooks/EventTriggerInstance.hpp"
#include "hooks/EnterEffectInstance.hpp"
#include "hooks/AdvancedFollowInstance.hpp"
#include "hooks/CAState.hpp"
#include "hooks/PlayLayer.hpp"
#include "hooks/SongChannelState.hpp"
#include "hooks/SongTriggerState.hpp"
#include "hooks/SFXTriggerState.hpp"
#include "hooks/SFXTriggerInstance.hpp"
#include "hooks/EnterEffectAnimValue.hpp"
#include "hooks/FMODSoundTween.hpp"
#include "hooks/GJValueTween.hpp"
#include "hooks/GameObjectPhysics.hpp"
#include "hooks/OpacityEffectAction.hpp"
#include "hooks/PulseEffectAction.hpp"
#include "hooks/DynamicObjectAction.hpp"

using namespace persistenceAPI;

// GameObject*

template<class T>
inline void writeGenericGameObjectPtr(Stream* o_stream, T** i_value) {
    int l_objectIndex = -1;
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(static_cast<GameObject*>(*i_value));
    o_stream->write(reinterpret_cast<char*>(&l_objectIndex), 4);
}

void Stream::operator<<(GameObject*& i_value) {
    writeGenericGameObjectPtr<GameObject>(this, &i_value);
}

void Stream::operator<<(SFXTriggerGameObject*& i_value) {
    writeGenericGameObjectPtr<SFXTriggerGameObject>(this, &i_value);
}

void Stream::operator<<(SongTriggerGameObject*& i_value) {
    writeGenericGameObjectPtr<SongTriggerGameObject>(this, &i_value);
}

void Stream::operator<<(DashRingObject*& i_value) {
    writeGenericGameObjectPtr<DashRingObject>(this, &i_value);
}

void Stream::operator<<(EnterEffectObject*& i_value) {
    writeGenericGameObjectPtr<EnterEffectObject>(this, &i_value);
}

// vector

template<class T, class U>
inline void writeGenericVector(Stream* o_stream, gd::vector<T>& i_value) {
    unsigned int l_size = i_value.size();
    o_stream->write(reinterpret_cast<char*>(&l_size), 4);
    //geode::log::info("VECTOR SIZE CustomWrite SIZE out: {}", l_size);
    if (l_size == 0) return;
    for (int i = 0; i < l_size; i++) {
        reinterpret_cast<U&>(i_value[i]).save(*o_stream);
    }
}

template <>
void Stream::operator<<<SavedObjectStateRef>(gd::vector<SavedObjectStateRef>& i_value) {
    writeGenericVector<SavedObjectStateRef, PASavedObjectStateRef>(this, i_value);
}

template <>
void Stream::operator<<<SavedActiveObjectState>(gd::vector<SavedActiveObjectState>& i_value) {
    writeGenericVector<SavedActiveObjectState, PASavedActiveObjectState>(this, i_value);
}

template <>
void Stream::operator<<<SavedSpecialObjectState>(gd::vector<SavedSpecialObjectState>& i_value) {
    writeGenericVector<SavedSpecialObjectState, PASavedSpecialObjectState>(this, i_value);
}

template <>
void Stream::operator<<<CountTriggerAction>(gd::vector<CountTriggerAction>& i_value) {
    //geode::log::info("1111111111111111111 VECTOR CustomWrite CountTriggerAction");
    writeGenericVector<CountTriggerAction, PACountTriggerAction>(this, i_value);
}

template <>
void Stream::operator<<<TouchToggleAction>(gd::vector<TouchToggleAction>& i_value) {
    //geode::log::info("22222222222222222222 VECTOR CustomWrite TouchToggleAction");
    writeGenericVector<TouchToggleAction, PATouchToggleAction>(this, i_value);
}

template <>
void Stream::operator<<<CollisionTriggerAction>(gd::vector<CollisionTriggerAction>& i_value) {
    //geode::log::info("33333333333333333333 VECTOR CustomWrite CollisionTriggerAction");
    writeGenericVector<CollisionTriggerAction, PACollisionTriggerAction>(this, i_value);
}

template <>
void Stream::operator<<<ToggleTriggerAction>(gd::vector<ToggleTriggerAction>& i_value) {
    //geode::log::info("4444444444444444444 VECTOR CustomWrite ToggleTriggerAction");
    writeGenericVector<ToggleTriggerAction, PAToggleTriggerAction>(this, i_value);
}

template <>
void Stream::operator<<<SpawnTriggerAction>(gd::vector<SpawnTriggerAction>& i_value) {
    //geode::log::info("55555555555555555555 VECTOR CustomWrite SpawnTriggerAction");
    writeGenericVector<SpawnTriggerAction, PASpawnTriggerAction>(this, i_value);
}

template <>
void Stream::operator<<<GroupCommandObject2>(gd::vector<GroupCommandObject2>& i_value) {
    //geode::log::info("666666666666666666666 VECTOR CustomWrite GroupCommandObject2");
    writeGenericVector<GroupCommandObject2, PAGroupCommandObject2>(this, i_value);
}

template <>
void Stream::operator<<<KeyframeObject>(gd::vector<KeyframeObject>& i_value) {
    //geode::log::info("777777777777777777 VECTOR CustomWrite KeyframeObject");
    writeGenericVector<KeyframeObject, PAKeyframeObject>(this, i_value);
}

template <>
void Stream::operator<<<TimerTriggerAction>(gd::vector<TimerTriggerAction>& i_value) {
    //geode::log::info("8888888888888888888 VECTOR CustomWrite TimerTriggerAction");
    writeGenericVector<TimerTriggerAction, PATimerTriggerAction>(this, i_value);
}

template <>
void Stream::operator<<<EventTriggerInstance>(gd::vector<EventTriggerInstance>& i_value) {
    //geode::log::info("00000000000 VECTOR CustomWrite EventTriggerInstance");
    writeGenericVector<EventTriggerInstance, PAEventTriggerInstance>(this, i_value);
}

template <>
void Stream::operator<<<EnterEffectInstance>(gd::vector<EnterEffectInstance>& i_value) {
    //geode::log::info("00232353000064545@@@@00003 VECTOR CustomWrite EnterEffectInstance");
    writeGenericVector<EnterEffectInstance, PAEnterEffectInstance>(this, i_value);
}

template <>
void Stream::operator<<<AdvancedFollowInstance>(gd::vector<AdvancedFollowInstance>& i_value) {
    //geode::log::info("UWUWUWUWUWUWUWUUWUWUWUWW VECTOR CustomWrite AdvancedFollowInstance");
    writeGenericVector<AdvancedFollowInstance, PAAdvancedFollowInstance>(this, i_value);
}

template <>
void Stream::operator<<<CAState>(gd::vector<CAState>& i_value) {
    //geode::log::info("OWOWOWOWOOWOWOW VECTOR CustomWrite CAState");
    writeGenericVector<CAState, PACAState>(this, i_value);
}

template <>
void Stream::operator<<<SongTriggerState>(gd::vector<SongTriggerState>& i_value) {
    //geode::log::info("AWAWAWAWWAAWAWWAAWAW VECTOR CustomWrite SongTriggerState");
    writeGenericVector<SongTriggerState, PASongTriggerState>(this, i_value);
}

template <>
void Stream::operator<<<SFXTriggerState>(gd::vector<SFXTriggerState>& i_value) {
    //geode::log::info("EWEWEWEWEWEWE VECTOR CustomWrite SFXTriggerState");
    writeGenericVector<SFXTriggerState, PASFXTriggerState>(this, i_value);
}

template <>
void Stream::operator<<<DynamicObjectAction>(gd::vector<DynamicObjectAction>& i_value) {
    //geode::log::info("EWEWEWEWEWEWE VECTOR CustomWrite DynamicObjectAction");
    writeGenericVector<DynamicObjectAction, PADynamicObjectAction>(this, i_value);
}

template <>
void Stream::operator<<<PulseEffectAction>(gd::vector<PulseEffectAction>& i_value) {
    //geode::log::info("444444444444444411111111111111 VECTOR CustomWrite PulseEffectAction");
    writeGenericVector<PulseEffectAction, PAPulseEffectAction>(this, i_value);
}

// unordered_map

template<class K, class V, class W>
inline void writeGenericUnorderedMap(Stream* o_stream, gd::unordered_map<K,V>& i_value) {
    unsigned int l_size = i_value.size();
    o_stream->write(reinterpret_cast<char*>(&l_size), 4);
    //geode::log::info("Unordered Map CustomWrite SIZE out: {}", l_size);
    if (l_size == 0) return;
    for (std::pair<K,V> l_pair : i_value) {
        o_stream->write(reinterpret_cast<char*>(&l_pair.first), sizeof(K));
        reinterpret_cast<W&>(l_pair.second).save(*o_stream);
    }
}

template <>
void Stream::operator<<<int, SequenceTriggerState>(gd::unordered_map<int, SequenceTriggerState>& i_value) {
    writeGenericUnorderedMap<int, SequenceTriggerState, PASequenceTriggerState>(this, i_value);
}

template <>
void Stream::operator<<<int, FMODQueuedMusic>(gd::unordered_map<int, FMODQueuedMusic>& i_value) {
    writeGenericUnorderedMap<int, FMODQueuedMusic, PAFMODQueuedMusic>(this, i_value);
}

template <>
void Stream::operator<<<int, FMODSoundState>(gd::unordered_map<int, FMODSoundState>& i_value) {
    writeGenericUnorderedMap<int, FMODSoundState, PAFMODSoundState>(this, i_value);
}

template <>
void Stream::operator<<<int, TimerItem>(gd::unordered_map<int, TimerItem>& i_value) {
    //geode::log::info("999999999999999999999 Unordered Map CustomWrite TimerItem");
    writeGenericUnorderedMap<int, TimerItem, PATimerItem>(this, i_value);
}

template <>
void Stream::operator<<<int, SongChannelState>(gd::unordered_map<int, SongChannelState>& i_value) {
    //geode::log::info("jjjjjjjjjjjjjjjjjjjjj Unordered Map CustomWrite SongChannelState");
    writeGenericUnorderedMap<int, SongChannelState, PASongChannelState>(this, i_value);
}

template <>
void Stream::operator<<<int, GJValueTween>(gd::unordered_map<int, GJValueTween>& i_value) {
    //geode::log::info("************************ Unordered Map CustomWrite GJValueTween");
    writeGenericUnorderedMap<int, GJValueTween, PAGJValueTween>(this, i_value);
}

template <>
void Stream::operator<<<int, GameObjectPhysics>(gd::unordered_map<int, GameObjectPhysics>& i_value) {
    //geode::log::info("&&&&&&&&&&&&&&&&&&&&&&&&& Unordered Map CustomWrite GameObjectPhysics");
    writeGenericUnorderedMap<int, GameObjectPhysics, PAGameObjectPhysics>(this, i_value);
}

template <>
void Stream::operator<<<int, OpacityEffectAction>(gd::unordered_map<int, OpacityEffectAction>& i_value) {
    //geode::log::info("^^^^^^^^^^^^^^^^^^^^^^^^^^ Unordered Map CustomWrite OpacityEffectAction");
    writeGenericUnorderedMap<int, OpacityEffectAction, PAOpacityEffectAction>(this, i_value);
}

template <>
void Stream::operator<<<int, EnhancedGameObject*>(gd::unordered_map<int, EnhancedGameObject*>& i_value) {
    unsigned int l_size = i_value.size();
    this->write(reinterpret_cast<char*>(&l_size), 4);
    //geode::log::info("Unordered Map CustomWrite EnhancedGameObject* SIZE out: {}", l_size);
    if (l_size == 0) return;
    int l_objectIndex;
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    for (std::pair<int, EnhancedGameObject*> l_pair : i_value) {
        this->write(reinterpret_cast<char*>(&l_pair.first), sizeof(int));
        int l_objectIndex = -1;
        if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(l_pair.second);
        this->write(reinterpret_cast<char*>(&l_objectIndex), sizeof(int));
    }
}

// map

template<class K, class V, class W>
inline void writeGenericMap(Stream* o_stream, gd::map<K,V>& i_value) {
    unsigned int l_size = i_value.size();
    o_stream->write(reinterpret_cast<char*>(&l_size), 4);
    //geode::log::info("Map CustomWrite SIZE out: {}", l_size);
    if (l_size == 0) return;
    for (std::pair<K,V> l_pair : i_value) {
        o_stream->write(reinterpret_cast<char*>(&l_pair.first), sizeof(K));
        reinterpret_cast<W&>(l_pair.second).save(*o_stream);
    }
}

template <>
void Stream::operator<<<std::pair<int,int>, SFXTriggerInstance>(gd::map<std::pair<int,int>, SFXTriggerInstance>& i_value) {
    //geode::log::info("jjjjjjjjjjjjjjjjjjjjj Map CustomWrite SFXTriggerInstance");
    writeGenericMap<std::pair<int,int>, SFXTriggerInstance, PASFXTriggerInstance>(this, i_value);
}

template <>
void Stream::operator<<<int, EnterEffectAnimValue>(gd::map<int, EnterEffectAnimValue>& i_value) {
    //geode::log::info("ooooooooooooooooooooooooooooooo Map CustomWrite EnterEffectAnimValue");
    writeGenericMap<int, EnterEffectAnimValue, PAEnterEffectAnimValue>(this, i_value);
}

template <>
void Stream::operator<<<std::pair<int,int>, FMODSoundTween>(gd::map<std::pair<int,int>, FMODSoundTween>& i_value) {
    //geode::log::info("aaaaaaaaaaaaaaaaaaaaaaaaaaa Map CustomWrite FMODSoundTween");
    writeGenericMap<std::pair<int,int>, FMODSoundTween, PAFMODSoundTween>(this, i_value);
}