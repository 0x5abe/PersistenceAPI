#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/DynamicObjectAction.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceUtils {
	class $modify(PUDynamicObjectAction, DynamicObjectAction) {
	public:
		friend void operator>>(persistenceUtils::InputStream& i_stream, PUDynamicObjectAction& o_value);
		friend void operator<<(persistenceUtils::OutputStream& o_stream, PUDynamicObjectAction& i_value);

	public:
		SABE_PU_DLL void load(persistenceUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceUtils::OutputStream& o_stream);

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}