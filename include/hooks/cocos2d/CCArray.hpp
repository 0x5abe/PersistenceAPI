#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/CCArray.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceAPI {
	class $modify(PACCArray, cocos2d::CCArray) {
	public:
		template <typename T>
		SABE_PU_DLL void load(persistenceAPI::InputStream& i_stream);

		template <typename T>
		SABE_PU_DLL void save(persistenceAPI::OutputStream& o_stream);

		template <typename T>
		void loadOne(persistenceAPI::InputStream& o_stream);

		template <typename T>
		void saveOne(persistenceAPI::OutputStream& o_stream, unsigned int i_index);

		template <>
		SABE_PU_DLL void load<GradientTriggerObject>(persistenceAPI::InputStream& i_stream);

		template <>
		SABE_PU_DLL void save<GradientTriggerObject>(persistenceAPI::OutputStream& o_stream);

	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		template <class T>
		SABE_PU_DLL void describe();

		// template <>
		// void describe<PUCheckpointObject>();

		template <>
		void describe<GradientTriggerObject>();
	#endif
	};
}