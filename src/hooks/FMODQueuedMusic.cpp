#include "hooks/FMODQueuedMusic.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAFMODQueuedMusic::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PAFMODQueuedMusic::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PAFMODQueuedMusic& o_value) {
	STR_SEPARATOR_I
	i_stream >> o_value.m_unkString;
	STR_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAFMODQueuedMusic,m_unkString) + sizeof(gd::string), 56);
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PAFMODQueuedMusic& i_value) {
	STR_SEPARATOR_O
	o_stream << i_value.m_unkString;
	STR_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PAFMODQueuedMusic,m_unkString) + sizeof(gd::string), 56);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PAFMODQueuedMusic::describe() {
	log::info("[PAFMODQueuedMusic - describe] m_unkString: {}", m_unkString);
	log::info("[PAFMODQueuedMusic - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PAFMODQueuedMusic,m_unkString) + sizeof(gd::string), 56));
}
#endif