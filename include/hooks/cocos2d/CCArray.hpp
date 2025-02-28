#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/CCArray.hpp"
#include "../../util/Stream.hpp"
#include "../../import_export.hpp"

namespace persistenceAPI {
	class $modify(PACCArray, cocos2d::CCArray) {
	public:
		template <typename T>
		SABE_PA_DLL void load(persistenceAPI::Stream& i_stream);

		template <typename T>
		SABE_PA_DLL void save(persistenceAPI::Stream& o_stream);

		template <typename T>
		void loadOne(persistenceAPI::Stream& o_stream);

		template <typename T>
		void saveOne(persistenceAPI::Stream& o_stream, unsigned int i_index);

		template <>
		SABE_PA_DLL void load<GradientTriggerObject>(persistenceAPI::Stream& i_stream);

		template <>
		SABE_PA_DLL void save<GradientTriggerObject>(persistenceAPI::Stream& o_stream);

	#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
		template <class T>
		SABE_PA_DLL void describe();

		template <>
		SABE_PA_DLL void describe<GradientTriggerObject>();
	#endif
	};
}