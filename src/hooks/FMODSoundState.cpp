#include "hooks/FMODSoundState.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAFMODSoundState::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAFMODSoundState::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAFMODSoundState& o_value) {
	STR_SEPARATOR_I
	i_stream >> o_value.m_unkString;
	STR_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAFMODSoundState,m_unkString) + sizeof(gd::string), 156);
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAFMODSoundState& i_value) {
	STR_SEPARATOR_O
	o_stream << i_value.m_unkString;
	STR_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PAFMODSoundState,m_unkString) + sizeof(gd::string), 156);
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAFMODSoundState::describe() {
	log::info("[PAFMODSoundState - describe] m_unkString: {}", m_unkString);
	log::info("[PAFMODSoundState - describe] pad_2: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PAFMODSoundState,m_unkString) + sizeof(gd::string), 156));
}
#endif