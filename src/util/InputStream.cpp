#include "util/Stream.hpp"
#include "hooks/DynamicSaveObject.hpp"
#include "hooks/ActiveSaveObject.hpp"
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
#include "hooks/SongChannelState.hpp"
#include "hooks/SongTriggerState.hpp"
#include "hooks/SFXTriggerState.hpp"
#include "hooks/SFXTriggerInstance.hpp"
#include "hooks/DynamicObjectAction.hpp"
#include "hooks/PlayLayer.hpp"

using namespace persistenceAPI;

// GameObject*

template<class T>
inline void readGenericGameObjectPtr(Stream* i_stream, T** o_value) {
	//geode::log::info(" @@@@@@@@@@ Custom GameObject* operator>> GETS CALLED @@@@@@@@@@@@@@");
	int l_objectIndex;
	i_stream->read(reinterpret_cast<char*>(&l_objectIndex), 4);
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) *o_value = static_cast<T*>(l_playLayer->getGameObject(l_objectIndex));
}

void Stream::operator>>(GameObject*& o_value) {
	readGenericGameObjectPtr<GameObject>(this, &o_value);
}

void Stream::operator>>(SFXTriggerGameObject*& o_value) {
	readGenericGameObjectPtr<SFXTriggerGameObject>(this, &o_value);
}

void Stream::operator>>(SongTriggerGameObject*& o_value) {
	readGenericGameObjectPtr<SongTriggerGameObject>(this, &o_value);
}

// vector

template<class T, class U>
inline void readGenericVector(Stream* i_stream, gd::vector<T>& o_value) {
	//geode::log::info("Vector CustomRead Existing SIZE: {}", o_value.size());
	unsigned int l_size;
	i_stream->read(reinterpret_cast<char*>(&l_size), 4);
	//geode::log::info("VECTOR SIZE CustomRead SIZE in: {}", l_size);
	if (l_size == 0) return;
	o_value.resize(l_size);
	for (int i = 0; i < l_size; i++) {
		//geode::log::info("VECTOR SIZE CustomRead SIZE in TRYING TO LOAD: {}", l_size);
		//geode::log::info("VECTOR REAL SIZE CustomRead SIZE in TRYING TO LOAD: {}", o_value.size());
		reinterpret_cast<U*>((reinterpret_cast<size_t>(o_value.data())+(i*sizeof(T))))->load(*i_stream);
	}
}

template <>
void Stream::operator>><DynamicSaveObject>(gd::vector<DynamicSaveObject>& o_value) {
	readGenericVector<DynamicSaveObject, PADynamicSaveObject>(this, o_value);
}

template <>
void Stream::operator>><ActiveSaveObject1>(gd::vector<ActiveSaveObject1>& o_value) {
	readGenericVector<ActiveSaveObject1, PAActiveSaveObject1>(this, o_value);
}

template <>
void Stream::operator>><ActiveSaveObject2>(gd::vector<ActiveSaveObject2>& o_value) {
	readGenericVector<ActiveSaveObject2, PAActiveSaveObject2>(this, o_value);
}

template <>
void Stream::operator>><CountTriggerAction>(gd::vector<CountTriggerAction>& o_value) {
	readGenericVector<CountTriggerAction, PACountTriggerAction>(this, o_value);
}

template <>
void Stream::operator>><TouchToggleAction>(gd::vector<TouchToggleAction>& o_value) {
	readGenericVector<TouchToggleAction, PATouchToggleAction>(this, o_value);
}

template <>
void Stream::operator>><CollisionTriggerAction>(gd::vector<CollisionTriggerAction>& o_value) {
	readGenericVector<CollisionTriggerAction, PACollisionTriggerAction>(this, o_value);
}

template <>
void Stream::operator>><ToggleTriggerAction>(gd::vector<ToggleTriggerAction>& o_value) {
	readGenericVector<ToggleTriggerAction, PAToggleTriggerAction>(this, o_value);
}

template <>
void Stream::operator>><SpawnTriggerAction>(gd::vector<SpawnTriggerAction>& o_value) {
	readGenericVector<SpawnTriggerAction, PASpawnTriggerAction>(this, o_value);
}

template <>
void Stream::operator>><GroupCommandObject2>(gd::vector<GroupCommandObject2>& o_value) {
	readGenericVector<GroupCommandObject2, PAGroupCommandObject2>(this, o_value);
}

template <>
void Stream::operator>><KeyframeObject>(gd::vector<KeyframeObject>& o_value) {
	readGenericVector<KeyframeObject, PAKeyframeObject>(this, o_value);
}

template <>
void Stream::operator>><TimerTriggerAction>(gd::vector<TimerTriggerAction>& o_value) {
	readGenericVector<TimerTriggerAction, PATimerTriggerAction>(this, o_value);
}

template <>
void Stream::operator>><EventTriggerInstance>(gd::vector<EventTriggerInstance>& o_value) {
	readGenericVector<EventTriggerInstance, PAEventTriggerInstance>(this, o_value);
}

template <>
void Stream::operator>><EnterEffectInstance>(gd::vector<EnterEffectInstance>& o_value) {
	readGenericVector<EnterEffectInstance, PAEnterEffectInstance>(this, o_value);
}

