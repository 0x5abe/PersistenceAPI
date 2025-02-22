#include "hooks/GJValueTween.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAGJValueTween::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAGJValueTween::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAGJValueTween& o_value) {
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_fromValue;
		SEPARATOR_I;
		i_stream >> o_value.m_toValue;
		SEPARATOR_I;
		i_stream >> o_value.m_duration;
		SEPARATOR_I;
		i_stream >> o_value.m_deltaTime;
		SEPARATOR_I;
		i_stream >> o_value.m_currentValue;
		SEPARATOR_I;
		i_stream >> o_value.m_easingType;
		SEPARATOR_I;
		i_stream >> o_value.m_easingRate;
		SEPARATOR_I;
		i_stream >> o_value.m_finished;
		SEPARATOR_I;
		i_stream >> o_value.m_disabled;
		SEPARATOR_I;
		i_stream >> o_value.m_unkInt1;
		SEPARATOR_I;
		i_stream >> o_value.m_unkInt2;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value), sizeof(GJValueTween));
	}
	SEPARATOR_I;
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAGJValueTween& i_value) {
	o_stream << i_value.m_fromValue;
	SEPARATOR_O;
	o_stream << i_value.m_toValue;
	SEPARATOR_O;
	o_stream << i_value.m_duration;
	SEPARATOR_O;
	o_stream << i_value.m_deltaTime;
	SEPARATOR_O;
	o_stream << i_value.m_currentValue;
	SEPARATOR_O;
	o_stream << i_value.m_easingType;
	SEPARATOR_O;
	o_stream << i_value.m_easingRate;
	SEPARATOR_O;
	o_stream << i_value.m_finished;
	SEPARATOR_O;
	o_stream << i_value.m_disabled;
	SEPARATOR_O;
	o_stream << i_value.m_unkInt1;
	SEPARATOR_O;
	o_stream << i_value.m_unkInt2;
	SEPARATOR_O;
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAGJValueTween::describe() {
	log::info("[PAGJValueTween - describe] m_fromValue: {}", m_fromValue);
	log::info("[PAGJValueTween - describe] m_toValue: {}", m_toValue);
	log::info("[PAGJValueTween - describe] m_duration: {}", m_duration);
	log::info("[PAGJValueTween - describe] m_deltaTime: {}", m_deltaTime);
	log::info("[PAGJValueTween - describe] m_currentValue: {}", m_currentValue);
	log::info("[PAGJValueTween - describe] m_easingType: {}", *reinterpret_cast<int*>(&m_easingType));
	log::info("[PAGJValueTween - describe] m_easingRate: {}", m_easingRate);
	log::info("[PAGJValueTween - describe] m_finished: {}", m_finished);
	log::info("[PAGJValueTween - describe] m_disabled: {}", m_disabled);
	log::info("[PAGJValueTween - describe] m_unkInt1: {}", m_unkInt1);
	log::info("[PAGJValueTween - describe] m_unkInt2: {}", m_unkInt2);
}
#endif