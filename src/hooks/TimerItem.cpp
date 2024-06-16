#include "hooks/TimerItem.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

void PUTimerItem::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUTimerItem::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceUtils::operator>>(InputStream& i_stream, PUTimerItem& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 56);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUTimerItem,m_unkVecInt) + sizeof(gd::vector<int>), 4);
	SEPARATOR_I
}

inline void persistenceUtils::operator<<(OutputStream& o_stream, PUTimerItem& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 56);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUTimerItem,m_unkVecInt) + sizeof(gd::vector<int>), 4);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUTimerItem::describe() {
	log::info("[PUTimerItem - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 56));
	int l_size = m_unkVecInt.size();
	log::info("[PUTimerItem - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PUTimerItem - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
	log::info("[PUTimerItem - describe] pad_2: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUTimerItem,m_unkVecInt) + sizeof(gd::vector<int>), 4));
}
#endif