#include "hooks/GroupCommandObject2.hpp"
#include "Geode/binding/KeyframeObject.hpp"
#include "hooks/KeyframeObject.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAGroupCommandObject2::load(Stream& i_stream) {
    i_stream >> *this;
}

void PAGroupCommandObject2::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAGroupCommandObject2& o_value) {
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_groupCommandUniqueID;
        SEPARATOR_I
        i_stream >> o_value.m_moveOffset;
        SEPARATOR_I
        i_stream >> o_value.m_easingType;
        SEPARATOR_I
        i_stream >> o_value.m_easingRate;
        SEPARATOR_I
        i_stream >> o_value.m_duration;
        SEPARATOR_I
        i_stream >> o_value.m_deltaTime;
        SEPARATOR_I
        i_stream >> o_value.m_targetGroupID;
        SEPARATOR_I
        i_stream >> o_value.m_centerGroupID;
        SEPARATOR_I
        i_stream >> o_value.m_currentXOffset;
        SEPARATOR_I
        i_stream >> o_value.m_currentYOffset;
        SEPARATOR_I
        i_stream >> o_value.m_deltaX;
        SEPARATOR_I
        i_stream >> o_value.m_deltaY;
        SEPARATOR_I
        i_stream >> o_value.m_oldDeltaX;
        SEPARATOR_I
        i_stream >> o_value.m_oldDeltaY;
        SEPARATOR_I
        i_stream >> o_value.m_lockedCurrentXOffset;
        SEPARATOR_I
        i_stream >> o_value.m_lockedCurrentYOffset;
        SEPARATOR_I
        i_stream >> o_value.m_finished;
        SEPARATOR_I
        i_stream >> o_value.m_disabled;
        SEPARATOR_I
        i_stream >> o_value.m_finishRelated;
        SEPARATOR_I
        i_stream >> o_value.m_lockToPlayerX;
        SEPARATOR_I
        i_stream >> o_value.m_lockToPlayerY;
        SEPARATOR_I
        i_stream >> o_value.m_lockToCameraX;
        SEPARATOR_I
        i_stream >> o_value.m_lockToCameraY;
        SEPARATOR_I
        i_stream >> o_value.m_lockedInX;
        SEPARATOR_I
        i_stream >> o_value.m_lockedInY;
        SEPARATOR_I
        i_stream >> o_value.m_moveModX;
        SEPARATOR_I
        i_stream >> o_value.m_moveModY;
        SEPARATOR_I
        i_stream >> o_value.m_currentRotateOrTransformValue;
        SEPARATOR_I
        i_stream >> o_value.m_currentRotateOrTransformDelta;
        SEPARATOR_I
        i_stream >> o_value.m_someInterpValue1RelatedOne;
        SEPARATOR_I
        i_stream >> o_value.m_someInterpValue2RelatedOne;
        SEPARATOR_I
        i_stream >> o_value.m_rotationOffset;
        SEPARATOR_I
        i_stream >> o_value.m_lockObjectRotation;
        SEPARATOR_I
        i_stream >> o_value.m_targetPlayer;
        SEPARATOR_I
        i_stream >> o_value.m_followXMod;
        SEPARATOR_I
        i_stream >> o_value.m_followYMod;
        SEPARATOR_I
        i_stream >> o_value.m_commandType;
        SEPARATOR_I
        i_stream >> o_value.m_someInterpValue1;
        SEPARATOR_I
        i_stream >> o_value.m_someInterpValue2;
        SEPARATOR_I
        i_stream >> o_value.m_keyframeRelated;
        SEPARATOR_I
        i_stream >> o_value.m_targetScaleX;
        SEPARATOR_I
        i_stream >> o_value.m_targetScaleY;
        SEPARATOR_I
        i_stream >> o_value.m_transformTriggerProperty450;
        SEPARATOR_I
        i_stream >> o_value.m_transformTriggerProperty451;
        SEPARATOR_I
        i_stream >> o_value.m_someInterpValue1RelatedZero;
        SEPARATOR_I
        i_stream >> o_value.m_someInterpValue2RelatedZero;
        SEPARATOR_I
        i_stream >> o_value.m_onlyMove;
        SEPARATOR_I
        i_stream >> o_value.m_transformRelatedFalse;
        SEPARATOR_I
        i_stream >> o_value.m_relativeRotation;
        SEPARATOR_I
        i_stream >> o_value.m_someInterpValue1Related;
        SEPARATOR_I
        i_stream >> o_value.m_someInterpValue2Related;
        SEPARATOR_I
        i_stream >> o_value.m_followYSpeed;
        SEPARATOR_I
        i_stream >> o_value.m_followYDelay;
        SEPARATOR_I
        i_stream >> o_value.m_followYOffset;
        SEPARATOR_I
        i_stream >> o_value.m_followYMaxSpeed;
        SEPARATOR_I
        i_stream >> o_value.m_triggerUniqueID;
        SEPARATOR_I
        i_stream >> o_value.m_controlID;
        SEPARATOR_I
        i_stream >> o_value.m_deltaX_3;
        SEPARATOR_I
        i_stream >> o_value.m_deltaY_3;
        SEPARATOR_I
        i_stream >> o_value.m_oldDeltaX_3;
        SEPARATOR_I
        i_stream >> o_value.m_oldDeltaY_3;
        SEPARATOR_I
        i_stream >> o_value.m_Delta_3_Related;
        SEPARATOR_I
        i_stream >> o_value.m_unkDoubleMaybeUnused;
        SEPARATOR_I
        i_stream >> o_value.m_actionType1;
        SEPARATOR_I
        i_stream >> o_value.m_actionType2;
        SEPARATOR_I
        i_stream >> o_value.m_actionValue1;
        SEPARATOR_I
        i_stream >> o_value.m_actionValue2;
        SEPARATOR_I
        i_stream >> o_value.m_someInterpValue1RelatedFalse;
        SEPARATOR_I
        i_stream >> o_value.m_deltaTimeInFloat;
        SEPARATOR_I
        i_stream >> o_value.m_alreadyUpdated;
        SEPARATOR_I
        i_stream >> o_value.m_doUpdate;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value), 440);
    }
    VEC_SEPARATOR_I
    i_stream >> o_value.m_keyframes;
    VEC_SEPARATOR_I
    i_stream >> o_value.m_splineRelated;
    SEPARATOR_I
    i_stream >> o_value.m_gameObject;
    if (i_stream.getPAVersion() == 1) {
        i_stream.ignore(4); // pad to keep same size for compatibility with older versions
    }
    SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_gameObjectRotation;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAGroupCommandObject2,m_gameObjectRotation), 8);
    }
    VEC_SEPARATOR_I
    i_stream >> o_value.m_remapKeys;
    VEC_SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_someInterpValue2RelatedTrue;
        SEPARATOR_I
        i_stream >> o_value.m_unkFloat204;
    } else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAGroupCommandObject2,m_someInterpValue2RelatedTrue), 8);
    }
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAGroupCommandObject2& i_value) {
    o_stream << i_value.m_groupCommandUniqueID;
    SEPARATOR_O
    o_stream << i_value.m_moveOffset;
    SEPARATOR_O
    o_stream << i_value.m_easingType;
    SEPARATOR_O
    o_stream << i_value.m_easingRate;
    SEPARATOR_O
    o_stream << i_value.m_duration;
    SEPARATOR_O
    o_stream << i_value.m_deltaTime;
    SEPARATOR_O
    o_stream << i_value.m_targetGroupID;
    SEPARATOR_O
    o_stream << i_value.m_centerGroupID;
    SEPARATOR_O
    o_stream << i_value.m_currentXOffset;
    SEPARATOR_O
    o_stream << i_value.m_currentYOffset;
    SEPARATOR_O
    o_stream << i_value.m_deltaX;
    SEPARATOR_O
    o_stream << i_value.m_deltaY;
    SEPARATOR_O
    o_stream << i_value.m_oldDeltaX;
    SEPARATOR_O
    o_stream << i_value.m_oldDeltaY;
    SEPARATOR_O
    o_stream << i_value.m_lockedCurrentXOffset;
    SEPARATOR_O
    o_stream << i_value.m_lockedCurrentYOffset;
    SEPARATOR_O
    o_stream << i_value.m_finished;
    SEPARATOR_O
    o_stream << i_value.m_disabled;
    SEPARATOR_O
    o_stream << i_value.m_finishRelated;
    SEPARATOR_O
    o_stream << i_value.m_lockToPlayerX;
    SEPARATOR_O
    o_stream << i_value.m_lockToPlayerY;
    SEPARATOR_O
    o_stream << i_value.m_lockToCameraX;
    SEPARATOR_O
    o_stream << i_value.m_lockToCameraY;
    SEPARATOR_O
    o_stream << i_value.m_lockedInX;
    SEPARATOR_O
    o_stream << i_value.m_lockedInY;
    SEPARATOR_O
    o_stream << i_value.m_moveModX;
    SEPARATOR_O
    o_stream << i_value.m_moveModY;
    SEPARATOR_O
    o_stream << i_value.m_currentRotateOrTransformValue;
    SEPARATOR_O
    o_stream << i_value.m_currentRotateOrTransformDelta;
    SEPARATOR_O
    o_stream << i_value.m_someInterpValue1RelatedOne;
    SEPARATOR_O
    o_stream << i_value.m_someInterpValue2RelatedOne;
    SEPARATOR_O
    o_stream << i_value.m_rotationOffset;
    SEPARATOR_O
    o_stream << i_value.m_lockObjectRotation;
    SEPARATOR_O
    o_stream << i_value.m_targetPlayer;
    SEPARATOR_O
    o_stream << i_value.m_followXMod;
    SEPARATOR_O
    o_stream << i_value.m_followYMod;
    SEPARATOR_O
    o_stream << i_value.m_commandType;
    SEPARATOR_O
    o_stream << i_value.m_someInterpValue1;
    SEPARATOR_O
    o_stream << i_value.m_someInterpValue2;
    SEPARATOR_O
    o_stream << i_value.m_keyframeRelated;
    SEPARATOR_O
    o_stream << i_value.m_targetScaleX;
    SEPARATOR_O
    o_stream << i_value.m_targetScaleY;
    SEPARATOR_O
    o_stream << i_value.m_transformTriggerProperty450;
    SEPARATOR_O
    o_stream << i_value.m_transformTriggerProperty451;
    SEPARATOR_O
    o_stream << i_value.m_someInterpValue1RelatedZero;
    SEPARATOR_O
    o_stream << i_value.m_someInterpValue2RelatedZero;
    SEPARATOR_O
    o_stream << i_value.m_onlyMove;
    SEPARATOR_O
    o_stream << i_value.m_transformRelatedFalse;
    SEPARATOR_O
    o_stream << i_value.m_relativeRotation;
    SEPARATOR_O
    o_stream << i_value.m_someInterpValue1Related;
    SEPARATOR_O
    o_stream << i_value.m_someInterpValue2Related;
    SEPARATOR_O
    o_stream << i_value.m_followYSpeed;
    SEPARATOR_O
    o_stream << i_value.m_followYDelay;
    SEPARATOR_O
    o_stream << i_value.m_followYOffset;
    SEPARATOR_O
    o_stream << i_value.m_followYMaxSpeed;
    SEPARATOR_O
    o_stream << i_value.m_triggerUniqueID;
    SEPARATOR_O
    o_stream << i_value.m_controlID;
    SEPARATOR_O
    o_stream << i_value.m_deltaX_3;
    SEPARATOR_O
    o_stream << i_value.m_deltaY_3;
    SEPARATOR_O
    o_stream << i_value.m_oldDeltaX_3;
    SEPARATOR_O
    o_stream << i_value.m_oldDeltaY_3;
    SEPARATOR_O
    o_stream << i_value.m_Delta_3_Related;
    SEPARATOR_O
    o_stream << i_value.m_unkDoubleMaybeUnused;
    SEPARATOR_O
    o_stream << i_value.m_actionType1;
    SEPARATOR_O
    o_stream << i_value.m_actionType2;
    SEPARATOR_O
    o_stream << i_value.m_actionValue1;
    SEPARATOR_O
    o_stream << i_value.m_actionValue2;
    SEPARATOR_O
    o_stream << i_value.m_someInterpValue1RelatedFalse;
    SEPARATOR_O
    o_stream << i_value.m_deltaTimeInFloat;
    SEPARATOR_O
    o_stream << i_value.m_alreadyUpdated;
    SEPARATOR_O
    o_stream << i_value.m_doUpdate;
    VEC_SEPARATOR_O
    o_stream << i_value.m_keyframes;
    VEC_SEPARATOR_O
    o_stream << i_value.m_splineRelated;
    SEPARATOR_O
    o_stream << i_value.m_gameObject;
    SEPARATOR_O
    o_stream << i_value.m_gameObjectRotation;
    VEC_SEPARATOR_O
    o_stream << i_value.m_remapKeys;
    VEC_SEPARATOR_O
    o_stream << i_value.m_someInterpValue2RelatedTrue;
    SEPARATOR_O
    o_stream << i_value.m_unkFloat204;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAGroupCommandObject2::describe() {

    log::info("[PAGroupCommandObject2 - describe] m_groupCommandUniqueID: {}", m_groupCommandUniqueID);
    log::info("[PAGroupCommandObject2 - describe] m_moveOffset: {}", m_moveOffset);
    log::info("[PAGroupCommandObject2 - describe] m_easingType: {}", *reinterpret_cast<int*>(&m_easingType));
    log::info("[PAGroupCommandObject2 - describe] m_easingRate: {}", m_easingRate);
    log::info("[PAGroupCommandObject2 - describe] m_duration: {}", m_duration);
    log::info("[PAGroupCommandObject2 - describe] m_deltaTime: {}", m_deltaTime);
    log::info("[PAGroupCommandObject2 - describe] m_targetGroupID: {}", m_targetGroupID);
    log::info("[PAGroupCommandObject2 - describe] m_centerGroupID: {}", m_centerGroupID);
    log::info("[PAGroupCommandObject2 - describe] m_currentXOffset: {}", m_currentXOffset);
    log::info("[PAGroupCommandObject2 - describe] m_currentYOffset: {}", m_currentYOffset);
    log::info("[PAGroupCommandObject2 - describe] m_deltaX: {}", m_deltaX);
    log::info("[PAGroupCommandObject2 - describe] m_deltaY: {}", m_deltaY);
    log::info("[PAGroupCommandObject2 - describe] m_oldDeltaX: {}", m_oldDeltaX);
    log::info("[PAGroupCommandObject2 - describe] m_oldDeltaY: {}", m_oldDeltaY);
    log::info("[PAGroupCommandObject2 - describe] m_lockedCurrentXOffset: {}", m_lockedCurrentXOffset);
    log::info("[PAGroupCommandObject2 - describe] m_lockedCurrentYOffset: {}", m_lockedCurrentYOffset);
    log::info("[PAGroupCommandObject2 - describe] m_finished: {}", m_finished);
    log::info("[PAGroupCommandObject2 - describe] m_disabled: {}", m_disabled);
    log::info("[PAGroupCommandObject2 - describe] m_finishRelated: {}", m_finishRelated);
    log::info("[PAGroupCommandObject2 - describe] m_lockToPlayerX: {}", m_lockToPlayerX);
    log::info("[PAGroupCommandObject2 - describe] m_lockToPlayerY: {}", m_lockToPlayerY);
    log::info("[PAGroupCommandObject2 - describe] m_lockToCameraX: {}", m_lockToCameraX);
    log::info("[PAGroupCommandObject2 - describe] m_lockToCameraY: {}", m_lockToCameraY);
    log::info("[PAGroupCommandObject2 - describe] m_lockedInX: {}", m_lockedInX);
    log::info("[PAGroupCommandObject2 - describe] m_lockedInY: {}", m_lockedInY);
    log::info("[PAGroupCommandObject2 - describe] m_moveModX: {}", m_moveModX);
    log::info("[PAGroupCommandObject2 - describe] m_moveModY: {}", m_moveModY);
    log::info("[PAGroupCommandObject2 - describe] m_currentRotateOrTransformValue: {}", m_currentRotateOrTransformValue);
    log::info("[PAGroupCommandObject2 - describe] m_currentRotateOrTransformDelta: {}", m_currentRotateOrTransformDelta);
    log::info("[PAGroupCommandObject2 - describe] m_someInterpValue1RelatedOne: {}", m_someInterpValue1RelatedOne);
    log::info("[PAGroupCommandObject2 - describe] m_someInterpValue2RelatedOne: {}", m_someInterpValue2RelatedOne);
    log::info("[PAGroupCommandObject2 - describe] m_rotationOffset: {}", m_rotationOffset);
    log::info("[PAGroupCommandObject2 - describe] m_lockObjectRotation: {}", m_lockObjectRotation);
    log::info("[PAGroupCommandObject2 - describe] m_targetPlayer: {}", m_targetPlayer);
    log::info("[PAGroupCommandObject2 - describe] m_followXMod: {}", m_followXMod);
    log::info("[PAGroupCommandObject2 - describe] m_followYMod: {}", m_followYMod);
    log::info("[PAGroupCommandObject2 - describe] m_commandType: {}", m_commandType);
    log::info("[PAGroupCommandObject2 - describe] m_someInterpValue1: {}", m_someInterpValue1);
    log::info("[PAGroupCommandObject2 - describe] m_someInterpValue2: {}", m_someInterpValue2);
    log::info("[PAGroupCommandObject2 - describe] m_keyframeRelated: {}", m_keyframeRelated);
    log::info("[PAGroupCommandObject2 - describe] m_targetScaleX: {}", m_targetScaleX);
    log::info("[PAGroupCommandObject2 - describe] m_targetScaleY: {}", m_targetScaleY);
    log::info("[PAGroupCommandObject2 - describe] m_transformTriggerProperty450: {}", m_transformTriggerProperty450);
    log::info("[PAGroupCommandObject2 - describe] m_transformTriggerProperty451: {}", m_transformTriggerProperty451);
    log::info("[PAGroupCommandObject2 - describe] m_someInterpValue1RelatedZero: {}", m_someInterpValue1RelatedZero);
    log::info("[PAGroupCommandObject2 - describe] m_someInterpValue2RelatedZero: {}", m_someInterpValue2RelatedZero);
    log::info("[PAGroupCommandObject2 - describe] m_onlyMove: {}", m_onlyMove);
    log::info("[PAGroupCommandObject2 - describe] m_transformRelatedFalse: {}", m_transformRelatedFalse);
    log::info("[PAGroupCommandObject2 - describe] m_relativeRotation: {}", m_relativeRotation);
    log::info("[PAGroupCommandObject2 - describe] m_someInterpValue1Related: {}", m_someInterpValue1Related);
    log::info("[PAGroupCommandObject2 - describe] m_someInterpValue2Related: {}", m_someInterpValue2Related);
    log::info("[PAGroupCommandObject2 - describe] m_followYSpeed: {}", m_followYSpeed);
    log::info("[PAGroupCommandObject2 - describe] m_followYDelay: {}", m_followYDelay);
    log::info("[PAGroupCommandObject2 - describe] m_followYOffset: {}", m_followYOffset);
    log::info("[PAGroupCommandObject2 - describe] m_followYMaxSpeed: {}", m_followYMaxSpeed);
    log::info("[PAGroupCommandObject2 - describe] m_triggerUniqueID: {}", m_triggerUniqueID);
    log::info("[PAGroupCommandObject2 - describe] m_controlID: {}", m_controlID);
    log::info("[PAGroupCommandObject2 - describe] m_deltaX_3: {}", m_deltaX_3);
    log::info("[PAGroupCommandObject2 - describe] m_deltaY_3: {}", m_deltaY_3);
    log::info("[PAGroupCommandObject2 - describe] m_oldDeltaY_3: {}", m_oldDeltaY_3);
    log::info("[PAGroupCommandObject2 - describe] m_Delta_3_Related: {}", m_Delta_3_Related);
    log::info("[PAGroupCommandObject2 - describe] m_unkDoubleMaybeUnused: {}", m_unkDoubleMaybeUnused);
    log::info("[PAGroupCommandObject2 - describe] m_actionType1: {}", m_actionType1);
    log::info("[PAGroupCommandObject2 - describe] m_actionType2: {}", m_actionType2);
    log::info("[PAGroupCommandObject2 - describe] m_actionValue1: {}", m_actionValue1);
    log::info("[PAGroupCommandObject2 - describe] m_actionValue2: {}", m_actionValue2);
    log::info("[PAGroupCommandObject2 - describe] m_someInterpValue1RelatedFalse: {}", m_someInterpValue1RelatedFalse);
    log::info("[PAGroupCommandObject2 - describe] m_deltaTimeInFloat: {}", m_deltaTimeInFloat);
    log::info("[PAGroupCommandObject2 - describe] m_alreadyUpdated: {}", m_alreadyUpdated);
    log::info("[PAGroupCommandObject2 - describe] m_doUpdate: {}", m_doUpdate);
    int l_size = m_keyframes.size();
    log::info("[PAGroupCommandObject2 - describe] m_keyframes.size(): {}", l_size);
    for (int i = 0; i < l_size; i++) {
        log::info("[PAGroupCommandObject2 - describe] m_keyframes[{}]:", i);
        reinterpret_cast<PAKeyframeObject*>(&m_keyframes[i])->describe();
    }
    log::info("[PAGroupCommandObject2 - describe] m_splineRelated: {}", m_splineRelated);
    int l_objectIndex = -1;
    PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
    if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
    log::info("[PAGroupCommandObject2 - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
    log::info("[PAGroupCommandObject2 - describe] m_gameObjectRotation: {}", m_gameObjectRotation);
    l_size = m_remapKeys.size();
    log::info("[PAGroupCommandObject2 - describe] m_remapKeys.size(): {}", l_size);
    for (int i = 0; i < l_size; i++) {
        log::info("[PAGroupCommandObject2 - describe] m_remapKeys[{}]: {}", i, m_remapKeys[i]);
    }
    log::info("[PAGroupCommandObject2 - describe] m_someInterpValue2RelatedTrue: {}", m_someInterpValue2RelatedTrue);
    log::info("[PAGroupCommandObject2 - describe] m_unkFloat204: {}", m_unkFloat204);
}
#endif