#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/SequenceTriggerState.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceAPI {
	class $modify(PASequenceTriggerState, SequenceTriggerState) {
	protected:
		friend void operator>>(persistenceAPI::InputStream& i_stream, PASequenceTriggerState& o_value);
		friend void operator<<(persistenceAPI::OutputStream& o_stream, PASequenceTriggerState& i_value);

	public:
		SABE_PU_DLL void load(persistenceAPI::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceAPI::OutputStream& o_stream);

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}