#include "hooks/DynamicSaveObject.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

void PUDynamicSaveObject::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUDynamicSaveObject::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceUtils::operator>>(InputStream& i_stream, PUDynamicSaveObject& o_value) {
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

	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_gameObject = l_playLayer->getGameObject(l_objectIndex);
}

inline void persistenceUtils::operator<<(OutputStream& o_stream, PUDynamicSaveObject& i_value) {
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
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
void PUDynamicSaveObject::describe() {
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	
	log::info("[PUDynamicSaveObject - describe] l_objectIndex: {}", l_objectIndex);
	log::info("[PUDynamicSaveObject - describe] m_unkDouble1: {}", m_unkDouble1);
	log::info("[PUDynamicSaveObject - describe] m_unkDouble2: {}", m_unkDouble2);
	log::info("[PUDynamicSaveObject - describe] m_unkFloat1: {}", m_unkFloat1);
	log::info("[PUDynamicSaveObject - describe] m_unkFloat2: {}", m_unkFloat2);
	log::info("[PUDynamicSaveObject - describe] m_unkFloat3: {}", m_unkFloat3);
	log::info("[PUDynamicSaveObject - describe] m_unkFloat4: {}", m_unkFloat4);
	log::info("[PUDynamicSaveObject - describe] m_unkFloat5: {}", m_unkFloat5);
	log::info("[PUDynamicSaveObject - describe] m_unkFloat6: {}", m_unkFloat6);
}
#endif