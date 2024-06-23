#include "hooks/EventTriggerInstance.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAEventTriggerInstance::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PAEventTriggerInstance::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PAEventTriggerInstance& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 16);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PAEventTriggerInstance& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 16);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAEventTriggerInstance::describe() {
	log::info("[PAEventTriggerInstance - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 16));
	int l_size = m_unkVecInt.size();
	log::info("[PAEventTriggerInstance - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEventTriggerInstance - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
}
#endif