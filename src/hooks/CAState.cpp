#include "hooks/CAState.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

void PUCAState::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PUCAState::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceUtils::operator>>(InputStream& i_stream, PUCAState& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 68);
	SEPARATOR_I;
}

inline void persistenceUtils::operator<<(OutputStream& o_stream, PUCAState& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 68);
	SEPARATOR_O;
}

#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
void PUCAState::describe() {
}
#endif