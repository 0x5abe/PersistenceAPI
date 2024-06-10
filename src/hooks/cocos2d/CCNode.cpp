#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/cocos2d/CCObject.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistencyUtils;

void PUCCNode::load(InputStream& i_stream) {
	reinterpret_cast<PUCCObject*>(this)->load(i_stream);
	i_stream >> *this;
}

void PUCCNode::save(OutputStream& o_stream) {
	reinterpret_cast<PUCCObject*>(this)->save(o_stream);
	o_stream << *this;
}

inline void persistencyUtils::operator>>(InputStream& i_stream, PUCCNode& o_value) {
	i_stream >> o_value.m_fRotationX;
	SEPARATOR_I
	i_stream >> o_value.m_fRotationY;
	SEPARATOR_I
	i_stream >> o_value.m_fScaleX;
	SEPARATOR_I
	i_stream >> o_value.m_fScaleY;
	SEPARATOR_I
	i_stream >> o_value.m_fVertexZ;
	SEPARATOR_I
	i_stream >> o_value.m_obPosition;
	SEPARATOR_I
	i_stream >> o_value.m_fSkewX;
	SEPARATOR_I
	i_stream >> o_value.m_fSkewY;
	SEPARATOR_I
	i_stream >> o_value.m_obAnchorPointInPoints;
	SEPARATOR_I
	i_stream >> o_value.m_obAnchorPoint;
	SEPARATOR_I
	i_stream >> o_value.m_obContentSize;
	SEPARATOR_I
	i_stream >> o_value.m_sAdditionalTransform;
	SEPARATOR_I
	i_stream >> o_value.m_sTransform;
	SEPARATOR_I
	i_stream >> o_value.m_sInverse;
	SEPARATOR_I
	i_stream >> o_value.m_bRunning;
	SEPARATOR_I
	i_stream >> o_value.m_bTransformDirty;
	SEPARATOR_I
	i_stream >> o_value.m_bInverseDirty;
	SEPARATOR_I
	i_stream >> o_value.m_bAdditionalTransformDirty;
	SEPARATOR_I
	i_stream >> o_value.m_bVisible;
	SEPARATOR_I
	i_stream >> o_value.m_bIgnoreAnchorPointForPosition;
	SEPARATOR_I
	i_stream >> o_value.m_bReorderChildDirty;
	SEPARATOR_I
	i_stream >> o_value.m_bUnkBool1;
	SEPARATOR_I
	i_stream >> o_value.m_bUnkBool2;
	SEPARATOR_I
}

