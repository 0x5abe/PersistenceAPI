#include "hooks/FMODSoundTween.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAFMODSoundTween::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAFMODSoundTween::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAFMODSoundTween& o_value) {
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_unkDouble1;
		SEPARATOR_I;
		i_stream >> o_value.m_unkDouble2;
		SEPARATOR_I;
		i_stream >> o_value.m_unkDouble3;
		SEPARATOR_I;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value), 40);
	}
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAFMODSoundTween& i_value) {
	o_stream << i_value.m_unkDouble1;
	SEPARATOR_O;
	o_stream << i_value.m_unkDouble2;
	SEPARATOR_O;
	o_stream << i_value.m_unkDouble3;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAFMODSoundTween::describe() {
	log::info("[PAFMODSoundTween - describe] m_unkDouble1: {}", m_unkDouble1);
	log::info("[PAFMODSoundTween - describe] m_unkDouble2: {}", m_unkDouble2);
	log::info("[PAFMODSoundTween - describe] m_unkDouble3: {}", m_unkDouble3);
}
#endif