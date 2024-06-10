#include "hooks/CollisionTriggerAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistencyUtils;

void PUCollisionTriggerAction::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUCollisionTriggerAction::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistencyUtils::operator>>(InputStream& i_stream, PUCollisionTriggerAction& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 32);
	VEC_SEPARATOR_I
	int l_size = o_value.m_unkVecInt.size();
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
}

inline void persistencyUtils::operator<<(OutputStream& o_stream, PUCollisionTriggerAction& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 32);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUCollisionTriggerAction::describe() {
	log::info("[PUCollisionTriggerAction - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 32));
	int l_size = m_unkVecInt.size();
	log::info("[PUCollisionTriggerAction - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PUCollisionTriggerAction - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
}
#endif