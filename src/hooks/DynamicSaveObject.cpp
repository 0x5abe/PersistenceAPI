#include "hooks/DynamicSaveObject.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PADynamicSaveObject::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PADynamicSaveObject::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PADynamicSaveObject& o_value) {
	int l_objectIndex;
	i_stream >> l_objectIndex;
	SEPARATOR_I
	i_stream >> o_value.m_unkDouble1;
	SEPARATOR_I
	i_stream >> o_value.m_unkDouble2;
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat1;
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat2;
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat3;
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat4;
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat5;
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat6;
	SEPARATOR_I_END

	// get the pointer to the gameObject

	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_gameObject = l_playLayer->getGameObject(l_objectIndex);
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PADynamicSaveObject& i_value) {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream << i_value.m_unkDouble1;
	SEPARATOR_O
	o_stream << i_value.m_unkDouble2;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat1;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat2;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat3;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat4;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat5;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat6;
	SEPARATOR_O_END
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PADynamicSaveObject::describe() {
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	
	log::info("[PADynamicSaveObject - describe] l_objectIndex: {}", l_objectIndex);
	log::info("[PADynamicSaveObject - describe] m_unkDouble1: {}", m_unkDouble1);
	log::info("[PADynamicSaveObject - describe] m_unkDouble2: {}", m_unkDouble2);
	log::info("[PADynamicSaveObject - describe] m_unkFloat1: {}", m_unkFloat1);
	log::info("[PADynamicSaveObject - describe] m_unkFloat2: {}", m_unkFloat2);
	log::info("[PADynamicSaveObject - describe] m_unkFloat3: {}", m_unkFloat3);
	log::info("[PADynamicSaveObject - describe] m_unkFloat4: {}", m_unkFloat4);
	log::info("[PADynamicSaveObject - describe] m_unkFloat5: {}", m_unkFloat5);
	log::info("[PADynamicSaveObject - describe] m_unkFloat6: {}", m_unkFloat6);
}
#endif