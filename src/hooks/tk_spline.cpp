#include "hooks/tk_spline.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAtk_spline::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAtk_spline::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAtk_spline& o_value) {
	i_stream >> o_value.m_x;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_y;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_b;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_c;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_d;
	VEC_SEPARATOR_I
	SEPARATOR_I
	i_stream >> o_value.m_c0;
	SEPARATOR_I
	i_stream >> o_value.m_type;
	SEPARATOR_I
	i_stream >> o_value.m_left;
	SEPARATOR_I
	i_stream >> o_value.m_right;
	SEPARATOR_I
	i_stream >> o_value.m_leftValue;
	SEPARATOR_I
	i_stream >> o_value.m_rightValue;
	SEPARATOR_I
	i_stream >> o_value.m_madeMonotonic;
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAtk_spline& i_value) {
	o_stream << i_value.m_x;
	VEC_SEPARATOR_O
	o_stream << i_value.m_y;
	VEC_SEPARATOR_O
	o_stream << i_value.m_b;
	VEC_SEPARATOR_O
	o_stream << i_value.m_c;
	VEC_SEPARATOR_O
	o_stream << i_value.m_d;
	VEC_SEPARATOR_O
	SEPARATOR_O
	o_stream << i_value.m_c0;
	SEPARATOR_O
	o_stream << i_value.m_type;
	SEPARATOR_O
	o_stream << i_value.m_left;
	SEPARATOR_O
	o_stream << i_value.m_right;
	SEPARATOR_O
	o_stream << i_value.m_leftValue;
	SEPARATOR_O
	o_stream << i_value.m_rightValue;
	SEPARATOR_O
	o_stream << i_value.m_madeMonotonic;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAtk_spline::describe() {
	int l_size = m_x.size();
	log::info("[PAtk_spline - describe] m_x.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAtk_spline - describe] m_x[{}]: {}", i, m_x[i]);
	}
	l_size = m_y.size();
	log::info("[PAtk_spline - describe] m_y.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAtk_spline - describe] m_y[{}]: {}", i, m_y[i]);
	}
	l_size = m_b.size();
	log::info("[PAtk_spline - describe] m_b.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAtk_spline - describe] m_b[{}]: {}", i, m_b[i]);
	}
	l_size = m_c.size();
	log::info("[PAtk_spline - describe] m_c.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAtk_spline - describe] m_c[{}]: {}", i, m_c[i]);
	}
	l_size = m_d.size();
	log::info("[PAtk_spline - describe] m_d.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAtk_spline - describe] m_d[{}]: {}", i, m_d[i]);
	}
	log::info("[PAtk_spline - describe] m_c0: {}", m_c0);
	log::info("[PAtk_spline - describe] m_type: {}", m_type);
	log::info("[PAtk_spline - describe] m_left: {}", m_left);
	log::info("[PAtk_spline - describe] m_right: {}", m_right);
	log::info("[PAtk_spline - describe] m_leftValue: {}", m_leftValue);
	log::info("[PAtk_spline - describe] m_rightValue: {}", m_rightValue);
	log::info("[PAtk_spline - describe] m_madeMonotonic: {}", m_madeMonotonic);
}
#endif