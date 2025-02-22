#include "hooks/EnterEffectInstance.hpp"
#include "Geode/binding/GameObject.hpp"
#include "hooks/PlayLayer.hpp"
#include "hooks/EnterEffectAnimValue.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAEnterEffectInstance::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAEnterEffectInstance::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAEnterEffectInstance& o_value) {
	MAP_SEPARATOR_I
	i_stream >> o_value.m_enterEffectAnimMap;
	MAP_SEPARATOR_I
	if (i_stream.getFileVersion() > 9) {
		i_stream >> o_value.m_length;
		SEPARATOR_I
		i_stream >> o_value.m_lengthVariance;
		SEPARATOR_I
		i_stream >> o_value.m_offset;
		SEPARATOR_I
		i_stream >> o_value.m_offsetVariance;
		SEPARATOR_I
		i_stream >> o_value.m_offsetY;
		SEPARATOR_I
		i_stream >> o_value.m_offsetYVariance;
		SEPARATOR_I
		i_stream >> o_value.m_modFront;
		SEPARATOR_I
		i_stream >> o_value.m_modBack;
		SEPARATOR_I
		i_stream >> o_value.m_deadzone;
		SEPARATOR_I
		i_stream >> o_value.m_moveDistance;
		SEPARATOR_I
		i_stream >> o_value.m_moveDistanceVariance;
		SEPARATOR_I
		i_stream >> o_value.m_moveAngle;
		SEPARATOR_I
		i_stream >> o_value.m_moveAngleVariance;
		SEPARATOR_I
		i_stream >> o_value.m_moveX;
		SEPARATOR_I
		i_stream >> o_value.m_moveXVariance;
		SEPARATOR_I
		i_stream >> o_value.m_moveY;
		SEPARATOR_I
		i_stream >> o_value.m_moveYVariance;
		SEPARATOR_I
		i_stream >> o_value.m_relativeFade;
		SEPARATOR_I
		i_stream >> o_value.m_scaleX;
		SEPARATOR_I
		i_stream >> o_value.m_scaleXVariance;
		SEPARATOR_I
		i_stream >> o_value.m_scaleY;
		SEPARATOR_I
		i_stream >> o_value.m_scaleYVariance;
		SEPARATOR_I
		i_stream >> o_value.m_rotation;
		SEPARATOR_I
		i_stream >> o_value.m_rotationVariance;
		SEPARATOR_I
		i_stream >> o_value.m_tint;
		SEPARATOR_I
		i_stream >> o_value.m_unk074;
		SEPARATOR_I
		i_stream >> o_value.m_toOpacity;
		SEPARATOR_I
		i_stream >> o_value.m_fromOpacity;
		SEPARATOR_I
		i_stream >> o_value.m_hsvValue;
		SEPARATOR_I
		i_stream >> o_value.m_hue;
		SEPARATOR_I
		i_stream >> o_value.m_saturation;
		SEPARATOR_I
		i_stream >> o_value.m_value;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAEnterEffectInstance,m_enterEffectAnimMap) + sizeof(gd::map<int,EnterEffectAnimValue>), 140);
	}
	SEPARATOR_I
	i_stream >> o_value.m_gameObject;
	SEPARATOR_I
	if (i_stream.getFileVersion() > 9) {
		i_stream >> o_value.m_unkBool1;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat1;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat2;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat3;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat4;
		SEPARATOR_I
		i_stream >> o_value.m_unkBool2;
		SEPARATOR_I
		i_stream >> o_value.m_unkBool3;
		SEPARATOR_I
		i_stream >> o_value.m_unkBool4;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat5;
	}
	else {
		i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAEnterEffectInstance,m_gameObject) + sizeof(GameObject*), 28);
	}
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkFloat6;
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAEnterEffectInstance& i_value) {
	MAP_SEPARATOR_O
	o_stream << i_value.m_enterEffectAnimMap;
	MAP_SEPARATOR_O
	o_stream << i_value.m_length;
	SEPARATOR_O
	o_stream << i_value.m_lengthVariance;
	SEPARATOR_O
	o_stream << i_value.m_offset;
	SEPARATOR_O
	o_stream << i_value.m_offsetVariance;
	SEPARATOR_O
	o_stream << i_value.m_offsetY;
	SEPARATOR_O
	o_stream << i_value.m_offsetYVariance;
	SEPARATOR_O
	o_stream << i_value.m_modFront;
	SEPARATOR_O
	o_stream << i_value.m_modBack;
	SEPARATOR_O
	o_stream << i_value.m_deadzone;
	SEPARATOR_O
	o_stream << i_value.m_moveDistance;
	SEPARATOR_O
	o_stream << i_value.m_moveDistanceVariance;
	SEPARATOR_O
	o_stream << i_value.m_moveAngle;
	SEPARATOR_O
	o_stream << i_value.m_moveAngleVariance;
	SEPARATOR_O
	o_stream << i_value.m_moveX;
	SEPARATOR_O
	o_stream << i_value.m_moveXVariance;
	SEPARATOR_O
	o_stream << i_value.m_moveY;
	SEPARATOR_O
	o_stream << i_value.m_moveYVariance;
	SEPARATOR_O
	o_stream << i_value.m_relativeFade;
	SEPARATOR_O
	o_stream << i_value.m_scaleX;
	SEPARATOR_O
	o_stream << i_value.m_scaleXVariance;
	SEPARATOR_O
	o_stream << i_value.m_scaleY;
	SEPARATOR_O
	o_stream << i_value.m_scaleYVariance;
	SEPARATOR_O
	o_stream << i_value.m_rotation;
	SEPARATOR_O
	o_stream << i_value.m_rotationVariance;
	SEPARATOR_O
	o_stream << i_value.m_tint;
	SEPARATOR_O
	o_stream << i_value.m_unk074;
	SEPARATOR_O
	o_stream << i_value.m_toOpacity;
	SEPARATOR_O
	o_stream << i_value.m_fromOpacity;
	SEPARATOR_O
	o_stream << i_value.m_hsvValue;
	SEPARATOR_O
	o_stream << i_value.m_hue;
	SEPARATOR_O
	o_stream << i_value.m_saturation;
	SEPARATOR_O
	o_stream << i_value.m_value;
	SEPARATOR_O
	o_stream << i_value.m_gameObject;
	SEPARATOR_O
	o_stream << i_value.m_unkBool1;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat1;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat2;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat3;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat4;
	SEPARATOR_O
	o_stream << i_value.m_unkBool2;
	SEPARATOR_O
	o_stream << i_value.m_unkBool3;
	SEPARATOR_O
	o_stream << i_value.m_unkBool4;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat5;
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkFloat6;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAEnterEffectInstance::describe() {
	int i = 0;
	for (std::pair<int, EnterEffectAnimValue> l_pair : m_enterEffectAnimMap) {
		log::info("[PAEnterEffectInstance - describe] m_enterEffectAnimMap element {} key: {}", i, l_pair.first);
		reinterpret_cast<PAEnterEffectAnimValue*>(&l_pair.second)->describe();
		i++;
	}
	log::info("[PAEnterEffectInstance - describe] m_length: {}", m_length);
	log::info("[PAEnterEffectInstance - describe] m_lengthVariance: {}", m_lengthVariance);
	log::info("[PAEnterEffectInstance - describe] m_offset: {}", m_offset);
	log::info("[PAEnterEffectInstance - describe] m_offsetVariance: {}", m_offsetVariance);
	log::info("[PAEnterEffectInstance - describe] m_offsetY: {}", m_offsetY);
	log::info("[PAEnterEffectInstance - describe] m_offsetYVariance: {}", m_offsetYVariance);
	log::info("[PAEnterEffectInstance - describe] m_modFront: {}", m_modFront);
	log::info("[PAEnterEffectInstance - describe] m_modBack: {}", m_modBack);
	log::info("[PAEnterEffectInstance - describe] m_deadzone: {}", m_deadzone);
	log::info("[PAEnterEffectInstance - describe] m_moveDistance: {}", m_moveDistance);
	log::info("[PAEnterEffectInstance - describe] m_moveDistanceVariance: {}", m_moveDistanceVariance);
	log::info("[PAEnterEffectInstance - describe] m_moveAngle: {}", m_moveAngle);
	log::info("[PAEnterEffectInstance - describe] m_moveAngleVariance: {}", m_moveAngleVariance);
	log::info("[PAEnterEffectInstance - describe] m_moveX: {}", m_moveX);
	log::info("[PAEnterEffectInstance - describe] m_moveXVariance: {}", m_moveXVariance);
	log::info("[PAEnterEffectInstance - describe] m_moveY: {}", m_moveY);
	log::info("[PAEnterEffectInstance - describe] m_moveYVariance: {}", m_moveYVariance);
	log::info("[PAEnterEffectInstance - describe] m_relativeFade: {}", m_relativeFade);
	log::info("[PAEnterEffectInstance - describe] m_scaleX: {}", m_scaleX);
	log::info("[PAEnterEffectInstance - describe] m_scaleXVariance: {}", m_scaleXVariance);
	log::info("[PAEnterEffectInstance - describe] m_scaleY: {}", m_scaleY);
	log::info("[PAEnterEffectInstance - describe] m_scaleYVariance: {}", m_scaleYVariance);
	log::info("[PAEnterEffectInstance - describe] m_rotation: {}", m_rotation);
	log::info("[PAEnterEffectInstance - describe] m_rotationVariance: {}", m_rotationVariance);
	log::info("[PAEnterEffectInstance - describe] m_tint: {}", m_tint);
	log::info("[PAEnterEffectInstance - describe] m_unk074: {}", m_unk074);
	log::info("[PAEnterEffectInstance - describe] m_toOpacity: {}", m_toOpacity);
	log::info("[PAEnterEffectInstance - describe] m_fromOpacity: {}", m_fromOpacity);
	log::info("[PAEnterEffectInstance - describe] m_hsvValue.h: {}", m_hsvValue.h);
	log::info("[PAEnterEffectInstance - describe] m_hsvValue.s: {}", m_hsvValue.s);
	log::info("[PAEnterEffectInstance - describe] m_hsvValue.v: {}", m_hsvValue.v);
	log::info("[PAEnterEffectInstance - describe] m_hsvValue.absoluteSaturation: {}", m_hsvValue.absoluteSaturation);
	log::info("[PAEnterEffectInstance - describe] m_hsvValue.absoluteBrightness: {}", m_hsvValue.absoluteBrightness);
	log::info("[PAEnterEffectInstance - describe] m_hue: {}", m_hue);
	log::info("[PAEnterEffectInstance - describe] m_saturation: {}", m_saturation);
	log::info("[PAEnterEffectInstance - describe] m_value: {}", m_value);
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PAEnterEffectInstance - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
	log::info("[PAEnterEffectInstance - describe] m_unkBool1: {}", m_unkBool1);
	log::info("[PAEnterEffectInstance - describe] m_unkFloat1: {}", m_unkFloat1);
	log::info("[PAEnterEffectInstance - describe] m_unkFloat2: {}", m_unkFloat2);
	log::info("[PAEnterEffectInstance - describe] m_unkFloat3: {}", m_unkFloat3);
	log::info("[PAEnterEffectInstance - describe] m_unkFloat4: {}", m_unkFloat4);
	log::info("[PAEnterEffectInstance - describe] m_unkBool2: {}", m_unkBool2);
	log::info("[PAEnterEffectInstance - describe] m_unkBool3: {}", m_unkBool3);
	log::info("[PAEnterEffectInstance - describe] m_unkBool4: {}", m_unkBool4);
	log::info("[PAEnterEffectInstance - describe] m_unkFloat5: {}", m_unkFloat5);
	int l_size = m_unkVecInt.size();
	log::info("[PAEnterEffectInstance - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEnterEffectInstance - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
	log::info("[PAEnterEffectInstance - describe] m_unkFloat6: {}", m_unkFloat6);
}
#endif