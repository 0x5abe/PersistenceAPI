#include "hooks/KeyframeObject.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/tk_spline.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAKeyframeObject::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAKeyframeObject::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAKeyframeObject& o_value) {
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_unk000;
		SEPARATOR_I
    	i_stream >> o_value.m_unk008;
		SEPARATOR_I
    	i_stream >> o_value.m_unk00c;
		SEPARATOR_I
    	i_stream >> o_value.m_unk010;
		SEPARATOR_I
    	i_stream >> o_value.m_unk014;
		SEPARATOR_I
    	i_stream >> o_value.m_unk018;
		SEPARATOR_I
    	i_stream >> o_value.m_unk01c;
		SEPARATOR_I
    	i_stream >> o_value.m_unk01d;
		SEPARATOR_I
    	i_stream >> o_value.m_unk01e;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value), 32);
	}
	VEC_SEPARATOR_I
	if (i_stream.getPAVersion() > 1) {
		reinterpret_cast<PAtk_spline*>(&o_value.m_spline1)->load(i_stream);
		VEC_SEPARATOR_I
		reinterpret_cast<PAtk_spline*>(&o_value.m_spline2)->load(i_stream);
		i_stream >> o_value.m_unk170;
		SEPARATOR_I
		i_stream >> o_value.m_unk178;
		SEPARATOR_I
		i_stream >> o_value.m_unk180;
		SEPARATOR_I
		i_stream >> o_value.m_unk184;
		SEPARATOR_I
		i_stream >> o_value.m_unk188;
		SEPARATOR_I
		i_stream >> o_value.m_unk190;
		SEPARATOR_I
		i_stream >> o_value.m_unk198;
		SEPARATOR_I
		i_stream >> o_value.m_unk1a0;
		SEPARATOR_I
		i_stream >> o_value.m_unk1a8;
		SEPARATOR_I
		i_stream >> o_value.m_unk1b0;
		SEPARATOR_I
		i_stream >> o_value.m_unk1b8;
	} else {
		i_stream >> o_value.m_spline1.m_x;
		VEC_SEPARATOR_I
		i_stream >> o_value.m_spline1.m_y;
		VEC_SEPARATOR_I
		i_stream >> o_value.m_spline1.m_b;
		VEC_SEPARATOR_I
		i_stream >> o_value.m_spline1.m_c;
		VEC_SEPARATOR_I
		i_stream >> o_value.m_spline1.m_d;
		VEC_SEPARATOR_I
		SEPARATOR_I
		i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAKeyframeObject,m_spline1) + sizeof(gd::vector<double>)*5, 41);
		SEPARATOR_I
		VEC_SEPARATOR_I
		i_stream >> o_value.m_spline2.m_x;
		VEC_SEPARATOR_I
		i_stream >> o_value.m_spline2.m_y;
		VEC_SEPARATOR_I
		i_stream >> o_value.m_spline2.m_b;
		VEC_SEPARATOR_I
		i_stream >> o_value.m_spline2.m_c;
		VEC_SEPARATOR_I
		i_stream >> o_value.m_spline2.m_d;
		VEC_SEPARATOR_I
		SEPARATOR_I
		i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAKeyframeObject,m_spline2) + sizeof(gd::vector<double>)*5, 128);
	}
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAKeyframeObject& i_value) {
	o_stream << i_value.m_unk000;
	SEPARATOR_O
    o_stream << i_value.m_unk008;
	SEPARATOR_O
    o_stream << i_value.m_unk00c;
	SEPARATOR_O
    o_stream << i_value.m_unk010;
	SEPARATOR_O
    o_stream << i_value.m_unk014;
	SEPARATOR_O
    o_stream << i_value.m_unk018;
	SEPARATOR_O
    o_stream << i_value.m_unk01c;
	SEPARATOR_O
    o_stream << i_value.m_unk01d;
	SEPARATOR_O
    o_stream << i_value.m_unk01e;
	VEC_SEPARATOR_O
	reinterpret_cast<PAtk_spline*>(&i_value.m_spline1)->save(o_stream);
	VEC_SEPARATOR_O
	reinterpret_cast<PAtk_spline*>(&i_value.m_spline2)->save(o_stream);
	o_stream << i_value.m_unk170;
	SEPARATOR_O
	o_stream << i_value.m_unk178;
	SEPARATOR_O
	o_stream << i_value.m_unk180;
	SEPARATOR_O
	o_stream << i_value.m_unk184;
	SEPARATOR_O
	o_stream << i_value.m_unk188;
	SEPARATOR_O
	o_stream << i_value.m_unk190;
	SEPARATOR_O
	o_stream << i_value.m_unk198;
	SEPARATOR_O
	o_stream << i_value.m_unk1a0;
	SEPARATOR_O
	o_stream << i_value.m_unk1a8;
	SEPARATOR_O
	o_stream << i_value.m_unk1b0;
	SEPARATOR_O
	o_stream << i_value.m_unk1b8;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAKeyframeObject::describe() {
	log::info("[PAKeyframeObject - describe] m_unk000: {}", m_unk000);
	log::info("[PAKeyframeObject - describe] m_unk008: {}", m_unk008);
	log::info("[PAKeyframeObject - describe] m_unk00c: {}", m_unk00c);
	log::info("[PAKeyframeObject - describe] m_unk010: {}", m_unk010);
	log::info("[PAKeyframeObject - describe] m_unk014: {}", m_unk014);
	log::info("[PAKeyframeObject - describe] m_unk018: {}", m_unk018);
	log::info("[PAKeyframeObject - describe] m_unk01c: {}", m_unk01c);
	log::info("[PAKeyframeObject - describe] m_unk01d: {}", m_unk01d);
	log::info("[PAKeyframeObject - describe] m_unk01e: {}", m_unk01e);
	reinterpret_cast<PAtk_spline*>(&m_spline1)->describe();
	reinterpret_cast<PAtk_spline*>(&m_spline2)->describe();
	log::info("[PAKeyframeObject - describe] m_unk170: {}", m_unk170);
	log::info("[PAKeyframeObject - describe] m_unk178: {}", m_unk178);
	log::info("[PAKeyframeObject - describe] m_unk180: {}", m_unk180);
	log::info("[PAKeyframeObject - describe] m_unk184: {}", m_unk184);
	log::info("[PAKeyframeObject - describe] m_unk188: {}", m_unk188);
	log::info("[PAKeyframeObject - describe] m_unk190: {}", m_unk190);
	log::info("[PAKeyframeObject - describe] m_unk198: {}", m_unk198);
	log::info("[PAKeyframeObject - describe] m_unk1a0: {}", m_unk1a0);
	log::info("[PAKeyframeObject - describe] m_unk1a8: {}", m_unk1a8);
	log::info("[PAKeyframeObject - describe] m_unk1b0: {}", m_unk1b0);
	log::info("[PAKeyframeObject - describe] m_unk1b8: {}", m_unk1b8);
}
#endif