#include "hooks/EnterEffectAnimValue.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAEnterEffectAnimValue::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAEnterEffectAnimValue::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAEnterEffectAnimValue& o_value) {
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_key;
		SEPARATOR_I;
		i_stream >> o_value.m_value;
		SEPARATOR_I;
		i_stream >> o_value.m_distance;
		SEPARATOR_I;
		i_stream >> o_value.m_duration;
		SEPARATOR_I;
		i_stream >> o_value.m_elapsed;
		SEPARATOR_I;
		i_stream >> o_value.m_easingType;
		SEPARATOR_I;
		i_stream >> o_value.m_easingRate;
		SEPARATOR_I;
		i_stream >> o_value.m_easingBuffer;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value), sizeof(EnterEffectAnimValue));
	}
	SEPARATOR_I;
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAEnterEffectAnimValue& i_value) {
	o_stream << i_value.m_key;
	SEPARATOR_O;
	o_stream << i_value.m_value;
	SEPARATOR_O;
	o_stream << i_value.m_distance;
	SEPARATOR_O;
	o_stream << i_value.m_duration;
	SEPARATOR_O;
	o_stream << i_value.m_elapsed;
	SEPARATOR_O;
	o_stream << i_value.m_easingType;
	SEPARATOR_O;
	o_stream << i_value.m_easingRate;
	SEPARATOR_O;
	o_stream << i_value.m_easingBuffer;
	SEPARATOR_O;
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAEnterEffectAnimValue::describe() {
	log::info("[PAEnterEffectAnimValue - describe] m_key: {}", m_key);
	log::info("[PAEnterEffectAnimValue - describe] m_value: {}", m_value);
	log::info("[PAEnterEffectAnimValue - describe] m_distance: {}", m_distance);
	log::info("[PAEnterEffectAnimValue - describe] m_duration: {}", m_duration);
	log::info("[PAEnterEffectAnimValue - describe] m_elapsed: {}", m_elapsed);
	log::info("[PAEnterEffectAnimValue - describe] m_easingType: {}", *reinterpret_cast<int*>(&m_easingType));
	log::info("[PAEnterEffectAnimValue - describe] m_easingRate: {}", m_easingRate);
	log::info("[PAEnterEffectAnimValue - describe] m_easingBuffer: {}", m_easingBuffer);
}
#endif