#include "hooks/EnterEffectInstance.hpp"
#include "Geode/binding/GameObject.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAEnterEffectInstance::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PAEnterEffectInstance::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PAEnterEffectInstance& o_value) {
	MAP_SEPARATOR_I
	i_stream >> o_value.m_enterEffectAnimMap;
	MAP_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAEnterEffectInstance,m_enterEffectAnimMap) + sizeof(gd::map<int,EnterEffectAnimValue>), 140);
	SEPARATOR_I
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_gameObject = l_playLayer->getGameObject(l_objectIndex);
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAEnterEffectInstance,m_gameObject) + sizeof(GameObject*), 28);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAEnterEffectInstance,m_unkVecInt) + sizeof(gd::vector<int>), 4);
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PAEnterEffectInstance& i_value) {
	MAP_SEPARATOR_O
	o_stream << i_value.m_enterEffectAnimMap;
	MAP_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PAEnterEffectInstance,m_enterEffectAnimMap) + sizeof(gd::map<int,EnterEffectAnimValue>), 140);
	SEPARATOR_O
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PAEnterEffectInstance,m_gameObject) + sizeof(GameObject*), 28);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PAEnterEffectInstance,m_unkVecInt) + sizeof(gd::vector<int>), 4);
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAEnterEffectInstance::describe() {
	int i = 0;
	for (std::pair<int, EnterEffectAnimValue> l_pair : m_enterEffectAnimMap) {
		log::info("[PAEnterEffectInstance - describe] m_enterEffectAnimMap element {} key: {}", i, l_pair.first);
		log::info("[PAEnterEffectInstance - describe] m_enterEffectAnimMap element {} value: [{}]", i, hexStr(reinterpret_cast<uint8_t*>(&l_pair.second), 32));
		i++;
	}
	log::info("[PAEnterEffectInstance - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PAEnterEffectInstance,m_enterEffectAnimMap) + sizeof(gd::map<int,EnterEffectAnimValue>), 140));
	int l_objectIndex = -1;
	PAPlayLayer* l_playLayer = static_cast<PAPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PAEnterEffectInstance - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
	log::info("[PAEnterEffectInstance - describe] pad_2: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PAEnterEffectInstance,m_gameObject) + sizeof(GameObject*), 28));
	int l_size = m_unkVecInt.size();
	log::info("[PAEnterEffectInstance - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PAEnterEffectInstance - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
	log::info("[PAEnterEffectInstance - describe] pad_3: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PAEnterEffectInstance,m_unkVecInt) + sizeof(gd::vector<int>), 4));
}
#endif