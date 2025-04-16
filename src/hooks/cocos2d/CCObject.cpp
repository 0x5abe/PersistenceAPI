#include "hooks/cocos2d/CCObject.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PACCObject::load(Stream& i_stream) {
    i_stream >> *this;
}

void PACCObject::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PACCObject& o_value) {
    i_stream >> (int&)(o_value.m_eObjType);
    SEPARATOR_I
    i_stream >> o_value.m_nZOrder;
    SEPARATOR_I
    i_stream >> o_value.m_uOrderOfArrival;
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PACCObject& i_value) {
    o_stream << (int&)(i_value.m_eObjType);
    SEPARATOR_O
    o_stream << i_value.m_nZOrder;
    SEPARATOR_O
    o_stream << i_value.m_uOrderOfArrival;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PACCObject::describe() {
    log::info("[PACCObject - describe] m_eObjType: {}", static_cast<int>(m_eObjType));
    log::info("[PACCObject - describe] m_nZOrder: {}", m_nZOrder);
    log::info("[PACCObject - describe] m_uOrderOfArrival: {}", m_uOrderOfArrival);
}
#endif