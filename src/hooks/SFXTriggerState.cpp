#include "hooks/SFXTriggerState.hpp"
#include "hooks/SFXStateContainer.hpp"
#include "Geode/binding/SFXTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASFXTriggerState::load(Stream& i_stream) {
	i_stream >> *this;
}

void PASFXTriggerState::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASFXTriggerState& o_value) {
	i_stream >> o_value.m_sfxTriggerGameObject;
	SEPARATOR_I
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_unkInt1;
		SEPARATOR_I
		i_stream >> o_value.m_unkDouble1;
		SEPARATOR_I
		i_stream >> o_value.m_unkDouble2;
		SEPARATOR_I
		i_stream >> o_value.m_unkDouble3;
		SEPARATOR_I
		i_stream >> o_value.m_unkDouble4;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat1;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat2;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat3;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat4;
		SEPARATOR_I
		i_stream >> o_value.m_unkInt2;
		SEPARATOR_I
		i_stream >> o_value.m_processed;
		SEPARATOR_I
		i_stream >> o_value.m_unkBool1;
		SEPARATOR_I
		reinterpret_cast<PASFXStateContainer*>(&o_value.m_sfxStateContainers[0])->load(i_stream);
		SEPARATOR_I
		reinterpret_cast<PASFXStateContainer*>(&o_value.m_sfxStateContainers[1])->load(i_stream);
		SEPARATOR_I
		reinterpret_cast<PASFXStateContainer*>(&o_value.m_sfxStateContainers[2])->load(i_stream);
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PASFXTriggerState,m_sfxTriggerGameObject) + sizeof(SFXTriggerGameObject*), 160);
	}
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASFXTriggerState& i_value) {
	o_stream << i_value.m_sfxTriggerGameObject;
	SEPARATOR_O
	o_stream << i_value.m_unkInt1;
	SEPARATOR_O
	o_stream << i_value.m_unkDouble1;
	SEPARATOR_O
	o_stream << i_value.m_unkDouble2;
	SEPARATOR_O
	o_stream << i_value.m_unkDouble3;
	SEPARATOR_O
	o_stream << i_value.m_unkDouble4;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat1;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat2;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat3;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat4;
	SEPARATOR_O
	o_stream << i_value.m_unkInt2;
	SEPARATOR_O
	o_stream << i_value.m_processed;
	SEPARATOR_O
	o_stream << i_value.m_unkBool1;
	SEPARATOR_O
	reinterpret_cast<PASFXStateContainer*>(&i_value.m_sfxStateContainers[0])->save(o_stream);
	SEPARATOR_O
	reinterpret_cast<PASFXStateContainer*>(&i_value.m_sfxStateContainers[1])->save(o_stream);
	SEPARATOR_O
	reinterpret_cast<PASFXStateContainer*>(&i_value.m_sfxStateContainers[2])->save(o_stream);
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASFXTriggerState::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_sfxTriggerGameObject);
	log::info("[PASFXTriggerState - describe] m_sfxTriggerGameObject l_objectIndex: {}", l_objectIndex);
	log::info("[PASFXTriggerState - describe] m_unkInt1: {}", m_unkInt1);
	log::info("[PASFXTriggerState - describe] m_unkDouble1: {}", m_unkDouble1);
	log::info("[PASFXTriggerState - describe] m_unkDouble2: {}", m_unkDouble2);
	log::info("[PASFXTriggerState - describe] m_unkDouble3: {}", m_unkDouble3);
	log::info("[PASFXTriggerState - describe] m_unkDouble4: {}", m_unkDouble4);
	log::info("[PASFXTriggerState - describe] m_unkFloat1: {}", m_unkFloat1);
	log::info("[PASFXTriggerState - describe] m_unkFloat2: {}", m_unkFloat2);
	log::info("[PASFXTriggerState - describe] m_unkFloat3: {}", m_unkFloat3);
	log::info("[PASFXTriggerState - describe] m_unkFloat4: {}", m_unkFloat4);
	log::info("[PASFXTriggerState - describe] m_unkInt2: {}", m_unkInt2);
	log::info("[PASFXTriggerState - describe] m_processed: {}", m_processed);
	log::info("[PASFXTriggerState - describe] m_unkBool1: {}", m_unkBool1);
	reinterpret_cast<PASFXStateContainer*>(&m_sfxStateContainers[0])->describe();
	reinterpret_cast<PASFXStateContainer*>(&m_sfxStateContainers[1])->describe();
	reinterpret_cast<PASFXStateContainer*>(&m_sfxStateContainers[2])->describe();
}
#endif