#include "hooks/EffectManagerState.hpp"
#include "Geode/binding/CountTriggerAction.hpp"
#include "Geode/binding/OpacityEffectAction.hpp"
#include "Geode/binding/PulseEffectAction.hpp"
#include "Geode/binding/TimerItem.hpp"
#include "Geode/binding/TimerTriggerAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/CountTriggerAction.hpp"
#include "hooks/TouchToggleAction.hpp"
#include "hooks/CollisionTriggerAction.hpp"
#include "hooks/ToggleTriggerAction.hpp"
#include "hooks/SpawnTriggerAction.hpp"
#include "hooks/GroupCommandObject2.hpp"
#include "hooks/TimerItem.hpp"
#include "hooks/TimerTriggerAction.hpp"
#include "hooks/CAState.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAEffectManagerState::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PAEffectManagerState::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PAEffectManagerState& o_value) {
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecCAState;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecPulseEffectAction;
	VEC_SEPARATOR_I
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unorderedMapInt_vectorPulseEffectAction;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unorderedMapInt_vectorCountTriggerAction;
	UMAP_SEPARATOR_I
	USET_SEPARATOR_I
	i_stream >> o_value.m_unorderedSet_int1;
	USET_SEPARATOR_I
	MAP_SEPARATOR_I
	i_stream >> o_value.m_mapInt_Int;
	MAP_SEPARATOR_I
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unorderedMapInt_OpacityEffectAction;
	UMAP_SEPARATOR_I
	VEC_SEPARATOR_I
	i_stream >> o_value.m_vectorTouchToggleAction;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_vectorCollisionTriggerAction;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_vectorToggleTriggerAction;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_vectorSpawnTriggerAction;
	VEC_SEPARATOR_I
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unorderedMapInt_int;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unorderedMapInt_bool;
	UMAP_SEPARATOR_I
	VEC_SEPARATOR_I
	i_stream >> o_value.m_vectorGroupCommandObject2;
	VEC_SEPARATOR_I
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unorderedMapInt_pair_double_double;
	UMAP_SEPARATOR_I
	USET_SEPARATOR_I
	i_stream >> o_value.m_unorderedSet_int2;
	USET_SEPARATOR_I
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unorderedMapInt_TimerItem;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unorderedMapInt_vectorTimerTriggerAction;
	UMAP_SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PAEffectManagerState& i_value) {
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecCAState;
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecPulseEffectAction;
	VEC_SEPARATOR_O
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unorderedMapInt_vectorPulseEffectAction;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unorderedMapInt_vectorCountTriggerAction;
	UMAP_SEPARATOR_O
	USET_SEPARATOR_O
	o_stream << i_value.m_unorderedSet_int1;
	USET_SEPARATOR_O
	MAP_SEPARATOR_O
	o_stream << i_value.m_mapInt_Int;
	MAP_SEPARATOR_O
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unorderedMapInt_OpacityEffectAction;
	UMAP_SEPARATOR_O
	VEC_SEPARATOR_O
	o_stream << i_value.m_vectorTouchToggleAction;
	VEC_SEPARATOR_O
	o_stream << i_value.m_vectorCollisionTriggerAction;
	VEC_SEPARATOR_O
	o_stream << i_value.m_vectorToggleTriggerAction;
	VEC_SEPARATOR_O
	o_stream << i_value.m_vectorSpawnTriggerAction;
	VEC_SEPARATOR_O
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unorderedMapInt_int;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unorderedMapInt_bool;
	UMAP_SEPARATOR_O
	VEC_SEPARATOR_O
	o_stream << i_value.m_vectorGroupCommandObject2;
	VEC_SEPARATOR_O
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unorderedMapInt_pair_double_double;
	UMAP_SEPARATOR_O
	USET_SEPARATOR_O
	o_stream << i_value.m_unorderedSet_int2;
	USET_SEPARATOR_O
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unorderedMapInt_TimerItem;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unorderedMapInt_vectorTimerTriggerAction;
	UMAP_SEPARATOR_O
}

