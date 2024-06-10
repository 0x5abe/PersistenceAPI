#include "hooks/ToggleTriggerAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistencyUtils;

void PUToggleTriggerAction::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUToggleTriggerAction::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistencyUtils::operator>>(InputStream& i_stream, PUToggleTriggerAction& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 20);
	VEC_SEPARATOR_I
	int l_size = o_value.m_unkVecInt.size();
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
}

inline void persistencyUtils::operator<<(OutputStream& o_stream, PUToggleTriggerAction& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 20);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUToggleTriggerAction::describe() {
	log::info("[PUToggleTriggerAction - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 20));
	int l_size = m_unkVecInt.size();
	log::info("[PUToggleTriggerAction - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PUToggleTriggerAction - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
}
#endif