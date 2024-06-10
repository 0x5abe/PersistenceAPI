#include "hooks/TouchToggleAction.hpp"
#include "Geode/loader/Log.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistencyUtils;

void PUTouchToggleAction::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUTouchToggleAction::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistencyUtils::operator>>(InputStream& i_stream, PUTouchToggleAction& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 32);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
}

inline void persistencyUtils::operator<<(OutputStream& o_stream, PUTouchToggleAction& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 32);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUTouchToggleAction::describe() {
	log::info("[PUTouchToggleAction - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 32));
	int l_size = m_unkVecInt.size();
	log::info("[PUTouchToggleAction - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PUTouchToggleAction - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
}
#endif