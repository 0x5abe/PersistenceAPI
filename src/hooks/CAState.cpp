#include "hooks/CAState.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PACAState::load(Stream& i_stream) {
	i_stream >> *this;
}

void PACAState::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PACAState& o_value) {
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_fromColor;
		SEPARATOR_I
		i_stream >> o_value.m_toColor;
		SEPARATOR_I
		i_stream >> o_value.m_color;
		SEPARATOR_I
		i_stream >> o_value.m_property19;
		SEPARATOR_I
		i_stream >> o_value.m_blending;
		SEPARATOR_I
		i_stream >> o_value.m_copyOpacity;
		SEPARATOR_I
		i_stream >> o_value.m_unknown;
		SEPARATOR_I
		i_stream >> o_value.m_playerColor;
		SEPARATOR_I
		i_stream >> o_value.m_colorID;
		SEPARATOR_I
		i_stream >> o_value.m_copyID;
		SEPARATOR_I
		i_stream >> o_value.m_unknown2;
		SEPARATOR_I
		i_stream >> o_value.m_duration;
		SEPARATOR_I
		i_stream >> o_value.m_fromOpacity;
		SEPARATOR_I
		i_stream >> o_value.m_toOpacity;
		SEPARATOR_I
		i_stream >> o_value.m_deltaTime;
		SEPARATOR_I
		i_stream >> o_value.m_unknown3;
		SEPARATOR_I
		i_stream >> o_value.m_copyHSV;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value), 68);
	}
	SEPARATOR_I;
}

inline void persistenceAPI::operator<<(Stream& o_stream, PACAState& i_value) {
	o_stream << i_value.m_fromColor;
	SEPARATOR_O
	o_stream << i_value.m_toColor;
	SEPARATOR_O
	o_stream << i_value.m_color;
	SEPARATOR_O
	o_stream << i_value.m_property19;
	SEPARATOR_O
	o_stream << i_value.m_blending;
	SEPARATOR_O
	o_stream << i_value.m_copyOpacity;
	SEPARATOR_O
	o_stream << i_value.m_unknown;
	SEPARATOR_O
	o_stream << i_value.m_playerColor;
	SEPARATOR_O
	o_stream << i_value.m_colorID;
	SEPARATOR_O
	o_stream << i_value.m_copyID;
	SEPARATOR_O
	o_stream << i_value.m_unknown2;
	SEPARATOR_O
	o_stream << i_value.m_duration;
	SEPARATOR_O
	o_stream << i_value.m_fromOpacity;
	SEPARATOR_O
	o_stream << i_value.m_toOpacity;
	SEPARATOR_O
	o_stream << i_value.m_deltaTime;
	SEPARATOR_O
	o_stream << i_value.m_unknown3;
	SEPARATOR_O
	o_stream << i_value.m_copyHSV;
	SEPARATOR_O;
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PACAState::describe() {
	log::info("[PACAState - describe] m_fromColor: {}", m_fromColor);
	log::info("[PACAState - describe] m_toColor: {}", m_toColor);
	log::info("[PACAState - describe] m_color: {}", m_color);
	log::info("[PACAState - describe] m_property19: {}", m_property19);
	log::info("[PACAState - describe] m_blending: {}", m_blending);
	log::info("[PACAState - describe] m_copyOpacity: {}", m_copyOpacity);
	log::info("[PACAState - describe] m_unknown: {}", m_unknown);
	log::info("[PACAState - describe] m_playerColor: {}", m_playerColor);
	log::info("[PACAState - describe] m_colorID: {}", m_colorID);
	log::info("[PACAState - describe] m_copyID: {}", m_copyID);
	log::info("[PACAState - describe] m_unknown2: {}", m_unknown2);
	log::info("[PACAState - describe] m_duration: {}", m_duration);
	log::info("[PACAState - describe] m_fromOpacity: {}", m_fromOpacity);
	log::info("[PACAState - describe] m_toOpacity: {}", m_toOpacity);
	log::info("[PACAState - describe] m_deltaTime: {}", m_deltaTime);
	log::info("[PACAState - describe] m_unknown3: {}", m_unknown3);
	log::info("[PACAState - describe] m_copyHSV.h: {}", m_copyHSV.h);
	log::info("[PACAState - describe] m_copyHSV.s: {}", m_copyHSV.s);
	log::info("[PACAState - describe] m_copyHSV.v: {}", m_copyHSV.v);
	log::info("[PACAState - describe] m_copyHSV.absoluteSaturation: {}", m_copyHSV.absoluteSaturation);
	log::info("[PACAState - describe] m_copyHSV.absoluteBrightness: {}", m_copyHSV.absoluteBrightness);
}
#endif