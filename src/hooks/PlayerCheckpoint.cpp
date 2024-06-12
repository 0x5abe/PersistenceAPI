#include "hooks/PlayerCheckpoint.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistencyUtils;

void PUPlayerCheckpoint::load(InputStream& i_stream) {
	reinterpret_cast<PUCCNode*>(this)->load(i_stream);
	i_stream >> *this;
}

void PUPlayerCheckpoint::save(OutputStream& o_stream) {
	reinterpret_cast<PUCCNode*>(this)->save(o_stream);
	o_stream << *this;
}

inline void persistencyUtils::operator>>(InputStream& i_stream, PUPlayerCheckpoint& o_value) {
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

inline void persistencyUtils::operator<<(OutputStream& o_stream, PUPlayerCheckpoint& i_value) {
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
void PUPlayerCheckpoint::describe() {
	log::info("[PUPlayerCheckpoint - describe] m_position: {}", m_position);
	log::info("[PUPlayerCheckpoint - describe] m_lastPosition: {}", m_lastPosition);
	log::info("[PUPlayerCheckpoint - describe] m_unkInt1: {}", m_unkInt1);
	log::info("[PUPlayerCheckpoint - describe] m_isUpsideDown: {}", m_isUpsideDown);
	log::info("[PUPlayerCheckpoint - describe] m_unk7b3: {}", m_unk7b3);
	log::info("[PUPlayerCheckpoint - describe] m_isShip: {}", m_isShip);
	log::info("[PUPlayerCheckpoint - describe] m_isBall: {}", m_isBall);
	log::info("[PUPlayerCheckpoint - describe] m_isBird: {}", m_isBird);
	log::info("[PUPlayerCheckpoint - describe] m_isSwing: {}", m_isSwing);
	log::info("[PUPlayerCheckpoint - describe] m_isDart: {}", m_isDart);
	log::info("[PUPlayerCheckpoint - describe] m_isRobot: {}", m_isRobot);
	log::info("[PUPlayerCheckpoint - describe] m_isSpider: {}", m_isSpider);
	log::info("[PUPlayerCheckpoint - describe] m_isOnGround: {}", m_isOnGround);
	log::info("[PUPlayerCheckpoint - describe] m_hasGhostTrail: {}", m_hasGhostTrail);
	log::info("[PUPlayerCheckpoint - describe] m_unkBytes1: [{}]", hexStr(m_unkBytes1, 4));
	log::info("[PUPlayerCheckpoint - describe] m_speed: {}", m_speed);
	log::info("[PUPlayerCheckpoint - describe] m_isHidden: {}", m_isHidden);
	log::info("[PUPlayerCheckpoint - describe] m_isGoingLeft: {}", m_isGoingLeft);
	log::info("[PUPlayerCheckpoint - describe] m_unkBytes2: [{}]", hexStr(m_unkBytes2, 27));
	log::info("[PUPlayerCheckpoint - describe] m_maybeAPointer: {}", m_maybeAPointer);
	log::info("[PUPlayerCheckpoint - describe] m_unkBool: {}", m_unkBool);
	log::info("[PUPlayerCheckpoint - describe] m_unkFloat1: {}", m_unkFloat1);
	log::info("[PUPlayerCheckpoint - describe] m_possiblyFlags: {}", m_possiblyFlags);
	log::info("[PUPlayerCheckpoint - describe] m_timeOrPercentRelated: {}", m_timeOrPercentRelated);
	log::info("[PUPlayerCheckpoint - describe] m_unkBytes3: [{}]", hexStr(m_unkBytes3, 4));
	int l_size = m_yPositionVector.size();
	log::info("[PUPlayerCheckpoint - describe] m_yPositionVector.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PUPlayerCheckpoint - describe] m_yPositionVector[{}]: {}", i, m_yPositionVector[i]);
	}
	log::info("[PUPlayerCheckpoint - describe] m_unkBytes4: [{}]", hexStr(m_unkBytes4, 8));
}
#endif