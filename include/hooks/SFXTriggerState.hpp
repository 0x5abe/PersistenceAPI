#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/SFXTriggerState.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceUtils {
	class $modify(PUSFXTriggerState, SFXTriggerState) {
	protected:
		friend void operator>>(persistenceUtils::InputStream& i_stream, PUSFXTriggerState& o_value);
		friend void operator<<(persistenceUtils::OutputStream& o_stream, PUSFXTriggerState& i_value);

	public:
		SABE_PU_DLL void load(persistenceUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceUtils::OutputStream& o_stream);

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}