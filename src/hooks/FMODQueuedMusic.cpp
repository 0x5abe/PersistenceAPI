#include "hooks/FMODQueuedMusic.hpp"
#include "Geode/binding/FMODAudioEngine.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAFMODQueuedMusic::load(Stream& i_stream) {
	i_stream >> *this;
}

void PAFMODQueuedMusic::save(Stream& o_stream) {
	o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAFMODQueuedMusic& o_value) {
	STR_SEPARATOR_I
	i_stream >> o_value.m_filePath;
	STR_SEPARATOR_I
	if (i_stream.getPAVersion() > 1) {
		i_stream >> o_value.m_unkFloat1;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat2;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat3;
		SEPARATOR_I
		i_stream >> o_value.m_unkInt1;
		SEPARATOR_I
		i_stream >> o_value.m_unkInt2;
		SEPARATOR_I
		i_stream >> o_value.m_unkInt3;
		SEPARATOR_I
		i_stream >> o_value.m_unkInt4;
		SEPARATOR_I
		i_stream >> o_value.m_unkBool1;
		SEPARATOR_I
		i_stream >> o_value.m_keyForFMODMusicMap1;
		SEPARATOR_I
		i_stream >> o_value.m_unkBool2;
		SEPARATOR_I
		i_stream >> o_value.m_keyForFMODMusicMap2;
		SEPARATOR_I
		i_stream >> o_value.m_unkBool3;
		SEPARATOR_I
		i_stream >> o_value.m_unkFloat4;
		SEPARATOR_I
		int l_dummy;
		i_stream >> l_dummy;
		if (l_dummy == -1) {
			//TODO: This may be wrong
			o_value.m_sound = FMODAudioEngine::get()->preloadMusic(o_value.m_filePath, true, o_value.m_keyForFMODMusicMap1);
		} else {
			//geode::log::info("!!!!!!!!!!!!!!!!!!! NOT Trying to load FMODQueuedMusic with preloadMusic CAUSE it was nullptr");
			o_value.m_sound = nullptr;
		}
		SEPARATOR_I
		i_stream >> o_value.m_dontReset;
	} else {
		i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAFMODQueuedMusic,m_filePath) + sizeof(gd::string), 56);
	}
	SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAFMODQueuedMusic& i_value) {
	STR_SEPARATOR_O
	o_stream << i_value.m_filePath;
	STR_SEPARATOR_O
	o_stream << i_value.m_unkFloat1;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat2;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat3;
	SEPARATOR_O
	o_stream << i_value.m_unkInt1;
	SEPARATOR_O
	o_stream << i_value.m_unkInt2;
	SEPARATOR_O
	o_stream << i_value.m_unkInt3;
	SEPARATOR_O
	o_stream << i_value.m_unkInt4;
	SEPARATOR_O
	o_stream << i_value.m_unkBool1;
	SEPARATOR_O
	o_stream << i_value.m_keyForFMODMusicMap1;
	SEPARATOR_O
	o_stream << i_value.m_unkBool2;
	SEPARATOR_O
	o_stream << i_value.m_keyForFMODMusicMap2;
	SEPARATOR_O
	o_stream << i_value.m_unkBool3;
	SEPARATOR_O
	o_stream << i_value.m_unkFloat4;
	SEPARATOR_O
	int l_dummy;
	if (i_value.m_sound == nullptr) {
		l_dummy = -2;
	} else {
		l_dummy = -1;
	}
	o_stream << l_dummy;
	SEPARATOR_O
	o_stream << i_value.m_dontReset;
	SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAFMODQueuedMusic::describe() {
	log::info("[PAFMODQueuedMusic - describe] m_filePath: {}", m_filePath);
	log::info("[PAFMODQueuedMusic - describe] m_unkFloat1: {}", m_unkFloat1);
	log::info("[PAFMODQueuedMusic - describe] m_unkFloat2: {}", m_unkFloat2);
	log::info("[PAFMODQueuedMusic - describe] m_unkFloat3: {}", m_unkFloat3);
	log::info("[PAFMODQueuedMusic - describe] m_unkInt1: {}", m_unkInt1);
	log::info("[PAFMODQueuedMusic - describe] m_unkInt2: {}", m_unkInt2);
	log::info("[PAFMODQueuedMusic - describe] m_unkInt3: {}", m_unkInt3);
	log::info("[PAFMODQueuedMusic - describe] m_unkInt4: {}", m_unkInt4);
	log::info("[PAFMODQueuedMusic - describe] m_unkBool1: {}", m_unkBool1);
	log::info("[PAFMODQueuedMusic - describe] m_keyForFMODMusicMap1: {}", m_keyForFMODMusicMap1);
	log::info("[PAFMODQueuedMusic - describe] m_unkBool2: {}", m_unkBool2);
	log::info("[PAFMODQueuedMusic - describe] m_keyForFMODMusicMap2: {}", m_keyForFMODMusicMap2);
	log::info("[PAFMODQueuedMusic - describe] m_unkBool3: {}", m_unkBool3);
	log::info("[PAFMODQueuedMusic - describe] m_unkFloat4: {}", m_unkFloat4);
	log::info("[PAFMODQueuedMusic - describe] m_sound: {}", *reinterpret_cast<size_t*>(&m_sound));
	log::info("[PAFMODQueuedMusic - describe] m_dontReset: {}", m_dontReset);
}
#endif