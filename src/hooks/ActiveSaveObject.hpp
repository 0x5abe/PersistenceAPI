#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/ActiveSaveObject1.hpp"
#include "Geode/modify/ActiveSaveObject2.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistencyUtils {
	class $modify(PUActiveSaveObject1, ActiveSaveObject1) {
	public:
		friend void operator>>(persistencyUtils::InputStream& i_stream, persistencyUtils::PUActiveSaveObject1& o_value);
		friend void operator<<(persistencyUtils::OutputStream& o_stream, persistencyUtils::PUActiveSaveObject1& i_value);

	public:
		SABE_PU_DLL void load(persistencyUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistencyUtils::OutputStream& o_stream);

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};

	class $modify(PUActiveSaveObject2, ActiveSaveObject2) {
	public:
		friend void operator>>(persistencyUtils::InputStream& i_stream, persistencyUtils::PUActiveSaveObject2& o_value);
		friend void operator<<(persistencyUtils::OutputStream& o_stream, persistencyUtils::PUActiveSaveObject2& i_value);

	public:
		SABE_PU_DLL void load(persistencyUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistencyUtils::OutputStream& o_stream);

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}