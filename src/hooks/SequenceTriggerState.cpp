#include "hooks/SequenceTriggerState.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PASequenceTriggerState::load(Stream& i_stream) {
	i_stream >> *this;
}

void PASequenceTriggerState::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PASequenceTriggerState& o_value) {
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkUnorderedMap1;
	UMAP_SEPARATOR_I
	i_stream >> o_value.m_unkUnorderedMap2;
	UMAP_SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASequenceTriggerState& i_value) {
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkUnorderedMap1;
	UMAP_SEPARATOR_O
	o_stream << i_value.m_unkUnorderedMap2;
	UMAP_SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASequenceTriggerState::describe() {
	int l_size = m_unkUnorderedMap1.size();
	log::info("[PASequenceTriggerState - describe] m_unkUnorderedMap1.size(): {}", l_size);
	int i = 0;
	for (std::pair<int,float> l_pair : m_unkUnorderedMap1) {
		log::info("[PASequenceTriggerState - describe] m_unkUnorderedMap1 element {} key: {}", i, l_pair.first);
		log::info("[PASequenceTriggerState - describe] m_unkUnorderedMap1 element {} value: {}", i, l_pair.second);
		i++;
	}
	l_size = m_unkUnorderedMap2.size();
	log::info("[PASequenceTriggerState - describe] m_unkUnorderedMap2.size(): {}", l_size);
	i = 0;
	for (std::pair<int,int> l_pair : m_unkUnorderedMap2) {
		log::info("[PASequenceTriggerState - describe] m_unkUnorderedMap2 element {} key: {}", i, l_pair.first);
		log::info("[PASequenceTriggerState - describe] m_unkUnorderedMap2 element {} value: {}", i, l_pair.second);
		i++;
	}
}
#endif