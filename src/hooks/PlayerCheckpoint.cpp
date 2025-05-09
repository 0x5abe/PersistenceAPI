#include "hooks/PlayerCheckpoint.hpp"
#include "hooks/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAPlayerCheckpoint::load(Stream& i_stream) {
    reinterpret_cast<PACCNode*>(this)->load(i_stream);
    i_stream >> *this;
}

void PAPlayerCheckpoint::save(Stream& o_stream) {
    reinterpret_cast<PACCNode*>(this)->save(o_stream);
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAPlayerCheckpoint& o_value) {
    i_stream >> o_value.m_position;
    SEPARATOR_I
    i_stream >> o_value.m_lastPosition;
    SEPARATOR_I
    i_stream >> o_value.m_yVelocity;
    SEPARATOR_I
    i_stream >> o_value.m_isUpsideDown;
    SEPARATOR_I
    i_stream >> o_value.m_isSideways;
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
    i_stream >> o_value.m_ghostType;
    SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_miniMode;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value.m_miniMode), 4);
    }
    SEPARATOR_I
    i_stream >> o_value.m_speed;
    SEPARATOR_I
    i_stream >> o_value.m_hidden;
    SEPARATOR_I
    i_stream >> o_value.m_goingLeft;
    SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_reverseSpeed;
        SEPARATOR_I
        i_stream >> o_value.m_dashing;
        SEPARATOR_I
        i_stream >> o_value.m_dashX;
        SEPARATOR_I
        i_stream >> o_value.m_dashY;
        SEPARATOR_I
        i_stream >> o_value.m_dashAngle;
        SEPARATOR_I
        i_stream >> o_value.m_dashStartTime;
        SEPARATOR_I
        i_stream >> o_value.m_dashRingObject;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAPlayerCheckpoint,m_goingLeft) + sizeof(bool), 34);
    }
    SEPARATOR_I
    i_stream >> o_value.m_platformerCheckpoint;
    SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_lastFlipTime;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAPlayerCheckpoint,m_platformerCheckpoint) + sizeof(bool), 7);
        SEPARATOR_I
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAPlayerCheckpoint,m_lastFlipTime), sizeof(bool));
        SEPARATOR_I
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAPlayerCheckpoint,m_lastFlipTime) + sizeof(float), sizeof(float));
    }
    SEPARATOR_I
    i_stream >> o_value.m_gravityMod;
    SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_decreaseBoostSlide;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAPlayerCheckpoint,m_decreaseBoostSlide), sizeof(int));
    }
    SEPARATOR_I
    i_stream >> o_value.m_followRelated;
    VEC_SEPARATOR_I
    i_stream >> o_value.m_playerFollowFloats;
    VEC_SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_followRelated2;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAPlayerCheckpoint,m_followRelated2), 8);
    }
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAPlayerCheckpoint& i_value) {
    o_stream << i_value.m_position;
    SEPARATOR_O
    o_stream << i_value.m_lastPosition;
    SEPARATOR_O
    o_stream << i_value.m_yVelocity;
    SEPARATOR_O
    o_stream << i_value.m_isUpsideDown;
    SEPARATOR_O
    o_stream << i_value.m_isSideways;
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
    o_stream << i_value.m_ghostType;
    SEPARATOR_O
    o_stream << i_value.m_miniMode;
    SEPARATOR_O
    o_stream << i_value.m_speed;
    SEPARATOR_O
    o_stream << i_value.m_hidden;
    SEPARATOR_O
    o_stream << i_value.m_goingLeft;
    SEPARATOR_O
    o_stream << i_value.m_reverseSpeed;
    SEPARATOR_O
    o_stream << i_value.m_dashing;
    SEPARATOR_O
    o_stream << i_value.m_dashX;
    SEPARATOR_O
    o_stream << i_value.m_dashY;
    SEPARATOR_O
    o_stream << i_value.m_dashAngle;
    SEPARATOR_O
    o_stream << i_value.m_dashStartTime;
    SEPARATOR_O
    o_stream << i_value.m_dashRingObject;
    SEPARATOR_O
    o_stream << i_value.m_platformerCheckpoint;
    SEPARATOR_O
    o_stream << i_value.m_lastFlipTime;
    SEPARATOR_O
    o_stream << i_value.m_gravityMod;
    SEPARATOR_O
    o_stream << i_value.m_decreaseBoostSlide;
    SEPARATOR_O
    o_stream << i_value.m_followRelated;
    VEC_SEPARATOR_O
    o_stream << i_value.m_playerFollowFloats;
    VEC_SEPARATOR_O
    o_stream << i_value.m_followRelated2;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAPlayerCheckpoint::describe() {
    int l_objectIndex = -1;
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    log::info("[PAPlayerCheckpoint - describe] m_position: {}", m_position);
    log::info("[PAPlayerCheckpoint - describe] m_lastPosition: {}", m_lastPosition);
    log::info("[PAPlayerCheckpoint - describe] m_yVelocity: {}", m_yVelocity);
    log::info("[PAPlayerCheckpoint - describe] m_isUpsideDown: {}", m_isUpsideDown);
    log::info("[PAPlayerCheckpoint - describe] m_isSideways: {}", m_isSideways);
    log::info("[PAPlayerCheckpoint - describe] m_isShip: {}", m_isShip);
    log::info("[PAPlayerCheckpoint - describe] m_isBall: {}", m_isBall);
    log::info("[PAPlayerCheckpoint - describe] m_isBird: {}", m_isBird);
    log::info("[PAPlayerCheckpoint - describe] m_isSwing: {}", m_isSwing);
    log::info("[PAPlayerCheckpoint - describe] m_isDart: {}", m_isDart);
    log::info("[PAPlayerCheckpoint - describe] m_isRobot: {}", m_isRobot);
    log::info("[PAPlayerCheckpoint - describe] m_isSpider: {}", m_isSpider);
    log::info("[PAPlayerCheckpoint - describe] m_isOnGround: {}", m_isOnGround);
    log::info("[PAPlayerCheckpoint - describe] m_ghostType: {}", m_ghostType);
    log::info("[PAPlayerCheckpoint - describe] m_miniMode: {}", m_miniMode);
    log::info("[PAPlayerCheckpoint - describe] m_speed: {}", m_speed);
    log::info("[PAPlayerCheckpoint - describe] m_hidden: {}", m_hidden);
    log::info("[PAPlayerCheckpoint - describe] m_goingLeft: {}", m_goingLeft);
    log::info("[PAPlayerCheckpoint - describe] m_reverseSpeed: {}", m_reverseSpeed);
    log::info("[PAPlayerCheckpoint - describe] m_dashing: {}", m_dashing);
    log::info("[PAPlayerCheckpoint - describe] m_dashX: {}", m_dashX);
    log::info("[PAPlayerCheckpoint - describe] m_dashY: {}", m_dashY);
    log::info("[PAPlayerCheckpoint - describe] m_dashAngle: {}", m_dashAngle);
    log::info("[PAPlayerCheckpoint - describe] m_dashStartTime: {}", m_dashStartTime);
    if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_dashRingObject);
    log::info("[PAPlayerCheckpoint - describe] m_dashRingObject: {}", l_objectIndex);
    log::info("[PAPlayerCheckpoint - describe] m_platformerCheckpoint: {}", m_platformerCheckpoint);
    log::info("[PAPlayerCheckpoint - describe] m_lastFlipTime: {}", m_lastFlipTime);
    log::info("[PAPlayerCheckpoint - describe] m_gravityMod: {}", m_gravityMod);
    log::info("[PAPlayerCheckpoint - describe] m_decreaseBoostSlide: {}", m_decreaseBoostSlide);
    log::info("[PAPlayerCheckpoint - describe] m_followRelated: {}", m_followRelated);
    int l_size = m_playerFollowFloats.size();
    log::info("[PAPlayerCheckpoint - describe] m_playerFollowFloats.size(): {}", l_size);
    for (int i = 0; i < l_size; i++) {
        log::info("[PAPlayerCheckpoint - describe] m_playerFollowFloats[{}]: {}", i, m_playerFollowFloats[i]);
    }
    log::info("[PAPlayerCheckpoint - describe] m_followRelated2: {}", m_followRelated2);
}
#endif