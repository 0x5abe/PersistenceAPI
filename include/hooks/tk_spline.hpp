#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/tk_spline.hpp"
#include "util/Stream.hpp"
#include "import_export.hpp"

namespace persistenceAPI {
	class $modify(PAtk_spline, tk_spline) {
	protected:
		friend void operator>>(persistenceAPI::Stream& i_stream, PAtk_spline& o_value);
		friend void operator<<(persistenceAPI::Stream& o_stream, PAtk_spline& i_value);

	public:
		SABE_PA_DLL void load(persistenceAPI::Stream& i_stream);
		SABE_PA_DLL void save(persistenceAPI::Stream& o_stream);

	#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
		SABE_PA_DLL void describe();
	#endif
	};
}