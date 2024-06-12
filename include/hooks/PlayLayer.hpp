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
		if (i_object == nullptr) return -1;

		int l_index = i_object->m_uniqueID-m_fields->m_uniqueIdBase;
		if (l_index > -1) {
			return l_index;
		}
		l_index = m_objects->indexOfObject(i_object);
		if (l_index > -1) {
			return l_index;
		}
		if (i_object == m_player1) {
			return -2;
		}
		if (i_object == m_player2) {
			return -3;
		}
		geode::log::info("@@@@@@@@@@@@@@ UNKNOWN GAMEOBJECT BEING SAVED @@@@@@@@@@@@@@@");
		return -404;
	}

	GameObject* getGameObject(int i_index) {
		if (i_index > -1) {
			return static_cast<GameObject*>(m_objects->objectAtIndex(i_index));
		}
		if (i_index == -2) {
			return m_player1;
		}
		if (i_index == -3) {
			return m_player2;
		}
		if (i_index == -404) {
			geode::log::info("@@@@@@@@@@@@@@ UNKNOWN GAMEOBJECT BEING LOADED @@@@@@@@@@@@@@@");
		}
		return nullptr;
	}
};