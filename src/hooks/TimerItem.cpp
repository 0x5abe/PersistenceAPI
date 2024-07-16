#include "hooks/TimerItem.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PATimerItem::load(Stream& i_stream) {
	i_stream >> *this;
}

void PATimerItem::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PATimerItem& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 56);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PATimerItem,m_unkVecInt) + sizeof(gd::vector<int>), 4);
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PATimerItem& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 56);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PATimerItem,m_unkVecInt) + sizeof(gd::vector<int>), 4);
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PATimerItem::describe() {
	log::info("[PATimerItem - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 56));
	int l_size = m_unkVecInt.size();
	log::info("[PATimerItem - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PATimerItem - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
	log::info("[PATimerItem - describe] pad_2: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PATimerItem,m_unkVecInt) + sizeof(gd::vector<int>), 4));
}
#endif