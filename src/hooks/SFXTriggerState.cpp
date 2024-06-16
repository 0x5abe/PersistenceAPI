#include "hooks/SFXTriggerState.hpp"
#include "Geode/binding/SFXTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

void PUSFXTriggerState::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUSFXTriggerState::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceUtils::operator>>(InputStream& i_stream, PUSFXTriggerState& o_value) {
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_sfxTriggerGameObject = static_cast<SFXTriggerGameObject*>(l_playLayer->getGameObject(l_objectIndex));
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUSFXTriggerState,m_sfxTriggerGameObject) + sizeof(SFXTriggerGameObject*), 160);
	SEPARATOR_I
}

inline void persistenceUtils::operator<<(OutputStream& o_stream, PUSFXTriggerState& i_value) {
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_sfxTriggerGameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUSFXTriggerState,m_sfxTriggerGameObject) + sizeof(SFXTriggerGameObject*), 160);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUSFXTriggerState::describe() {
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_sfxTriggerGameObject);
	log::info("[PUSFXTriggerState - describe] m_sfxTriggerGameObject l_objectIndex: {}", l_objectIndex);
	log::info("[PUSFXTriggerState - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUSFXTriggerState,m_sfxTriggerGameObject) + sizeof(SFXTriggerGameObject*), 160));
}
#endif