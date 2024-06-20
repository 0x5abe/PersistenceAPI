#include "hooks/ActiveSaveObject.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAActiveSaveObject1::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PAActiveSaveObject1::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PAActiveSaveObject1& o_value) {
	int l_objectIndex;
	i_stream >> l_objectIndex;
	SEPARATOR_I
	i_stream >> o_value.m_unkBool1;
	SEPARATOR_I
	i_stream >> o_value.m_unkBool2;
	SEPARATOR_I_END

	// get the pointer to the gameObject

	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_gameObject = l_playLayer->getGameObject(l_objectIndex);
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PAActiveSaveObject1& i_value) {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream << i_value.m_unkBool1;
	SEPARATOR_O
	o_stream << i_value.m_unkBool2;
	SEPARATOR_O_END
}

void PAActiveSaveObject2::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PAActiveSaveObject2::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PAActiveSaveObject2& o_value) {
	int l_objectIndex;
	i_stream >> l_objectIndex;
	SEPARATOR_I
	unsigned int l_easingType;
	i_stream >> l_easingType;
	o_value.m_easingType = static_cast<EasingType>(l_easingType);
	SEPARATOR_I_END

	// get the pointer to the gameObject

	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_gameObject = l_playLayer->getGameObject(l_objectIndex);
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PAActiveSaveObject2& i_value) {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
	unsigned int l_easingType = static_cast<unsigned int>(i_value.m_easingType);
	o_stream << l_easingType;
	SEPARATOR_O_END
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PAActiveSaveObject1::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PAActiveSaveObject1 - describe] l_objectIndex: {}", l_objectIndex);
	log::info("[PAActiveSaveObject1 - describe] m_unkBool1: {}", m_unkBool1);
	log::info("[PAActiveSaveObject1 - describe] m_unkBool2: {}", m_unkBool2);
}

void PAActiveSaveObject2::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PAActiveSaveObject2 - describe] l_objectIndex: {}", l_objectIndex);
	log::info("[PAActiveSaveObject2 - describe] m_easingType: {}", static_cast<unsigned int>(m_easingType));
}
#endif