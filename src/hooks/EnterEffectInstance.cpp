#include "hooks/EnterEffectInstance.hpp"
#include "Geode/binding/GameObject.hpp"
#include "hooks/PlayLayer.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

void PUEnterEffectInstance::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUEnterEffectInstance::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceUtils::operator>>(InputStream& i_stream, PUEnterEffectInstance& o_value) {
	MAP_SEPARATOR_I
	i_stream >> o_value.m_enterEffectAnimMap;
	MAP_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUEnterEffectInstance,m_enterEffectAnimMap) + sizeof(gd::map<int,EnterEffectAnimValue>), 140);
	SEPARATOR_I
	int l_objectIndex;
	i_stream >> l_objectIndex;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) o_value.m_gameObject = l_playLayer->getGameObject(l_objectIndex);
	SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUEnterEffectInstance,m_gameObject) + sizeof(GameObject*), 28);
	VEC_SEPARATOR_I
	i_stream >> o_value.m_unkVecInt;
	VEC_SEPARATOR_I
	i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PUEnterEffectInstance,m_unkVecInt) + sizeof(gd::vector<int>), 4);
	SEPARATOR_I
}

inline void persistenceUtils::operator<<(OutputStream& o_stream, PUEnterEffectInstance& i_value) {
	MAP_SEPARATOR_O
	o_stream << i_value.m_enterEffectAnimMap;
	MAP_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUEnterEffectInstance,m_enterEffectAnimMap) + sizeof(gd::map<int,EnterEffectAnimValue>), 140);
	SEPARATOR_O
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(i_value.m_gameObject);
	o_stream << l_objectIndex;
	SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUEnterEffectInstance,m_gameObject) + sizeof(GameObject*), 28);
	VEC_SEPARATOR_O
	o_stream << i_value.m_unkVecInt;
	VEC_SEPARATOR_O
	o_stream.write(reinterpret_cast<char*>(&i_value) + offsetof(PUEnterEffectInstance,m_unkVecInt) + sizeof(gd::vector<int>), 4);
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUEnterEffectInstance::describe() {
	int i = 0;
	for (std::pair<int, EnterEffectAnimValue> l_pair : m_enterEffectAnimMap) {
		log::info("[PUEnterEffectInstance - describe] m_enterEffectAnimMap element {} key: {}", i, l_pair.first);
		log::info("[PUEnterEffectInstance - describe] m_enterEffectAnimMap element {} value: [{}]", i, hexStr(reinterpret_cast<uint8_t*>(&l_pair.second), 32));
		i++;
	}
	log::info("[PUEnterEffectInstance - describe] pad_1: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUEnterEffectInstance,m_enterEffectAnimMap) + sizeof(gd::map<int,EnterEffectAnimValue>), 140));
	int l_objectIndex = -1;
	PUPlayLayer* l_playLayer = static_cast<PUPlayLayer*>(PlayLayer::get());
	if (l_playLayer) l_objectIndex = l_playLayer->getGameObjectIndex(m_gameObject);
	log::info("[PUEnterEffectInstance - describe] m_gameObject l_objectIndex: {}", l_objectIndex);
	log::info("[PUEnterEffectInstance - describe] pad_2: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUEnterEffectInstance,m_gameObject) + sizeof(GameObject*), 28));
	int l_size = m_unkVecInt.size();
	log::info("[PUEnterEffectInstance - describe] m_unkVecInt.size(): {}", l_size);
	for (int i = 0; i < l_size; i++) {
		log::info("[PUEnterEffectInstance - describe] m_unkVecInt[{}]: {}", i, m_unkVecInt[i]);
	}
	log::info("[PUEnterEffectInstance - describe] pad_3: [{}]", hexStr(reinterpret_cast<unsigned char*>(this) + offsetof(PUEnterEffectInstance,m_unkVecInt) + sizeof(gd::vector<int>), 4));
}
#endif