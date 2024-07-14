#include "hooks/AdvancedFollowInstance.hpp"
#include "Geode/binding/PlayLayer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAAdvancedFollowInstance::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PAAdvancedFollowInstance::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PAAdvancedFollowInstance& o_value) {
	i_stream >> o_value.m_gameObject;
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAAdvancedFollowInstance,m_gameObject) + sizeof(GameObject*), 24);
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PAAdvancedFollowInstance& i_value) {
	o_stream << i_value.m_gameObject;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PAAdvancedFollowInstance,m_gameObject) + sizeof(GameObject*), 24);
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAAdvancedFollowInstance::describe() {
	log::info("[PAAdvancedFollowInstance - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PAAdvancedFollowInstance,m_gameObject) + sizeof(GameObject*), 24));
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PAAdvancedFollowInstance - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
}
#endif