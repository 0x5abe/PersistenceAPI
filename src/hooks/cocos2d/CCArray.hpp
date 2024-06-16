#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/CCArray.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceUtils {
	class $modify(PUCCArray, cocos2d::CCArray) {
	public:
		template <typename T>
		SABE_PU_DLL void load(persistenceUtils::InputStream& i_stream);

		template <typename T>
		SABE_PU_DLL void save(persistenceUtils::OutputStream& o_stream);

		template <typename T>
		void loadOne(persistenceUtils::InputStream& o_stream);

		template <typename T>
		void saveOne(persistenceUtils::OutputStream& o_stream, unsigned int i_index);

		template <>
		void load<GradientTriggerObject>(persistenceUtils::InputStream& i_stream);

		template <>
		void save<GradientTriggerObject>(persistenceUtils::OutputStream& o_stream);

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