template <>
void Stream::operator>><AdvancedFollowInstance>(gd::vector<AdvancedFollowInstance>& o_value) {
	readGenericVector<AdvancedFollowInstance, PAAdvancedFollowInstance>(this, o_value);
}

template <>
void Stream::operator>><CAState>(gd::vector<CAState>& o_value) {
	readGenericVector<CAState, PACAState>(this, o_value);
}

template <>
void Stream::operator>><SongTriggerState>(gd::vector<SongTriggerState>& o_value) {
	readGenericVector<SongTriggerState, PASongTriggerState>(this, o_value);
}

template <>
void Stream::operator>><SFXTriggerState>(gd::vector<SFXTriggerState>& o_value) {
	readGenericVector<SFXTriggerState, PASFXTriggerState>(this, o_value);
}

template <>
void Stream::operator>><DynamicObjectAction>(gd::vector<DynamicObjectAction>& o_value) {
	readGenericVector<DynamicObjectAction, PADynamicObjectAction>(this, o_value);
}

// unordered_map

template<class K, class V, class W>
inline void readGenericUnorderedMap(Stream* i_stream, gd::unordered_map<K,V>& o_value) {
	if (o_value.size() != 0) {
		//geode::log::info("VECTOR SIZE SHOULD NOT BE HERE AGRIA: {}", o_value.size());
		o_value.clear();
	}
	unsigned int l_size;
	i_stream->read(reinterpret_cast<char*>(&l_size), 4);
	//geode::log::info("Unordered Map CustomRead SIZE in: {}", l_size);
	for (int i = 0; i < l_size; i++) {
		K l_key;
		i_stream->read(reinterpret_cast<char*>(&l_key), sizeof(K));
		reinterpret_cast<W&>(o_value[l_key]).load(*i_stream);
	}
}

template <>
void Stream::operator>><int, SequenceTriggerState>(gd::unordered_map<int, SequenceTriggerState>& o_value) {
	readGenericUnorderedMap<int, SequenceTriggerState, PASequenceTriggerState>(this, o_value);
}

template <>
void Stream::operator>><int, FMODQueuedMusic>(gd::unordered_map<int, FMODQueuedMusic>& o_value) {
	readGenericUnorderedMap<int, FMODQueuedMusic, PAFMODQueuedMusic>(this, o_value);
}

template <>
void Stream::operator>><int, FMODSoundState>(gd::unordered_map<int, FMODSoundState>& o_value) {
	readGenericUnorderedMap<int, FMODSoundState, PAFMODSoundState>(this, o_value);
}

template <>
void Stream::operator>><int, TimerItem>(gd::unordered_map<int, TimerItem>& o_value) {
	readGenericUnorderedMap<int, TimerItem, PATimerItem>(this, o_value);
}

template <>
void Stream::operator>><int, SongChannelState>(gd::unordered_map<int, SongChannelState>& o_value) {
	readGenericUnorderedMap<int, SongChannelState, PASongChannelState>(this, o_value);
}

template <>
void Stream::operator>><int, EnhancedGameObject*>(gd::unordered_map<int, EnhancedGameObject*>& o_value) {
	unsigned int l_size;
	this->read(reinterpret_cast<char*>(&l_size), 4);
	//geode::log::info("Unordered Map EnhancedGameObject* CustomRead SIZE in: {}", l_size);
	for (int i = 0; i < l_size; i++) {
		int l_key;
		int l_objectIndex;
		this->read(reinterpret_cast<char*>(&l_key), sizeof(int));
		this->read(reinterpret_cast<char*>(&l_objectIndex), sizeof(int));

		PlayLayer* l_playLayer = PlayLayer::get();
		if (l_playLayer && l_objectIndex != -1) {
			o_value[l_key] = static_cast<EnhancedGameObject*>(l_playLayer->m_objects->objectAtIndex(l_objectIndex));
		} else {
			o_value[l_key] = nullptr;
		}
	}
}

// map

template<class K, class V, class W>
inline void readGenericMap(Stream* i_stream, gd::map<K,V>& o_value) {
	if (o_value.size() != 0) {
		//geode::log::info("VECTOR SIZE SHOULD NOT BE HERE AGRIA: {}", o_value.size());
		o_value.clear();
	}
	unsigned int l_size;
	i_stream->read(reinterpret_cast<char*>(&l_size), 4);
	//geode::log::info("Map CustomRead SIZE in: {}", l_size);
	for (int i = 0; i < l_size; i++) {
		K l_key;
		i_stream->read(reinterpret_cast<char*>(&l_key), sizeof(K));
		reinterpret_cast<W&>(o_value[l_key]).load(*i_stream);
	}
}

template <>
void Stream::operator>><std::pair<int,int>, SFXTriggerInstance>(gd::map<std::pair<int,int>, SFXTriggerInstance>& o_value) {
	//geode::log::info("jjjjjjjjjjjjjjjjjjjjj Map CustomRead SFXTriggerInstance");
	readGenericMap<std::pair<int,int>, SFXTriggerInstance, PASFXTriggerInstance>(this, o_value);
}