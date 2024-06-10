#include "util/InputStream.hpp"
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

using namespace persistencyUtils;

// vector

template<class T, class U>
inline void readGenericVector(InputStream* i_stream, gd::vector<T>& o_value) {
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
void InputStream::operator>><DynamicSaveObject>(gd::vector<DynamicSaveObject>& o_value) {
	readGenericVector<DynamicSaveObject, PUDynamicSaveObject>(this, o_value);
}

template <>
void InputStream::operator>><ActiveSaveObject1>(gd::vector<ActiveSaveObject1>& o_value) {
	readGenericVector<ActiveSaveObject1, PUActiveSaveObject1>(this, o_value);
}

template <>
void InputStream::operator>><ActiveSaveObject2>(gd::vector<ActiveSaveObject2>& o_value) {
	readGenericVector<ActiveSaveObject2, PUActiveSaveObject2>(this, o_value);
}

template <>
void InputStream::operator>><CountTriggerAction>(gd::vector<CountTriggerAction>& o_value) {
	readGenericVector<CountTriggerAction, PUCountTriggerAction>(this, o_value);
}

template <>
void InputStream::operator>><TouchToggleAction>(gd::vector<TouchToggleAction>& o_value) {
	readGenericVector<TouchToggleAction, PUTouchToggleAction>(this, o_value);
}

template <>
void InputStream::operator>><CollisionTriggerAction>(gd::vector<CollisionTriggerAction>& o_value) {
	readGenericVector<CollisionTriggerAction, PUCollisionTriggerAction>(this, o_value);
}

template <>
void InputStream::operator>><ToggleTriggerAction>(gd::vector<ToggleTriggerAction>& o_value) {
	readGenericVector<ToggleTriggerAction, PUToggleTriggerAction>(this, o_value);
}

template <>
void InputStream::operator>><SpawnTriggerAction>(gd::vector<SpawnTriggerAction>& o_value) {
	readGenericVector<SpawnTriggerAction, PUSpawnTriggerAction>(this, o_value);
}

template <>
void InputStream::operator>><GroupCommandObject2>(gd::vector<GroupCommandObject2>& o_value) {
	readGenericVector<GroupCommandObject2, PUGroupCommandObject2>(this, o_value);
}

template <>
void InputStream::operator>><KeyframeObject>(gd::vector<KeyframeObject>& o_value) {
	readGenericVector<KeyframeObject, PUKeyframeObject>(this, o_value);
}

template <>
void InputStream::operator>><TimerTriggerAction>(gd::vector<TimerTriggerAction>& o_value) {
	readGenericVector<TimerTriggerAction, PUTimerTriggerAction>(this, o_value);
}

template <>
void InputStream::operator>><EventTriggerInstance>(gd::vector<EventTriggerInstance>& o_value) {
	readGenericVector<EventTriggerInstance, PUEventTriggerInstance>(this, o_value);
}

template <>
void InputStream::operator>><EnterEffectInstance>(gd::vector<EnterEffectInstance>& o_value) {
	readGenericVector<EnterEffectInstance, PUEnterEffectInstance>(this, o_value);
}

template <>
void InputStream::operator>><AdvancedFollowInstance>(gd::vector<AdvancedFollowInstance>& o_value) {
	readGenericVector<AdvancedFollowInstance, PUAdvancedFollowInstance>(this, o_value);
}

template <>
void InputStream::operator>><CAState>(gd::vector<CAState>& o_value) {
	readGenericVector<CAState, PUCAState>(this, o_value);
}

template <>
void InputStream::operator>><SongTriggerState>(gd::vector<SongTriggerState>& o_value) {
	readGenericVector<SongTriggerState, PUSongTriggerState>(this, o_value);
}

template <>
void InputStream::operator>><SFXTriggerState>(gd::vector<SFXTriggerState>& o_value) {
	readGenericVector<SFXTriggerState, PUSFXTriggerState>(this, o_value);
}

template <>
void InputStream::operator>><DynamicObjectAction>(gd::vector<DynamicObjectAction>& o_value) {
	readGenericVector<DynamicObjectAction, PUDynamicObjectAction>(this, o_value);
}

// unordered_map

template<class K, class V, class W>
inline void readGenericUnorderedMap(InputStream* i_stream, gd::unordered_map<K,V>& o_value) {
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
void InputStream::operator>><int, SequenceTriggerState>(gd::unordered_map<int, SequenceTriggerState>& o_value) {
	readGenericUnorderedMap<int, SequenceTriggerState, PUSequenceTriggerState>(this, o_value);
}

template <>
void InputStream::operator>><int, FMODQueuedMusic>(gd::unordered_map<int, FMODQueuedMusic>& o_value) {
	readGenericUnorderedMap<int, FMODQueuedMusic, PUFMODQueuedMusic>(this, o_value);
}

template <>
void InputStream::operator>><int, FMODSoundState>(gd::unordered_map<int, FMODSoundState>& o_value) {
	readGenericUnorderedMap<int, FMODSoundState, PUFMODSoundState>(this, o_value);
}

template <>
void InputStream::operator>><int, TimerItem>(gd::unordered_map<int, TimerItem>& o_value) {
	readGenericUnorderedMap<int, TimerItem, PUTimerItem>(this, o_value);
}

template <>
void InputStream::operator>><int, SongChannelState>(gd::unordered_map<int, SongChannelState>& o_value) {
	readGenericUnorderedMap<int, SongChannelState, PUSongChannelState>(this, o_value);
}

template <>
void InputStream::operator>><int, EnhancedGameObject*>(gd::unordered_map<int, EnhancedGameObject*>& o_value) {
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
inline void readGenericMap(InputStream* i_stream, gd::map<K,V>& o_value) {
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
void InputStream::operator>><std::pair<int,int>, SFXTriggerInstance>(gd::map<std::pair<int,int>, SFXTriggerInstance>& o_value) {
	geode::log::info("jjjjjjjjjjjjjjjjjjjjj Map CustomRead SFXTriggerInstance");
	readGenericMap<std::pair<int,int>, SFXTriggerInstance, PUSFXTriggerInstance>(this, o_value);
}