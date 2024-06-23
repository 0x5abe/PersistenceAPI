#include "hooks/CAState.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PACAState::load(InputStream& i_stream) {
	i_stream >> *this;
}

void PACAState::save(OutputStream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(InputStream& i_stream, PACAState& o_value) {
	i_stream.read(reinterpret_cast<char*>(&o_value), 68);
	SEPARATOR_I;
}

inline void persistenceAPI::operator<<(OutputStream& o_stream, PACAState& i_value) {
	o_stream.write(reinterpret_cast<char*>(&i_value), 68);
	SEPARATOR_O;
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PACAState::describe() {
}
#endif