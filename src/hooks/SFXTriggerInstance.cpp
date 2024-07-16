#include "hooks/SFXTriggerInstance.hpp"
#include "Geode/binding/SFXTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASFXTriggerInstance::load(Stream& i_stream) {
	i_stream >> *this;
}

void PASFXTriggerInstance::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASFXTriggerInstance& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 16);
	SEPARATOR_I
	i_stream >> o_value.m_sfxTriggerGameObject;
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASFXTriggerInstance& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 16);
	SEPARATOR_O
	o_stream << i_value.m_sfxTriggerGameObject;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASFXTriggerInstance::describe() {
	log::info("[PASFXTriggerInstance - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this), 16));
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_sfxTriggerGameObject);
	log::info("[PASFXTriggerInstance - describe] m_sfxTriggerGameObject l_objectIndex: {}", l_objectIndex);
}
#endif