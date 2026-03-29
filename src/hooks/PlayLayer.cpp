#include "hooks/PlayLayer.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

// overrides

bool persistenceAPI::PAPlayLayer::init(GJGameLevel* i_level, bool i_useReplay, bool i_dontCreateObjects) {
    // reset uniqueID global to save/load GameObjects correctly using their index
    // should look into not having to do this but it's harder than it looks since there's
    // probably maps with object id as keys, it's not just us saving pointers so I'd have to find those.

    GameObject::resetMID();
    m_fields->m_uniqueIDBase = 12;

    if (!PlayLayer::init(i_level, i_useReplay, i_dontCreateObjects)) return false;

    return true;
}