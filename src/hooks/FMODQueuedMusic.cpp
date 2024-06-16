#include "hooks/FMODQueuedMusic.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

void PUFMODQueuedMusic::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUFMODQueuedMusic::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceUtils::operator>>(InputStream& i_stream, PUFMODQueuedMusic& o_value) {
	STR_SEPARATOR_I
	i_stream >> o_value.m_unkString;
	STR_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUFMODQueuedMusic,m_unkString) + sizeof(gd::string), 56);
	SEPARATOR_I
}

inline void persistenceUtils::operator<<(OutputStream& o_stream, PUFMODQueuedMusic& i_value) {
	STR_SEPARATOR_O
	o_stream << i_value.m_unkString;
	STR_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUFMODQueuedMusic,m_unkString) + sizeof(gd::string), 56);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUFMODQueuedMusic::describe() {
	log::info("[PUFMODQueuedMusic - describe] m_unkString: {}", m_unkString);
	log::info("[PUFMODQueuedMusic - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUFMODQueuedMusic,m_unkString) + sizeof(gd::string), 56));
}
#endif