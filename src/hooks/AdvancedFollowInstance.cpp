#include "hooks/AdvancedFollowInstance.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistencyUtils;

void PUAdvancedFollowInstance::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUAdvancedFollowInstance::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistencyUtils::operator>>(InputStream& i_stream, PUAdvancedFollowInstance& o_value) {
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_gameObject = l_playLayer->getGameObject(l_objectIndex);
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUAdvancedFollowInstance,m_gameObject) + sizeof(GameObject*), 24);
	SEPARATOR_I
}

inline void persistencyUtils::operator<<(OutputStream& o_stream, PUAdvancedFollowInstance& i_value) {
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUAdvancedFollowInstance,m_gameObject) + sizeof(GameObject*), 24);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUAdvancedFollowInstance::describe() {
	log::info("[PUAdvancedFollowInstance - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUAdvancedFollowInstance,m_gameObject) + sizeof(GameObject*), 24));
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PUAdvancedFollowInstance - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
}
#endif