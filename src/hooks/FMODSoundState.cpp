#include "hooks/FMODSoundState.hpp"
#include "hooks/SoundStateContainer.hpp"
#include "hooks/cocos2d/CCNode.hpp"
#include "util/debug.hpp"

using namespace geode::prelude;
using namespace persistenceAPI;

void PAFMODSoundState::load(Stream& i_stream) {
    i_stream >> *this;
}

void PAFMODSoundState::save(Stream& o_stream) {
    o_stream << *this;
}

inline void persistenceAPI::operator>>(Stream& i_stream, PAFMODSoundState& o_value) {
    STR_SEPARATOR_I
    i_stream >> o_value.m_filePath;
    STR_SEPARATOR_I
    if (i_stream.getPAVersion() > 1) {
        i_stream >> o_value.m_speed;
        SEPARATOR_I
        i_stream >> o_value.m_unkFloat1;
        SEPARATOR_I
        i_stream >> o_value.m_volume;
        SEPARATOR_I
        i_stream >> o_value.m_shouldLoop;
        SEPARATOR_I
        i_stream >> o_value.m_channelID;
        SEPARATOR_I
        reinterpret_cast<PASoundStateContainer*>(&o_value.m_soundStateContainer)->load(i_stream);
        SEPARATOR_I
        i_stream >> o_value.m_uniqueID;
        SEPARATOR_I
        i_stream >> o_value.m_sfxGroup;
        SEPARATOR_I
        i_stream >> o_value.m_pitch;
        SEPARATOR_I
        i_stream >> o_value.m_fastFourierTransform;
        SEPARATOR_I
        i_stream >> o_value.m_reverb;
        SEPARATOR_I
        i_stream >> o_value.m_unkInt1;
        SEPARATOR_I
        i_stream >> o_value.m_unkBool1;
        SEPARATOR_I
        i_stream >> o_value.m_keyForFMODMusicMap;
        SEPARATOR_I
        i_stream >> o_value.m_unkBool2;
    }
    else {
        i_stream.read(reinterpret_cast<char*>(&o_value) + offsetof(PAFMODSoundState,m_filePath) + sizeof(gd::string), 156);
    }
    SEPARATOR_I
}

inline void persistenceAPI::operator<<(Stream& o_stream, PAFMODSoundState& i_value) {
    STR_SEPARATOR_O
    o_stream << i_value.m_filePath;
    STR_SEPARATOR_O
    o_stream << i_value.m_speed;
    SEPARATOR_O
    o_stream << i_value.m_unkFloat1;
    SEPARATOR_O
    o_stream << i_value.m_volume;
    SEPARATOR_O
    o_stream << i_value.m_shouldLoop;
    SEPARATOR_O
    o_stream << i_value.m_channelID;
    SEPARATOR_O
    reinterpret_cast<PASoundStateContainer*>(&i_value.m_soundStateContainer)->save(o_stream);
    SEPARATOR_O
    o_stream << i_value.m_uniqueID;
    SEPARATOR_O
    o_stream << i_value.m_sfxGroup;
    SEPARATOR_O
    o_stream << i_value.m_pitch;
    SEPARATOR_O
    o_stream << i_value.m_fastFourierTransform;
    SEPARATOR_O
    o_stream << i_value.m_reverb;
    SEPARATOR_O
    o_stream << i_value.m_unkInt1;
    SEPARATOR_O
    o_stream << i_value.m_unkBool1;
    SEPARATOR_O
    o_stream << i_value.m_keyForFMODMusicMap;
    SEPARATOR_O
    o_stream << i_value.m_unkBool2;
    SEPARATOR_O
}

#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
void PAFMODSoundState::describe() {
    log::info("[PAFMODSoundState - describe] m_filePath: {}", m_filePath);
    log::info("[PAFMODSoundState - describe] m_filePath: {}", m_filePath);
    log::info("[PAFMODSoundState - describe] m_speed: {}", m_speed);
    log::info("[PAFMODSoundState - describe] m_unkFloat1: {}", m_unkFloat1);
    log::info("[PAFMODSoundState - describe] m_volume: {}", m_volume);
    log::info("[PAFMODSoundState - describe] m_shouldLoop: {}", m_shouldLoop);
    log::info("[PAFMODSoundState - describe] m_channelID: {}", m_channelID);
    reinterpret_cast<PASoundStateContainer*>(&m_soundStateContainer)->describe();
    log::info("[PAFMODSoundState - describe] m_uniqueID: {}", m_uniqueID);
    log::info("[PAFMODSoundState - describe] m_sfxGroup: {}", m_sfxGroup);
    log::info("[PAFMODSoundState - describe] m_pitch: {}", m_pitch);
    log::info("[PAFMODSoundState - describe] m_fastFourierTransform: {}", m_fastFourierTransform);
    log::info("[PAFMODSoundState - describe] m_reverb: {}", m_reverb);
    log::info("[PAFMODSoundState - describe] m_unkInt1: {}", m_unkInt1);
    log::info("[PAFMODSoundState - describe] m_unkBool1: {}", m_unkBool1);
    log::info("[PAFMODSoundState - describe] m_keyForFMODMusicMap: {}", m_keyForFMODMusicMap);
    log::info("[PAFMODSoundState - describe] m_unkBool2: {}", m_unkBool2);
}
#endif