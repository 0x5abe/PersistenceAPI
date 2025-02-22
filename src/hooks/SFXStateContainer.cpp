#include "hooks/SFXStateContainer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASFXStateContainer::load(Stream& i_stream) {
	i_stream >> *this;
}

void PASFXStateContainer::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASFXStateContainer& o_value) {
	i_stream >> o_value.m_unkDouble1;
	SEPARATOR_I
	i_stream >> o_value.m_unkDouble2;
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat1;
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat2;
	SEPARATOR_I
	i_stream >> o_value.m_unkBool;
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASFXStateContainer& i_value) {
	o_stream << i_value.m_unkDouble1;
	SEPARATOR_O
	o_stream << i_value.m_unkDouble2;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat1;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat2;
	SEPARATOR_O
	o_stream << i_value.m_unkBool;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASFXStateContainer::describe() {
	log::info("[PASFXStateContainer - describe] m_unkDouble1: {}", m_unkDouble1);
	log::info("[PASFXStateContainer - describe] m_unkDouble2: {}", m_unkDouble2);
	log::info("[PASFXStateContainer - describe] m_unkFloat1: {}", m_unkFloat1);
	log::info("[PASFXStateContainer - describe] m_unkFloat2: {}", m_unkFloat2);
	log::info("[PASFXStateContainer - describe] m_unkBool: {}", m_unkBool);
}
#endif