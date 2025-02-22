#include "hooks/SavedSpecialObjectState.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASavedSpecialObjectState::load(Stream& i_stream) {
	i_stream >> *this;
}

void PASavedSpecialObjectState::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASavedSpecialObjectState& o_value) {
	i_stream >> o_value.m_gameObject;
	SEPARATOR_I
	i_stream >> o_value.m_animationID;
	SEPARATOR_I_END
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASavedSpecialObjectState& i_value) {
	o_stream << i_value.m_gameObject;
	SEPARATOR_O
	o_stream << i_value.m_animationID;
	SEPARATOR_O_END
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASavedSpecialObjectState::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PASavedSpecialObjectState - describe] l_objectIndex: {}", l_objectIndex);
	log::info("[PASavedSpecialObjectState - describe] m_animationID: {}", m_animationID);
}
#endif