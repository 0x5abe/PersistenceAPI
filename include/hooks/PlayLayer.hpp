#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/PlayLayer.hpp"

class $modify(PUPlayLayer, PlayLayer) {
public:
	struct Fields {
		int m_uniqueIdBase = 12;
	};

	// overrides

	$override
	bool init(GJGameLevel* i_level, bool i_useReplay, bool i_dontCreateObjects);
	
	// custom methods

	inline int getGameObjectIndex(GameObject* i_object) {
		int l_index = i_object->m_uniqueID-m_fields->m_uniqueIdBase;
		if (l_index > -1) {
			return l_index;
		}
		return m_objects->indexOfObject(i_object);
	}
};