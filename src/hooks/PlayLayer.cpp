#include "hooks/PlayLayer.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

#if defined(GEODE_IS_WINDOWS)
	#define UNIQUE_ID_OFFSET 0x69c158
#elif  defined(GEODE_IS_ANDROID64)
	#define UNIQUE_ID_OFFSET 0x11fe018
#elif  defined(GEODE_IS_ANDROID32)
	#define UNIQUE_ID_OFFSET 0xa9f00c
#endif

// overrides

bool persistenceAPI::PAPlayLayer::init(GJGameLevel* i_level, bool i_useReplay, bool i_dontCreateObjects) {
	// reset uniqueID global to save/load GameObjects correctly using their index
	// should look into not having to do this but it's harder than it looks since there's 
	// probably maps with object id as keys, it's not just us saving pointers so I'd have to find those.

	*reinterpret_cast<int*>(geode::base::get()+UNIQUE_ID_OFFSET) = 10;
	m_fields->m_uniqueIDBase = *reinterpret_cast<int*>(geode::base::get()+UNIQUE_ID_OFFSET) + 2;

	if (!PlayLayer::init(i_level, i_useReplay, i_dontCreateObjects)) return false;

	return true;
}