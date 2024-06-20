#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/EventTriggerInstance.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceAPI {
	class $modify(PAEventTriggerInstance, EventTriggerInstance) {
	protected:
		friend void operator>>(persistenceAPI::InputStream& i_stream, PAEventTriggerInstance& o_value);
		friend void operator<<(persistenceAPI::OutputStream& o_stream, PAEventTriggerInstance& i_value);

	public:
		SABE_PU_DLL void load(persistenceAPI::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceAPI::OutputStream& o_stream);
		
	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}