inline void persistencyUtils::operator<<(OutputStream& o_stream, PUCCNode& i_value) {
	o_stream << i_value.m_fRotationX;
	SEPARATOR_O
	o_stream << i_value.m_fRotationY;
	SEPARATOR_O
	o_stream << i_value.m_fScaleX;
	SEPARATOR_O
	o_stream << i_value.m_fScaleY;
	SEPARATOR_O
	o_stream << i_value.m_fVertexZ;
	SEPARATOR_O
	o_stream << i_value.m_obPosition;
	SEPARATOR_O
	o_stream << i_value.m_fSkewX;
	SEPARATOR_O
	o_stream << i_value.m_fSkewY;
	SEPARATOR_O
	o_stream << i_value.m_obAnchorPointInPoints;
	SEPARATOR_O
	o_stream << i_value.m_obAnchorPoint;
	SEPARATOR_O
	o_stream << i_value.m_obContentSize;
	SEPARATOR_O
	o_stream << i_value.m_sAdditionalTransform;
	SEPARATOR_O
	o_stream << i_value.m_sTransform;
	SEPARATOR_O
	o_stream << i_value.m_sInverse;
	SEPARATOR_O
	o_stream << i_value.m_bRunning;
	SEPARATOR_O
	o_stream << i_value.m_bTransformDirty;
	SEPARATOR_O
	o_stream << i_value.m_bInverseDirty;
	SEPARATOR_O
	o_stream << i_value.m_bAdditionalTransformDirty;
	SEPARATOR_O
	o_stream << i_value.m_bVisible;
	SEPARATOR_O
	o_stream << i_value.m_bIgnoreAnchorPointForPosition;
	SEPARATOR_O
	o_stream << i_value.m_bReorderChildDirty;
	SEPARATOR_O
	o_stream << i_value.m_bUnkBool1;
	SEPARATOR_O
	o_stream << i_value.m_bUnkBool2;
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUCCNode::describe() {
	log::info("[PUCCNode - describe] m_fRotationX: {}", m_fRotationX);
	log::info("[PUCCNode - describe] m_fRotationY: {}", m_fRotationY);
	log::info("[PUCCNode - describe] m_fScaleX: {}", m_fScaleX);
	log::info("[PUCCNode - describe] m_fScaleY: {}", m_fScaleY);
	log::info("[PUCCNode - describe] m_fVertexZ: {}", m_fVertexZ);
	log::info("[PUCCNode - describe] m_obPosition: {}", m_obPosition);
	log::info("[PUCCNode - describe] m_fSkewX: {}", m_fSkewX);
	log::info("[PUCCNode - describe] m_fSkewY: {}", m_fSkewY);
	log::info("[PUCCNode - describe] m_obAnchorPointInPoints: {}", m_obAnchorPointInPoints);
	log::info("[PUCCNode - describe] m_obAnchorPoint: {}", m_obAnchorPoint);
	log::info("[PUCCNode - describe] m_obContentSize: {}", m_obContentSize);
	log::info("[PUCCNode - describe] m_sAdditionalTransform.A: {}", m_sAdditionalTransform.a);
	log::info("[PUCCNode - describe] m_sAdditionalTransform.B: {}", m_sAdditionalTransform.b);
	log::info("[PUCCNode - describe] m_sAdditionalTransform.C: {}", m_sAdditionalTransform.c);
	log::info("[PUCCNode - describe] m_sAdditionalTransform.D: {}", m_sAdditionalTransform.d);
	log::info("[PUCCNode - describe] m_sAdditionalTransform.TX: {}", m_sAdditionalTransform.tx);
	log::info("[PUCCNode - describe] m_sAdditionalTransform.TY: {}", m_sAdditionalTransform.ty);
	log::info("[PUCCNode - describe] m_sTransform.A: {}", m_sTransform.a);
	log::info("[PUCCNode - describe] m_sTransform.B: {}", m_sTransform.b);
	log::info("[PUCCNode - describe] m_sTransform.C: {}", m_sTransform.c);
	log::info("[PUCCNode - describe] m_sTransform.D: {}", m_sTransform.d);
	log::info("[PUCCNode - describe] m_sTransform.TX: {}", m_sTransform.tx);
	log::info("[PUCCNode - describe] m_sTransform.TY: {}", m_sTransform.ty);
	log::info("[PUCCNode - describe] m_sInverse.A: {}", m_sInverse.a);
	log::info("[PUCCNode - describe] m_sInverse.B: {}", m_sInverse.b);
	log::info("[PUCCNode - describe] m_sInverse.C: {}", m_sInverse.c);
	log::info("[PUCCNode - describe] m_sInverse.D: {}", m_sInverse.d);
	log::info("[PUCCNode - describe] m_sInverse.TX: {}", m_sInverse.tx);
	log::info("[PUCCNode - describe] m_sInverse.TY: {}", m_sInverse.ty);
	log::info("[PUCCNode - describe] m_bRunning: {}", m_bRunning);
	log::info("[PUCCNode - describe] m_bTransformDirty: {}", m_bTransformDirty);
	log::info("[PUCCNode - describe] m_bInverseDirty: {}", m_bInverseDirty);
	log::info("[PUCCNode - describe] m_bAdditionalTransformDirty: {}", m_bAdditionalTransformDirty);
	log::info("[PUCCNode - describe] m_bVisible: {}", m_bVisible);
	log::info("[PUCCNode - describe] m_bIgnoreAnchorPointForPosition: {}", m_bIgnoreAnchorPointForPosition);
	log::info("[PUCCNode - describe] m_bReorderChildDirty: {}", m_bReorderChildDirty);
	log::info("[PUCCNode - describe] m_bUnkBool1: {}", m_bUnkBool1);
	log::info("[PUCCNode - describe] m_bUnkBool2: {}", m_bUnkBool2);
}
#endif