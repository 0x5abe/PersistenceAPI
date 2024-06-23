#include "hooks/GroupCommandObject2.hpp"
#include "Geode/binding/KeyframeObject.hpp"
#include "hooks/KeyframeObject.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAGroupCommandObject2::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PAGroupCommandObject2::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PAGroupCommandObject2& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 440);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecKeyframeObject;
	VEC_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAGroupCommandObject2,m_unkVecKeyframeObject) + sizeof(gd::vector<KeyframeObject>), 24);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAGroupCommandObject2,m_unkVecInt) + sizeof(gd::vector<int>), 8);
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PAGroupCommandObject2& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 440);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecKeyframeObject;
	VEC_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PAGroupCommandObject2,m_unkVecKeyframeObject) + sizeof(gd::vector<KeyframeObject>), 24);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PAGroupCommandObject2,m_unkVecInt) + sizeof(gd::vector<int>), 8);
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAGroupCommandObject2::describe() {
	log::info("[PAGroupCommandObject2 - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 440));
	int l_size = m_unkVecKeyframeObject.size();
	log::info("[PAGroupCommandObject2 - describe] m_unkVecKeyframeObject.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAGroupCommandObject2 - describe] m_unkVecKeyframeObject[{}]:", i);
		reinterpret_cast<PAKeyframeObject*>(&m_unkVecKeyframeObject[i])->describe();
	}
	log::info("[PAGroupCommandObject2 - describe] pad_2: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PAGroupCommandObject2,m_unkVecKeyframeObject) + sizeof(gd::vector<KeyframeObject>), 24));
	l_size = m_unkVecInt.size();
	log::info("[PAGroupCommandObject2 - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAGroupCommandObject2 - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
	log::info("[PAGroupCommandObject2 - describe] pad_3: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PAGroupCommandObject2,m_unkVecInt) + sizeof(gd::vector<int>), 8));
}
#endif