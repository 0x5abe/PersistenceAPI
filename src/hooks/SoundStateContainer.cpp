#include "hooks/SoundStateContainer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASoundStateContainer::load(Stream& i_stream) {
	i_stream >> *this;
}

void PASoundStateContainer::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASoundStateContainer& o_value) {
	i_stream >> o_value.m_fadePointCount;
	SEPARATOR_I
	i_stream >> o_value.m_fadePointVolumes[0];
	SEPARATOR_I
	i_stream >> o_value.m_fadePointVolumes[1];
	SEPARATOR_I
	i_stream >> o_value.m_fadePointVolumes[2];
	SEPARATOR_I
	i_stream >> o_value.m_fadePointVolumes[3];
	SEPARATOR_I
	i_stream >> o_value.m_fadePointOffsets[0];
	SEPARATOR_I
	i_stream >> o_value.m_fadePointOffsets[1];
	SEPARATOR_I
	i_stream >> o_value.m_fadePointOffsets[2];
	SEPARATOR_I
	i_stream >> o_value.m_fadePointOffsets[3];
	SEPARATOR_I
	i_stream >> o_value.m_currentOffset;
	SEPARATOR_I
	i_stream >> o_value.m_loopStartMs;
	SEPARATOR_I
	i_stream >> o_value.m_loopEndMs;
	SEPARATOR_I
	i_stream >> o_value.m_currentMs;
	SEPARATOR_I
	i_stream >> o_value.m_playStartOffset;
	SEPARATOR_I
	i_stream >> o_value.m_playEndOffset;
	SEPARATOR_I
	i_stream >> o_value.m_usePlayOffsets;
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASoundStateContainer& i_value) {
	o_stream << i_value.m_fadePointCount;
	SEPARATOR_O
	o_stream << i_value.m_fadePointVolumes[0];
	SEPARATOR_O
	o_stream << i_value.m_fadePointVolumes[1];
	SEPARATOR_O
	o_stream << i_value.m_fadePointVolumes[2];
	SEPARATOR_O
	o_stream << i_value.m_fadePointVolumes[3];
	SEPARATOR_O
	o_stream << i_value.m_fadePointOffsets[0];
	SEPARATOR_O
	o_stream << i_value.m_fadePointOffsets[1];
	SEPARATOR_O
	o_stream << i_value.m_fadePointOffsets[2];
	SEPARATOR_O
	o_stream << i_value.m_fadePointOffsets[3];
	SEPARATOR_O
	o_stream << i_value.m_currentOffset;
	SEPARATOR_O
	o_stream << i_value.m_loopStartMs;
	SEPARATOR_O
	o_stream << i_value.m_loopEndMs;
	SEPARATOR_O
	o_stream << i_value.m_currentMs;
	SEPARATOR_O
	o_stream << i_value.m_playStartOffset;
	SEPARATOR_O
	o_stream << i_value.m_playEndOffset;
	SEPARATOR_O
	o_stream << i_value.m_usePlayOffsets;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASoundStateContainer::describe() {
	log::info("[PASoundStateContainer - describe] m_fadePointCount: {}", m_fadePointCount);
	for (int i = 0; i < m_fadePointCount; i++) {
		log::info("[PASoundStateContainer - describe] m_fadePointVolumes[{}]: {}", i, m_fadePointVolumes[i]);
	}
	for (int i = 0; i < m_fadePointCount; i++) {
		log::info("[PASoundStateContainer - describe] m_fadePointOffsets[{}]: {}", i, m_fadePointOffsets[i]);
	}
	log::info("[PASoundStateContainer - describe] m_currentOffset: {}", m_currentOffset);
	log::info("[PASoundStateContainer - describe] m_loopStartMs: {}", m_loopStartMs);
	log::info("[PASoundStateContainer - describe] m_loopEndMs: {}", m_loopEndMs);
	log::info("[PASoundStateContainer - describe] m_currentMs: {}", m_currentMs);
	log::info("[PASoundStateContainer - describe] m_playStartOffset: {}", m_playStartOffset);
	log::info("[PASoundStateContainer - describe] m_playEndOffset: {}", m_playEndOffset);
	log::info("[PASoundStateContainer - describe] m_usePlayOffsets: {}", m_usePlayOffsets);
}
#endif