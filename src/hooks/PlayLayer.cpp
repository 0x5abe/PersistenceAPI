#include "hooks/PlayLayer.hpp"

using namespace geode::prelude;
using namespace persistenceUtils;

// overrides

bool persistenceUtils::PUPlayLayer::init(GJGameLevel* i_level, bool i_useReplay, bool i_dontCreateObjects) {
	// reset uniqueID global to save/load GameObjects correctly using their index
	// should look into not having to do this but it's harder than it looks since there's 
	// probably maps with object id as keys, it's not just us saving pointers so I'd have to find those.
	*reinterpret_cast<int*>(geode::base::get()+0x67f158) = 10;
	m_fields->m_uniqueIdBase = *reinterpret_cast<int*>(geode::base::get()+0x67f158) + 2;

	if (!PlayLayer::init(i_level, i_useReplay, i_dontCreateObjects)) return false;

	return true;
}