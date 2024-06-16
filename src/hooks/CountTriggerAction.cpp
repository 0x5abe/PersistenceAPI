#include "hooks/CountTriggerAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

void PUCountTriggerAction::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUCountTriggerAction::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceUtils::operator>>(InputStream& i_stream, PUCountTriggerAction& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 36);
	VEC_SEPARATOR_I
	int l_size = o_value.m_unkVecInt.size();
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
}

inline void persistenceUtils::operator<<(OutputStream& o_stream, PUCountTriggerAction& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 36);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUCountTriggerAction::describe() {
	log::info("[PUCountTriggerAction - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 36));
	int l_size = m_unkVecInt.size();
	log::info("[PUCountTriggerAction - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PUCountTriggerAction - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
}   
#endif