#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/ActiveSaveObject1.hpp"
#include "Geode/modify/ActiveSaveObject2.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceUtils {
	class $modify(PUActiveSaveObject1, ActiveSaveObject1) {
	public:
		friend void operator>>(persistenceUtils::InputStream& i_stream, persistenceUtils::PUActiveSaveObject1& o_value);
		friend void operator<<(persistenceUtils::OutputStream& o_stream, persistenceUtils::PUActiveSaveObject1& i_value);

	public:
		SABE_PU_DLL void load(persistenceUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceUtils::OutputStream& o_stream);

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};

	class $modify(PUActiveSaveObject2, ActiveSaveObject2) {
	public:
		friend void operator>>(persistenceUtils::InputStream& i_stream, persistenceUtils::PUActiveSaveObject2& o_value);
		friend void operator<<(persistenceUtils::OutputStream& o_stream, persistenceUtils::PUActiveSaveObject2& i_value);

	public:
		SABE_PU_DLL void load(persistenceUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceUtils::OutputStream& o_stream);

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}