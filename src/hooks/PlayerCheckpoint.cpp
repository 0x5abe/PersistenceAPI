#include "hooks/PlayerCheckpoint.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAPlayerCheckpoint::load(InputStream& i_stream) {
	reinterpret_cast<PACCNode*>(this)->load(i_stream);
	i_stream >> *this;
}

void PAPlayerCheckpoint::save(OutputStream& o_stream) {
	reinterpret_cast<PACCNode*>(this)->save(o_stream);
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PAPlayerCheckpoint& o_value) {
	i_stream >> o_value.m_position;
	SEPARATOR_I
	i_stream >> o_value.m_lastPosition;
	SEPARATOR_I
	i_stream >> o_value.m_unkInt1;
	SEPARATOR_I
	i_stream >> o_value.m_isUpsideDown;
	SEPARATOR_I
	i_stream >> o_value.m_unk7b3;
	SEPARATOR_I
	i_stream >> o_value.m_isShip;
	SEPARATOR_I
	i_stream >> o_value.m_isBall;
	SEPARATOR_I
	i_stream >> o_value.m_isBird;
	SEPARATOR_I
	i_stream >> o_value.m_isSwing;
	SEPARATOR_I
	i_stream >> o_value.m_isDart;
	SEPARATOR_I
	i_stream >> o_value.m_isRobot;
	SEPARATOR_I
	i_stream >> o_value.m_isSpider;
	SEPARATOR_I
	i_stream >> o_value.m_isOnGround;
	SEPARATOR_I
	i_stream >> o_value.m_hasGhostTrail;
	SEPARATOR_I
	i_stream.read((char*)o_value.m_unkBytes1, 4);
	SEPARATOR_I
	i_stream >> o_value.m_speed;
	SEPARATOR_I
	i_stream >> o_value.m_isHidden;
	SEPARATOR_I
	i_stream >> o_value.m_isGoingLeft;
	SEPARATOR_I
	i_stream.read((char*)o_value.m_unkBytes2, 34);
	SEPARATOR_I
	// TODO SEE IF IT IS A PTR
	i_stream >> o_value.m_hideAttemptCount;
	SEPARATOR_I
	i_stream.read((char*)o_value.m_unkBytes3, 7);
	SEPARATOR_I
	i_stream >> o_value.m_unkBool;
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat1;
	SEPARATOR_I
	i_stream >> o_value.m_possiblyFlags;
	SEPARATOR_I
	i_stream >> o_value.m_timeOrPercentRelated;
	SEPARATOR_I
	i_stream.read((char*)o_value.m_unkBytes4, 4);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_yPositionVector;
	VEC_SEPARATOR_I
	i_stream.read((char*)o_value.m_unkBytes5, 8);
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PAPlayerCheckpoint& i_value) {
	o_stream << i_value.m_position;
	SEPARATOR_O
	o_stream << i_value.m_lastPosition;
	SEPARATOR_O
	o_stream << i_value.m_unkInt1;
	SEPARATOR_O
	o_stream << i_value.m_isUpsideDown;
	SEPARATOR_O
	o_stream << i_value.m_unk7b3;
	SEPARATOR_O
	o_stream << i_value.m_isShip;
	SEPARATOR_O
	o_stream << i_value.m_isBall;
	SEPARATOR_O
	o_stream << i_value.m_isBird;
	SEPARATOR_O
	o_stream << i_value.m_isSwing;
	SEPARATOR_O
	o_stream << i_value.m_isDart;
	SEPARATOR_O
	o_stream << i_value.m_isRobot;
	SEPARATOR_O
	o_stream << i_value.m_isSpider;
	SEPARATOR_O
	o_stream << i_value.m_isOnGround;
	SEPARATOR_O
	o_stream << i_value.m_hasGhostTrail;
	SEPARATOR_O
	o_stream.write((char*)i_value.m_unkBytes1, 4);
	SEPARATOR_O
	o_stream << i_value.m_speed;
	SEPARATOR_O
	o_stream << i_value.m_isHidden;
	SEPARATOR_O
	o_stream << i_value.m_isGoingLeft;
	SEPARATOR_O
	o_stream.write((char*)i_value.m_unkBytes2, 34);
	SEPARATOR_O
	o_stream << i_value.m_hideAttemptCount;
	SEPARATOR_O
	o_stream.write((char*)i_value.m_unkBytes3, 7);
	SEPARATOR_O
	o_stream << i_value.m_unkBool;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat1;
	SEPARATOR_O
	o_stream << i_value.m_possiblyFlags;
	SEPARATOR_O
	o_stream << i_value.m_timeOrPercentRelated;
	SEPARATOR_O
	o_stream.write((char*)i_value.m_unkBytes4, 4);
	VEC_SEPARATOR_O
	o_stream << i_value.m_yPositionVector;
	VEC_SEPARATOR_O
	o_stream.write((char*)i_value.m_unkBytes5, 8);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PAPlayerCheckpoint::describe() {
	log::info("[PAPlayerCheckpoint - describe] m_position: {}", m_position);
	log::info("[PAPlayerCheckpoint - describe] m_lastPosition: {}", m_lastPosition);
	log::info("[PAPlayerCheckpoint - describe] m_unkInt1: {}", m_unkInt1);
	log::info("[PAPlayerCheckpoint - describe] m_isUpsideDown: {}", m_isUpsideDown);
	log::info("[PAPlayerCheckpoint - describe] m_unk7b3: {}", m_unk7b3);
	log::info("[PAPlayerCheckpoint - describe] m_isShip: {}", m_isShip);
	log::info("[PAPlayerCheckpoint - describe] m_isBall: {}", m_isBall);
	log::info("[PAPlayerCheckpoint - describe] m_isBird: {}", m_isBird);
	log::info("[PAPlayerCheckpoint - describe] m_isSwing: {}", m_isSwing);
	log::info("[PAPlayerCheckpoint - describe] m_isDart: {}", m_isDart);
	log::info("[PAPlayerCheckpoint - describe] m_isRobot: {}", m_isRobot);
	log::info("[PAPlayerCheckpoint - describe] m_isSpider: {}", m_isSpider);
	log::info("[PAPlayerCheckpoint - describe] m_isOnGround: {}", m_isOnGround);
	log::info("[PAPlayerCheckpoint - describe] m_hasGhostTrail: {}", m_hasGhostTrail);
	log::info("[PAPlayerCheckpoint - describe] m_unkBytes1: [{}]", hexStr(m_unkBytes1, 4));
	log::info("[PAPlayerCheckpoint - describe] m_speed: {}", m_speed);
	log::info("[PAPlayerCheckpoint - describe] m_isHidden: {}", m_isHidden);
	log::info("[PAPlayerCheckpoint - describe] m_isGoingLeft: {}", m_isGoingLeft);
	log::info("[PAPlayerCheckpoint - describe] m_unkBytes2: [{}]", hexStr(m_unkBytes2, 27));
	log::info("[PAPlayerCheckpoint - describe] m_maybeAPointer: {}", m_maybeAPointer);
	log::info("[PAPlayerCheckpoint - describe] m_unkBool: {}", m_unkBool);
	log::info("[PAPlayerCheckpoint - describe] m_unkFloat1: {}", m_unkFloat1);
	log::info("[PAPlayerCheckpoint - describe] m_possiblyFlags: {}", m_possiblyFlags);
	log::info("[PAPlayerCheckpoint - describe] m_timeOrPercentRelated: {}", m_timeOrPercentRelated);
	log::info("[PAPlayerCheckpoint - describe] m_unkBytes3: [{}]", hexStr(m_unkBytes3, 4));
	int l_size = m_yPositionVector.size();
	log::info("[PAPlayerCheckpoint - describe] m_yPositionVector.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAPlayerCheckpoint - describe] m_yPositionVector[{}]: {}", i, m_yPositionVector[i]);
	}
	log::info("[PAPlayerCheckpoint - describe] m_unkBytes4: [{}]", hexStr(m_unkBytes4, 8));
}
#endif