#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/EffectManagerState.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistencyUtils {
	class $modify(PUEffectManagerState, EffectManagerState) {
	protected:
		friend void operator>>(persistencyUtils::InputStream& i_stream, PUEffectManagerState& o_value);
		friend void operator<<(persistencyUtils::OutputStream& o_stream, PUEffectManagerState& i_value);

	public:
		SABE_PU_DLL void load(persistencyUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistencyUtils::OutputStream& o_stream);

		SABE_PU_DLL void clean();

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}