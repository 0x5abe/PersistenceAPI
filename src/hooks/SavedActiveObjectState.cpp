#include "hooks/SavedActiveObjectState.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASavedActiveObjectState::load(Stream& i_stream) {
	i_stream >> *this;
}

void PASavedActiveObjectState::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASavedActiveObjectState& o_value) {
	i_stream >> o_value.m_gameObject;
	SEPARATOR_I
	i_stream >> o_value.m_unkBool1;
	SEPARATOR_I
	i_stream >> o_value.m_unkBool2;
	SEPARATOR_I_END
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASavedActiveObjectState& i_value) {
	o_stream << i_value.m_gameObject;
	SEPARATOR_O
	o_stream << i_value.m_unkBool1;
	SEPARATOR_O
	o_stream << i_value.m_unkBool2;
	SEPARATOR_O_END
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASavedActiveObjectState::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PASavedActiveObjectState - describe] l_objectIndex: {}", l_objectIndex);
	log::info("[PASavedActiveObjectState - describe] m_unkBool1: {}", m_unkBool1);
	log::info("[PASavedActiveObjectState - describe] m_unkBool2: {}", m_unkBool2);
}
#endif