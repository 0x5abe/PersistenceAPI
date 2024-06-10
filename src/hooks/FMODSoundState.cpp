#include "hooks/FMODSoundState.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistencyUtils;

void PUFMODSoundState::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUFMODSoundState::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistencyUtils::operator>>(InputStream& i_stream, PUFMODSoundState& o_value) {
	STR_SEPARATOR_I
	i_stream >> o_value.m_unkString;
	STR_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUFMODSoundState,m_unkString) + sizeof(gd::string), 164);
	SEPARATOR_I
}

inline void persistencyUtils::operator<<(OutputStream& o_stream, PUFMODSoundState& i_value) {
	STR_SEPARATOR_O
	o_stream << i_value.m_unkString;
	STR_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUFMODSoundState,m_unkString) + sizeof(gd::string), 164);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUFMODSoundState::describe() {
	log::info("[PUFMODSoundState - describe] m_unkString: {}", m_unkString);
	log::info("[PUFMODSoundState - describe] pad_2: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUFMODSoundState,m_unkString) + sizeof(gd::string), 164));
}
#endif