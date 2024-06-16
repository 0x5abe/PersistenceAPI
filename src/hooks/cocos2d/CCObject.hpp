#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/CCObject.hpp"
#include "util/InputStream.hpp"
#include "util/OutputStream.hpp"
#include "import_export.hpp"

namespace persistenceUtils {
	class $modify(PUCCObject, cocos2d::CCObject) {
	protected:
		friend void operator>>(persistenceUtils::InputStream& i_stream, PUCCObject& o_value);
		friend void operator<<(persistenceUtils::OutputStream& o_stream, PUCCObject& i_value);

	public:
		SABE_PU_DLL void load(persistenceUtils::InputStream& i_stream);
		SABE_PU_DLL void save(persistenceUtils::OutputStream& o_stream);
		
	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
		SABE_PU_DLL void describe();
	#endif
	};
}