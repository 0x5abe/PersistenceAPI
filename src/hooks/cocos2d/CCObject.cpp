#include "hooks/cocos2d/CCObject.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

void PUCCObject::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUCCObject::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceUtils::operator>>(InputStream& i_stream, PUCCObject& o_value) {
	i_stream >> (int&)(o_value.m_eObjType);
	SEPARATOR_I
	i_stream >> o_value.m_nZOrder;
	SEPARATOR_I
	i_stream >> o_value.m_uOrderOfArrival;
	SEPARATOR_I
}

inline void persistenceUtils::operator<<(OutputStream& o_stream, PUCCObject& i_value) {
	o_stream << (int&)(i_value.m_eObjType);
	SEPARATOR_O
	o_stream << i_value.m_nZOrder;
	SEPARATOR_O
	o_stream << i_value.m_uOrderOfArrival;
	SEPARATOR_O
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUCCObject::describe() {
	log::info("[PUCCObject - describe] m_eObjType: {}", static_cast<int>(m_eObjType));
	log::info("[PUCCObject - describe] m_nZOrder: {}", m_nZOrder);
	log::info("[PUCCObject - describe] m_uOrderOfArrival: {}", m_uOrderOfArrival);
}
#endif