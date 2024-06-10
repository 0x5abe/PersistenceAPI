#include "hooks/GroupCommandObject2.hpp"
#include "Geode/binding/KeyframeObject.hpp"
#include "hooks/KeyframeObject.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistencyUtils;

void PUGroupCommandObject2::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUGroupCommandObject2::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistencyUtils::operator>>(InputStream& i_stream, PUGroupCommandObject2& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 440);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecKeyframeObject;
	VEC_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUGroupCommandObject2,m_unkVecKeyframeObject) + sizeof(gd::vector<KeyframeObject>), 24);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUGroupCommandObject2,m_unkVecInt) + sizeof(gd::vector<int>), 8);
	SEPARATOR_I
}

inline void persistencyUtils::operator<<(OutputStream& o_stream, PUGroupCommandObject2& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 440);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecKeyframeObject;
	VEC_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUGroupCommandObject2,m_unkVecKeyframeObject) + sizeof(gd::vector<KeyframeObject>), 24);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUGroupCommandObject2,m_unkVecInt) + sizeof(gd::vector<int>), 8);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUGroupCommandObject2::describe() {
	log::info("[PUGroupCommandObject2 - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 440));
	int l_size = m_unkVecKeyframeObject.size();
	log::info("[PUGroupCommandObject2 - describe] m_unkVecKeyframeObject.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PUGroupCommandObject2 - describe] m_unkVecKeyframeObject[{}]:", i);
		reinterpret_cast<PUKeyframeObject*>(&m_unkVecKeyframeObject[i])->describe();
	}
	log::info("[PUGroupCommandObject2 - describe] pad_2: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUGroupCommandObject2,m_unkVecKeyframeObject) + sizeof(gd::vector<KeyframeObject>), 24));
	l_size = m_unkVecInt.size();
	log::info("[PUGroupCommandObject2 - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PUGroupCommandObject2 - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
	log::info("[PUGroupCommandObject2 - describe] pad_3: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUGroupCommandObject2,m_unkVecInt) + sizeof(gd::vector<int>), 8));
}
#endif