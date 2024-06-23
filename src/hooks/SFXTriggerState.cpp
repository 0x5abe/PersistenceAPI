#include "hooks/SFXTriggerState.hpp"
#include "Geode/binding/SFXTriggerGameObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASFXTriggerState::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PASFXTriggerState::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PASFXTriggerState& o_value) {
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_sfxTriggerGameObject = static_cast<SFXTriggerGameObject*>(l_playLayer->getGameObject(l_objectIndex));
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PASFXTriggerState,m_sfxTriggerGameObject) + sizeof(SFXTriggerGameObject*), 160);
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PASFXTriggerState& i_value) {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_sfxTriggerGameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PASFXTriggerState,m_sfxTriggerGameObject) + sizeof(SFXTriggerGameObject*), 160);
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASFXTriggerState::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_sfxTriggerGameObject);
	log::info("[PASFXTriggerState - describe] m_sfxTriggerGameObject l_objectIndex: {}", l_objectIndex);
	log::info("[PASFXTriggerState - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PASFXTriggerState,m_sfxTriggerGameObject) + sizeof(SFXTriggerGameObject*), 160));
}
#endif