#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/ActiveSaveObject1.hpp"
#include "Geode/modify/ActiveSaveObject2.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceAPI {
	class $modify(PAActiveSaveObject1, ActiveSaveObject1) {
	public:
		friend void operator>>(persistenceAPI::InputStream& i_stream, persistenceAPI::PAActiveSaveObject1& o_value);
		friend void operator<<(persistenceAPI::OutputStream& o_stream, persistenceAPI::PAActiveSaveObject1& i_value);

	public:
		SABE_PA_DLL void load(persistenceAPI::InputStream& i_stream);
		SABE_PA_DLL void save(persistenceAPI::OutputStream& o_stream);

	#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
		SABE_PA_DLL void describe();
	#endif
	};

	class $modify(PAActiveSaveObject2, ActiveSaveObject2) {
	public:
		friend void operator>>(persistenceAPI::InputStream& i_stream, persistenceAPI::PAActiveSaveObject2& o_value);
		friend void operator<<(persistenceAPI::OutputStream& o_stream, persistenceAPI::PAActiveSaveObject2& i_value);

	public:
		SABE_PA_DLL void load(persistenceAPI::InputStream& i_stream);
		SABE_PA_DLL void save(persistenceAPI::OutputStream& o_stream);

	#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
		SABE_PA_DLL void describe();
	#endif
	};
}