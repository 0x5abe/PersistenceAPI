#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/PlayerCheckpoint.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceUtils {
	class $modify(PUPlayerCheckpoint, PlayerCheckpoint) {
	protected:
		friend void operator>>(persistenceUtils::InputStream& i_stream, PUPlayerCheckpoint& o_value);
		friend void operator<<(persistenceUtils::OutputStream& o_stream, PUPlayerCheckpoint& i_value);

	public:
		SABE_PU_DLL void load(persistenceUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceUtils::OutputStream& o_stream);

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}