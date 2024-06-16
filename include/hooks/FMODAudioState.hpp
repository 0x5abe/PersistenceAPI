#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/FMODAudioState.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceUtils {
	class $modify(PUFMODAudioState, FMODAudioState) {
	protected:
		friend void operator>>(persistenceUtils::InputStream& i_stream, PUFMODAudioState& o_value);
		friend void operator<<(persistenceUtils::OutputStream& o_stream, PUFMODAudioState& i_value);

	public:
		SABE_PU_DLL void load(persistenceUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceUtils::OutputStream& o_stream);
		
	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}