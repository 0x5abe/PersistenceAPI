#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/GroupCommandObject2.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceUtils {
	class $modify(PUGroupCommandObject2, GroupCommandObject2) {
	protected:
		friend void operator>>(persistenceUtils::InputStream& i_stream, PUGroupCommandObject2& o_value);
		friend void operator<<(persistenceUtils::OutputStream& o_stream, PUGroupCommandObject2& i_value);

	public:
		SABE_PU_DLL void load(persistenceUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceUtils::OutputStream& o_stream);
		
	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}