void PAEffectManagerState::clean() {
	m_unkVecCAState.clear();
	gd::vector<CAState>().swap(m_unkVecCAState);

	m_unkVecPulseEffectAction.clear();
	gd::vector<PulseEffectAction>().swap(m_unkVecPulseEffectAction);

	for (std::pair<int, gd::vector<PulseEffectAction>> l_pair : m_unorderedMapInt_vectorPulseEffectAction) {
		l_pair.second.clear();
		gd::vector<PulseEffectAction>().swap(l_pair.second);
	}

	for (std::pair<int, gd::vector<CountTriggerAction>> l_pair : m_unorderedMapInt_vectorCountTriggerAction) {
		l_pair.second.clear();
		gd::vector<CountTriggerAction>().swap(l_pair.second);
	}

	m_vectorTouchToggleAction.clear();
	gd::vector<TouchToggleAction>().swap(m_vectorTouchToggleAction);

	m_vectorCollisionTriggerAction.clear();
	gd::vector<CollisionTriggerAction>().swap(m_vectorCollisionTriggerAction);

	m_vectorToggleTriggerAction.clear();
	gd::vector<ToggleTriggerAction>().swap(m_vectorToggleTriggerAction);

	m_vectorSpawnTriggerAction.clear();
	gd::vector<SpawnTriggerAction>().swap(m_vectorSpawnTriggerAction);

	m_vectorGroupCommandObject2.clear();
	gd::vector<GroupCommandObject2>().swap(m_vectorGroupCommandObject2);

	for (std::pair<int, gd::vector<TimerTriggerAction>> l_pair : m_unorderedMapInt_vectorTimerTriggerAction) {
		l_pair.second.clear();
		gd::vector<TimerTriggerAction>().swap(l_pair.second);
	}
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAEffectManagerState::describe() {
	int l_size = m_unkVecCAState.size();
	log::info("[PAEffectManagerState - describe] m_unkVecCAState.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEffectManagerState - describe] m_unkVecCAState[{}]:", i);
		reinterpret_cast<PACAState*>(&m_unkVecCAState[i])->describe();
	}
	l_size = m_unkVecPulseEffectAction.size();
	log::info("[PAEffectManagerState - describe] m_unkVecPulseEffectAction.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEffectManagerState - describe] m_unkVecPulseEffectAction[{}]: {}", i, hexStr(reinterpret_cast<uint8_t*>(&m_unkVecPulseEffectAction[i]), sizeof(PulseEffectAction)));
	}
	l_size = m_unorderedMapInt_vectorPulseEffectAction.size();
	log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorPulseEffectAction.size(): {}", l_size);
	int i = 0;
	for (std::pair<int, gd::vector<PulseEffectAction>> l_pair : m_unorderedMapInt_vectorPulseEffectAction) {
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorPulseEffectAction element {} key: {}", i, l_pair.first);
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorPulseEffectAction element {} value:", i);
		l_size = l_pair.second.size();
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorPulseEffectAction element {} value.size(): {}", i, l_size);
		for (int j = 0; j < l_size; j++) {
			log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorPulseEffectAction element {} value[{}]: {}", i, j, hexStr(reinterpret_cast<uint8_t*>(&l_pair.second[j]), sizeof(PulseEffectAction)));
		}
		i++;
	}
	i = 0;
	for (std::pair<int, gd::vector<CountTriggerAction>> l_pair : m_unorderedMapInt_vectorCountTriggerAction) {
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorCountTriggerAction element {} key: {}", i, l_pair.first);
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorCountTriggerAction element {} value:", i);
		l_size = l_pair.second.size();
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorCountTriggerAction element {} value.size(): {}", i, l_size);
		for (int j = 0; j < l_size; j++) {
			log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorCountTriggerAction element {} value[{}]:", i, j);
			reinterpret_cast<PACountTriggerAction*>(&l_pair.second[j])->describe();
		}
		i++;
	}
	i = 0;
	for (int l_value : m_unorderedSet_int1) {
		log::info("[PAEffectManagerState - describe] m_unorderedSet_int1 element {} value: {}", i, l_value);
		i++;
	}
	i = 0;
	for (std::pair<int, int> l_pair : m_mapInt_Int) {
		log::info("[PAEffectManagerState - describe] m_mapInt_Int element {} key: {}", i, l_pair.first);
		log::info("[PAEffectManagerState - describe] m_mapInt_Int element {} value: {}", i, l_pair.second);
		i++;
	}
	l_size = m_unorderedMapInt_OpacityEffectAction.size();
	log::info("[PAEffectManagerState - describe] m_unorderedMapInt_OpacityEffectAction.size(): {}", l_size);
	i = 0;
	for (std::pair<int, OpacityEffectAction> l_pair : m_unorderedMapInt_OpacityEffectAction) {
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_OpacityEffectAction element {} key: {}", i, l_pair.first);
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_OpacityEffectAction element {} value: {}", i, hexStr(reinterpret_cast<uint8_t*>(&l_pair.second), sizeof(OpacityEffectAction)));
		i++;
	}
	l_size = m_vectorTouchToggleAction.size();
	log::info("[PAEffectManagerState - describe] m_vectorTouchToggleAction.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEffectManagerState - describe] m_vectorTouchToggleAction[{}]:", i);
		reinterpret_cast<PATouchToggleAction*>(&m_vectorTouchToggleAction[i])->describe();
	}
	l_size = m_vectorCollisionTriggerAction.size();
	log::info("[PAEffectManagerState - describe] m_vectorCollisionTriggerAction.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEffectManagerState - describe] m_vectorCollisionTriggerAction[{}]:", i);
		reinterpret_cast<PACollisionTriggerAction*>(&m_vectorCollisionTriggerAction[i])->describe();
	}
	l_size = m_vectorToggleTriggerAction.size();
	log::info("[PAEffectManagerState - describe] m_vectorToggleTriggerAction.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEffectManagerState - describe] m_vectorToggleTriggerAction[{}]:", i);
		reinterpret_cast<PAToggleTriggerAction*>(&m_vectorToggleTriggerAction[i])->describe();
	}
	l_size = m_vectorSpawnTriggerAction.size();
	log::info("[PAEffectManagerState - describe] m_vectorSpawnTriggerAction.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEffectManagerState - describe] m_vectorSpawnTriggerAction[{}]:", i);
		reinterpret_cast<PASpawnTriggerAction*>(&m_vectorSpawnTriggerAction[i])->describe();
	}
	i = 0;
	for (std::pair<int, int> l_pair : m_unorderedMapInt_int) {
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_int element {} key: {}", i, l_pair.first);
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_int element {} value: {}", i, l_pair.second);
		i++;
	}
	i = 0;
	for (std::pair<int, bool> l_pair : m_unorderedMapInt_bool) {
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_bool element {} key: {}", i, l_pair.first);
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_bool element {} value: {}", i, l_pair.second);
		i++;
	}
	l_size = m_vectorGroupCommandObject2.size();
	log::info("[PAEffectManagerState - describe] m_vectorGroupCommandObject2.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEffectManagerState - describe] m_vectorGroupCommandObject2[{}]:", i);
		reinterpret_cast<PAGroupCommandObject2*>(&m_vectorGroupCommandObject2[i])->describe();
	}
	i = 0;
	for (std::pair<int, std::pair<double,double>> l_pair : m_unorderedMapInt_pair_double_double) {
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_pair_double_double element {} key: {}", i, l_pair.first);
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_pair_double_double element {} value: {}", i, l_pair.second);
		i++;
	}
	i = 0;
	for (int l_value : m_unorderedSet_int2) {
		log::info("[PAEffectManagerState - describe] m_unorderedSet_int2 element {} value: {}", i, l_value);
		i++;
	}
	l_size = m_unorderedMapInt_TimerItem.size();
	log::info("[PAEffectManagerState - describe] m_unorderedMapInt_TimerItem.size(): {}", l_size);
	i = 0;
	for (std::pair<int, TimerItem> l_pair : m_unorderedMapInt_TimerItem) {
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_TimerItem element {} key: {}", i, l_pair.first);
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_TimerItem element {} value:", i);
		reinterpret_cast<PATimerItem*>(&l_pair.second)->describe();
		i++;
	}
	i = 0;
	for (std::pair<int, gd::vector<TimerTriggerAction>> l_pair : m_unorderedMapInt_vectorTimerTriggerAction) {
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorTimerTriggerAction element {} key: {}", i, l_pair.first);
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorTimerTriggerAction element {} value:", i);
		l_size = l_pair.second.size();
		log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorTimerTriggerAction element {} value.size(): {}", i, l_size);
		for (int j = 0; j < l_size; j++) {
			log::info("[PAEffectManagerState - describe] m_unorderedMapInt_vectorTimerTriggerAction element {} value[{}]:", i, j);
			reinterpret_cast<PATimerTriggerAction*>(&l_pair.second[j])->describe();
		}
		i++;
	}
}
#endif