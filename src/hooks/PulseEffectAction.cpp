#include "hooks/PulseEffectAction.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAPulseEffectAction::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAPulseEffectAction::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAPulseEffectAction& o_value) {
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_disabled;
		SEPARATOR_I;
		i_stream >> o_value.m_fadeInTime;
		SEPARATOR_I;
		i_stream >> o_value.m_holdTime;
		SEPARATOR_I;
		i_stream >> o_value.m_fadeOutTime;
		SEPARATOR_I;
		i_stream >> o_value.m_deltaTime;
		SEPARATOR_I;
		i_stream >> o_value.m_targetGroupID;
		SEPARATOR_I;
		i_stream >> o_value.m_currentValue;
		SEPARATOR_I;
		i_stream >> o_value.m_color;
		SEPARATOR_I;
		i_stream >> o_value.m_pulseEffectType;
		SEPARATOR_I;
		i_stream >> o_value.m_hsv;
		SEPARATOR_I;
		i_stream >> o_value.m_colorIndex;
		SEPARATOR_I;
		i_stream >> o_value.m_mainOnly;
		SEPARATOR_I;
		i_stream >> o_value.m_detailOnly;
		SEPARATOR_I;
		i_stream >> o_value.m_isDynamicHsv;
		SEPARATOR_I;
		i_stream >> o_value.m_triggerUniqueID;
		SEPARATOR_I;
		i_stream >> o_value.m_controlID;
		SEPARATOR_I;
		i_stream >> o_value.m_startTime;
		SEPARATOR_I;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value), sizeof(PulseEffectAction));
	}
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAPulseEffectAction& i_value) {
	o_stream << i_value.m_disabled;
	SEPARATOR_O;
	o_stream << i_value.m_fadeInTime;
	SEPARATOR_O;
	o_stream << i_value.m_holdTime;
	SEPARATOR_O;
	o_stream << i_value.m_fadeOutTime;
	SEPARATOR_O;
	o_stream << i_value.m_deltaTime;
	SEPARATOR_O;
	o_stream << i_value.m_targetGroupID;
	SEPARATOR_O;
	o_stream << i_value.m_currentValue;
	SEPARATOR_O;
	o_stream << i_value.m_color;
	SEPARATOR_O;
	o_stream << i_value.m_pulseEffectType;
	SEPARATOR_O;
	o_stream << i_value.m_hsv;
	SEPARATOR_O;
	o_stream << i_value.m_colorIndex;
	SEPARATOR_O;
	o_stream << i_value.m_mainOnly;
	SEPARATOR_O;
	o_stream << i_value.m_detailOnly;
	SEPARATOR_O;
	o_stream << i_value.m_isDynamicHsv;
	SEPARATOR_O;
	o_stream << i_value.m_triggerUniqueID;
	SEPARATOR_O;
	o_stream << i_value.m_controlID;
	SEPARATOR_O;
	o_stream << i_value.m_startTime;
	SEPARATOR_O;
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAPulseEffectAction::describe() {
	bool m_disabled;
    float m_fadeInTime;
    float m_holdTime;
    float m_fadeOutTime;
    float m_deltaTime;
    int m_targetGroupID;
    float m_currentValue;
    cocos2d::ccColor3B m_color;
    PulseEffectType m_pulseEffectType;
    cocos2d::ccHSVValue m_hsv;
    int m_colorIndex;
    bool m_mainOnly;
    bool m_detailOnly;
    bool m_isDynamicHsv;
    int m_triggerUniqueID;
    int m_controlID;
    float m_startTime;
	log::info("[PAPulseEffectAction - describe] m_disabled: {}", m_disabled);
	log::info("[PAPulseEffectAction - describe] m_fadeInTime: {}", m_fadeInTime);
	log::info("[PAPulseEffectAction - describe] m_holdTime: {}", m_holdTime);
	log::info("[PAPulseEffectAction - describe] m_fadeOutTime: {}", m_fadeOutTime);
	log::info("[PAPulseEffectAction - describe] m_deltaTime: {}", m_deltaTime);
	log::info("[PAPulseEffectAction - describe] m_targetGroupID: {}", m_targetGroupID);
	log::info("[PAPulseEffectAction - describe] m_currentValue: {}", m_currentValue);
	log::info("[PAPulseEffectAction - describe] m_color: {}", m_color);
	log::info("[PAPulseEffectAction - describe] m_pulseEffectType: {}", *reinterpret_cast<int*>(&m_pulseEffectType));
	log::info("[PAPulseEffectAction - describe] m_hsv.h: {}", m_hsv.h);
	log::info("[PAPulseEffectAction - describe] m_hsv.s: {}", m_hsv.s);
	log::info("[PAPulseEffectAction - describe] m_hsv.v: {}", m_hsv.v);
	log::info("[PAPulseEffectAction - describe] m_hsv.absoluteSaturation: {}", m_hsv.absoluteSaturation);
	log::info("[PAPulseEffectAction - describe] m_hsv.absoluteBrightness: {}", m_hsv.absoluteBrightness);
	log::info("[PAPulseEffectAction - describe] m_colorIndex: {}", m_colorIndex);
	log::info("[PAPulseEffectAction - describe] m_mainOnly: {}", m_mainOnly);
	log::info("[PAPulseEffectAction - describe] m_detailOnly: {}", m_detailOnly);
	log::info("[PAPulseEffectAction - describe] m_isDynamicHsv: {}", m_isDynamicHsv);
	log::info("[PAPulseEffectAction - describe] m_triggerUniqueID: {}", m_triggerUniqueID);
	log::info("[PAPulseEffectAction - describe] m_controlID: {}", m_controlID);
	log::info("[PAPulseEffectAction - describe] m_startTime: {}", m_startTime);
}
#endif