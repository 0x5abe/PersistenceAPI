#include "hooks/FMODAudioState.hpp"
#include "Geode/binding/FMODQueuedMusic.hpp"
#include "Geode/binding/FMODSoundState.hpp"
#include "Geode/binding/FMODSoundTween.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "hooks/FMODQueuedMusic.hpp"
#include "hooks/FMODSoundState.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAFMODAudioState::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAFMODAudioState::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAFMODAudioState& o_value) {
	i_stream >> o_value.m_unkFloat1;
	SEPARATOR_I
	i_stream >> o_value.m_unkFloat2;
	MAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapPairIntIntFMODSoundTween1;
	MAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapPairIntIntFMODSoundTween2;
	MAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapPairIntIntFMODSoundTween3;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFloat1;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFloat2;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFloat3;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFloat4;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFloat5;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFloat6;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFloat7;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFloat8;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFloat9;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFloat10;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFMODQueuedMusic1;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFMODQueuedMusic2;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkMapIntFMODSoundState;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkInt1;
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAFMODAudioState& i_value) {
	o_stream << i_value.m_unkFloat1;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat2;
	MAP_SEPARATOR_O
	o_stream << i_value.m_unkMapPairIntIntFMODSoundTween1;
	MAP_SEPARATOR_O
	o_stream << i_value.m_unkMapPairIntIntFMODSoundTween2;
	MAP_SEPARATOR_O
	o_stream << i_value.m_unkMapPairIntIntFMODSoundTween3;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFloat1;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFloat2;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFloat3;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFloat4;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFloat5;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFloat6;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFloat7;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFloat8;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFloat9;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFloat10;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFMODQueuedMusic1;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFMODQueuedMusic2;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkMapIntFMODSoundState;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkInt1;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAFMODAudioState::describe() {
	log::info("[PAFMODAudioState - describe] m_unkFloat1", m_unkFloat1);
	log::info("[PAFMODAudioState - describe] m_unkFloat2", m_unkFloat2);
	int l_size = m_unkMapPairIntIntFMODSoundTween1.size();
	log::info("[PAFMODAudioState - describe] m_unkMapPairIntIntFMODSoundTween1.size(): {}", l_size);
	int i = 0;
	for (std::pair<std::pair<int,int>, FMODSoundTween> l_pair : m_unkMapPairIntIntFMODSoundTween1) {
		log::info("[PAFMODAudioState - describe] m_unkMapPairIntIntFMODSoundTween1 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapPairIntIntFMODSoundTween1 element {} value (FMODSoundTween): [{}]", i, hexStr(reinterpret_cast<uint8_t*>(&l_pair.second), 40));
		i++;
	}
	l_size = m_unkMapPairIntIntFMODSoundTween2.size();
	log::info("[PAFMODAudioState - describe] m_unkMapPairIntIntFMODSoundTween2.size(): {}", l_size);
	i = 0;
	for (std::pair<std::pair<int,int>, FMODSoundTween> l_pair : m_unkMapPairIntIntFMODSoundTween2) {
		log::info("[PAFMODAudioState - describe] m_unkMapPairIntIntFMODSoundTween2 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapPairIntIntFMODSoundTween2 element {} value (FMODSoundTween): [{}]", i, hexStr(reinterpret_cast<uint8_t*>(&l_pair.second), 40));
		i++;
	}
	l_size = m_unkMapPairIntIntFMODSoundTween3.size();
	log::info("[PAFMODAudioState - describe] m_unkMapPairIntIntFMODSoundTween3.size(): {}", l_size);
	i = 0;
	for (std::pair<std::pair<int,int>, FMODSoundTween> l_pair : m_unkMapPairIntIntFMODSoundTween3) {
		log::info("[PAFMODAudioState - describe] m_unkMapPairIntIntFMODSoundTween3 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapPairIntIntFMODSoundTween3 element {} value (FMODSoundTween): [{}]", i, hexStr(reinterpret_cast<uint8_t*>(&l_pair.second), 40));
		i++;
	}
	l_size = m_unkMapIntFloat1.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFloat1.size(): {}", l_size);
	i = 0;
	for (std::pair<int, float> l_pair : m_unkMapIntFloat1) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat1 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat1 element {} value {}", i, l_pair.second);
		i++;
	}
	l_size = m_unkMapIntFloat2.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFloat1.size(): {}", l_size);
	i = 0;
	for (std::pair<int, float> l_pair : m_unkMapIntFloat2) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat2 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat2 element {} value {}", i, l_pair.second);
		i++;
	}
	l_size = m_unkMapIntFloat3.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFloat3.size(): {}", l_size);
	i = 0;
	for (std::pair<int, float> l_pair : m_unkMapIntFloat3) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat3 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat3 element {} value {}", i, l_pair.second);
		i++;
	}
	l_size = m_unkMapIntFloat4.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFloat4.size(): {}", l_size);
	i = 0;
	for (std::pair<int, float> l_pair : m_unkMapIntFloat4) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat4 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat4 element {} value {}", i, l_pair.second);
		i++;
	}
	l_size = m_unkMapIntFloat5.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFloat5.size(): {}", l_size);
	i = 0;
	for (std::pair<int, float> l_pair : m_unkMapIntFloat5) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat5 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat5 element {} value {}", i, l_pair.second);
		i++;
	}
	l_size = m_unkMapIntFloat6.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFloat6.size(): {}", l_size);
	i = 0;
	for (std::pair<int, float> l_pair : m_unkMapIntFloat6) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat6 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat6 element {} value {}", i, l_pair.second);
		i++;
	}
	l_size = m_unkMapIntFloat7.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFloat1.size(): {}", l_size);
	i = 0;
	for (std::pair<int, float> l_pair : m_unkMapIntFloat7) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat7 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat7 element {} value {}", i, l_pair.second);
		i++;
	}
		l_size = m_unkMapIntFloat8.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFloat8.size(): {}", l_size);
	i = 0;
	for (std::pair<int, float> l_pair : m_unkMapIntFloat8) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat8 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat8 element {} value {}", i, l_pair.second);
		i++;
	}
	l_size = m_unkMapIntFloat9.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFloat9.size(): {}", l_size);
	i = 0;
	for (std::pair<int, float> l_pair : m_unkMapIntFloat9) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat9 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat9 element {} value {}", i, l_pair.second);
		i++;
	}
	l_size = m_unkMapIntFloat10.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFloat10.size(): {}", l_size);
	i = 0;
	for (std::pair<int, float> l_pair : m_unkMapIntFloat10) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat10 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFloat10 element {} value {}", i, l_pair.second);
		i++;
	}
	l_size = m_unkMapIntFMODQueuedMusic1.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFMODQueuedMusic1.size(): {}", l_size);
	i = 0;
	for (std::pair<int, FMODQueuedMusic> l_pair : m_unkMapIntFMODQueuedMusic1) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFMODQueuedMusic1 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFMODQueuedMusic1 element {} value:", i);
		reinterpret_cast<PAFMODQueuedMusic*>(&l_pair.second)->describe();
	}
	l_size = m_unkMapIntFMODQueuedMusic2.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFMODQueuedMusic2.size(): {}", l_size);
	i = 0;
	for (std::pair<int, FMODQueuedMusic> l_pair : m_unkMapIntFMODQueuedMusic2) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFMODQueuedMusic2 element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFMODQueuedMusic2 element {} value:", i);
		reinterpret_cast<PAFMODQueuedMusic*>(&l_pair.second)->describe();
	}
	l_size = m_unkMapIntFMODSoundState.size();
	log::info("[PAFMODAudioState - describe] m_unkMapIntFMODSoundState.size(): {}", l_size);
	i = 0;
	for (std::pair<int, FMODSoundState> l_pair : m_unkMapIntFMODSoundState) {
		log::info("[PAFMODAudioState - describe] m_unkMapIntFMODSoundState element {} key: {}", i, l_pair.first);
		log::info("[PAFMODAudioState - describe] m_unkMapIntFMODSoundState element {} value:", i);
		reinterpret_cast<PAFMODSoundState*>(&l_pair.second)->describe();
	}
	log::info("[PAFMODAudioState - describe] m_unkInt1", m_unkInt1);
}
#endif