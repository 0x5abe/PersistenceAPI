#if defined(PU_DEBUG)
#include "util/debug.hpp"

using namespace persistenceAPI;

#if defined(PU_SEPARATORS)
void writeSeparator(std::string i_string, OutputStream& o_stream) {
	o_stream.write(i_string.data(),i_string.length());
}

void readSeparator(std::string o_string, InputStream& i_stream) {
	i_stream.ignore(o_string.length());
}
#endif
#endif