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
    i_stream >> o_value.m_sequenceTimes;
    UMAP_SEPARATOR_I
    i_stream >> o_value.m_sequenceIndices;
    UMAP_SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PASequenceTriggerState& i_value) {
    UMAP_SEPARATOR_O
    o_stream << i_value.m_sequenceTimes;
    UMAP_SEPARATOR_O
    o_stream << i_value.m_sequenceIndices;
    UMAP_SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PASequenceTriggerState::describe() {
    int l_size = m_sequenceTimes.size();
    log::info("[PASequenceTriggerState - describe] m_sequenceTimes.size(): {}", l_size);
    int i = 0;
    for (gd::pair<int,float> l_pair : m_sequenceTimes) {
        log::info("[PASequenceTriggerState - describe] m_sequenceTimes element {} key: {}", i, l_pair.first);
        log::info("[PASequenceTriggerState - describe] m_sequenceTimes element {} value: {}", i, l_pair.second);
        i++;
    }
    l_size = m_sequenceIndices.size();
    log::info("[PASequenceTriggerState - describe] m_sequenceIndices.size(): {}", l_size);
    i = 0;
    for (gd::pair<int,int> l_pair : m_sequenceIndices) {
        log::info("[PASequenceTriggerState - describe] m_sequenceIndices element {} key: {}", i, l_pair.first);
        log::info("[PASequenceTriggerState - describe] m_sequenceIndices element {} value: {}", i, l_pair.second);
        i++;
    }
}
#endif