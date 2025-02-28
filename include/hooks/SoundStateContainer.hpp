#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/SoundStateContainer.hpp"
#include "../util/Stream.hpp"
#include "../import_export.hpp"

namespace persistenceAPI {
	class $modify(PASoundStateContainer, SoundStateContainer) {
	protected:
		friend void operator>>(persistenceAPI::Stream& i_stream, PASoundStateContainer& o_value);
		friend void operator<<(persistenceAPI::Stream& o_stream, PASoundStateContainer& i_value);

	public:
		SABE_PA_DLL void load(persistenceAPI::Stream& i_stream);
		SABE_PA_DLL void save(persistenceAPI::Stream& o_stream);

	#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
		SABE_PA_DLL void describe();
	#endif
	};
}