#pragma once
#include "iostream"
#include "Geode/Geode.hpp"
#include "Geode/Enums.hpp"
#include "Geode/loader/Log.hpp"
#include "Geode/binding/AdvancedFollowInstance.hpp"
#include "Geode/binding/EnhancedGameObject.hpp"
#include "Geode/binding/EnterEffectInstance.hpp"
#include "Geode/binding/EventTriggerInstance.hpp"
#include "Geode/binding/SongChannelState.hpp"
#include "Geode/binding/SongTriggerState.hpp"
#include "Geode/binding/SFXTriggerState.hpp"
#include "Geode/binding/DashRingObject.hpp"
#include "Geode/binding/EnterEffectObject.hpp"
#include "Geode/binding/EnterEffectAnimValue.hpp"
#include "../import_export.hpp"
#include <filesystem>

#define PA_OPERATOR_READ(type) SABE_PA_DLL virtual void operator>>(type& o_value) { read(reinterpret_cast<char*>(&o_value), sizeof(type)); }

#define PA_OPERATOR_WRITE(type) SABE_PA_DLL virtual void operator<<(type& i_value) { write(reinterpret_cast<char*>(&i_value), sizeof(type)); }

namespace persistenceAPI {
	class Stream {
	protected:
		std::fstream* m_stream;
		unsigned int* m_bytesRead;
		int m_PAVersion;
		const char m_zeros[256] = {};
	public:
		SABE_PA_DLL Stream() {
			m_stream = nullptr;
			m_bytesRead = nullptr;
			m_PAVersion = -1;
		};
		SABE_PA_DLL Stream(std::string i_filePath, int i_PAVersion, bool i_trunc = false) {
			int l_mode = std::ios_base::binary | std::ios_base::out;
			if (std::filesystem::exists(i_filePath)) {
				l_mode |= std::ios_base::in;
			}
			if (i_trunc) l_mode |= std::ios_base::trunc;
			m_stream = new std::fstream(i_filePath, l_mode);
			m_PAVersion = i_PAVersion;
		}
		SABE_PA_DLL Stream(std::string i_filePath, unsigned int* i_bytesRead, int i_PAVersion, bool i_trunc = false) {
			int l_mode = std::ios_base::binary | std::ios_base::out;
			if (std::filesystem::exists(i_filePath)) {
				l_mode |= std::ios_base::in;
			}
			if (i_trunc) l_mode |= std::ios_base::trunc;
			m_stream = new std::fstream(i_filePath, l_mode);
			m_bytesRead = i_bytesRead;
			m_PAVersion = i_PAVersion;
		}
		SABE_PA_DLL ~Stream() { delete m_stream; }

		PA_OPERATOR_READ(bool)
		PA_OPERATOR_READ(char)
		PA_OPERATOR_READ(unsigned char)
		PA_OPERATOR_READ(int)
		PA_OPERATOR_READ(unsigned int)
		PA_OPERATOR_READ(short)
		PA_OPERATOR_READ(unsigned short)
		PA_OPERATOR_READ(float)
		PA_OPERATOR_READ(double)
		PA_OPERATOR_READ(cocos2d::CCPoint)
		PA_OPERATOR_READ(cocos2d::CCSize)
		PA_OPERATOR_READ(cocos2d::CCAffineTransform)
		PA_OPERATOR_READ(cocos2d::ccHSVValue)
		PA_OPERATOR_READ(cocos2d::ccColor3B)
		PA_OPERATOR_READ(uint64_t)
		PA_OPERATOR_READ(long long)
		PA_OPERATOR_READ(EasingType)
		PA_OPERATOR_READ(TouchTriggerType)
		PA_OPERATOR_READ(TouchTriggerControl)
		PA_OPERATOR_READ(PulseEffectType)

		PA_OPERATOR_WRITE(bool)
		PA_OPERATOR_WRITE(char)
		PA_OPERATOR_WRITE(unsigned char)
		PA_OPERATOR_WRITE(int)
		PA_OPERATOR_WRITE(unsigned int)
		PA_OPERATOR_WRITE(short)
		PA_OPERATOR_WRITE(unsigned short)
		PA_OPERATOR_WRITE(float)
		PA_OPERATOR_WRITE(double)
		PA_OPERATOR_WRITE(cocos2d::CCPoint)
		PA_OPERATOR_WRITE(cocos2d::CCSize)
		PA_OPERATOR_WRITE(cocos2d::CCAffineTransform)
		PA_OPERATOR_WRITE(cocos2d::ccHSVValue)
		PA_OPERATOR_WRITE(cocos2d::ccColor3B)
		PA_OPERATOR_WRITE(uint64_t)
		PA_OPERATOR_WRITE(long long)
		PA_OPERATOR_WRITE(EasingType)
		PA_OPERATOR_WRITE(TouchTriggerType)
		PA_OPERATOR_WRITE(TouchTriggerControl)
		PA_OPERATOR_WRITE(PulseEffectType)

		SABE_PA_DLL bool setFile(std::string i_filePath, unsigned int* i_bytesRead, int i_PAVersion, bool i_trunc = false) {
			if (m_stream) {
				delete m_stream;
			}
			int l_mode = std::ios_base::binary | std::ios_base::out;
			if (std::filesystem::exists(i_filePath)) {
				l_mode |= std::ios_base::in;
			}
			if (i_trunc) l_mode |= std::ios_base::trunc;
			m_stream = new std::fstream(i_filePath, l_mode);
			if (!m_stream->good()) {
				//geode::log::info("!!!!!!!!!!!!!!! Failed to open file path: {} !!!!!!!!!!!!!!!!", i_filePath);
				return false;
			}
			m_bytesRead = i_bytesRead;
			m_PAVersion = i_PAVersion;
			return true;
		}

		SABE_PA_DLL bool setFile(std::string i_filePath, int i_PAVersion, bool i_trunc = false) {
			if (m_stream) {
				delete m_stream;
			}
			int l_mode = std::ios_base::binary | std::ios_base::out;
			if (std::filesystem::exists(i_filePath)) {
				l_mode |= std::ios_base::in;
			}
			if (i_trunc) l_mode |= std::ios_base::trunc;
			m_stream = new std::fstream(i_filePath, l_mode);
			if (!m_stream->good()) {
				//geode::log::info("Failed to open file path: {}", i_filePath);
				return false;
			}
			m_PAVersion = i_PAVersion;
			return true;
		}

		SABE_PA_DLL void read(char* o_value, int i_size) { 
			#if defined(PA_DEBUG) && defined(PA_DESCRIBE)
				//geode::log::info("---- Doing read at offset {} | size {} ----", static_cast<uint32_t>(m_stream->tellg()), i_size);
			#endif
			m_stream->read(o_value, i_size); 
		
			if (m_bytesRead) {
				*m_bytesRead += i_size;
			}
		}
		
		SABE_PA_DLL void ignore(int i_size) {
			m_stream->ignore(i_size);
			if (m_bytesRead) *m_bytesRead += i_size;
		}

		SABE_PA_DLL void write(char* i_value, int i_size) {
			m_stream->write(i_value, i_size);
		}

		SABE_PA_DLL void writeZero(int i_size) { 
			m_stream->write(m_zeros, i_size);
		}

		SABE_PA_DLL void seek(int i_pos, bool i_fromEnd = false) {
			if (i_fromEnd) {
				m_stream->seekp(i_pos, std::ios_base::end);
				return;
			}
			m_stream->seekp(i_pos, std::ios_base::beg);
		}

		SABE_PA_DLL void flush() {
			if (m_stream) {
				m_stream->flush();
			}
		}

		SABE_PA_DLL void clear() {
			if (m_stream) {
				m_stream->clear();
			}
		}

		SABE_PA_DLL void end() {
			if (m_stream) {
				m_stream->flush();
				m_stream->close();
				delete m_stream;
			}
			m_stream = nullptr;
			m_PAVersion = -1;
		}

		SABE_PA_DLL inline int getPAVersion() {
			return m_PAVersion;
		}

		SABE_PA_DLL inline void setPAVersion(int i_PAVersion) {
			//geode::log::info("@@@@@ PAVersion set to {} @@@@@", i_PAVersion);
			m_PAVersion = i_PAVersion;
		}

		// custom operators read

		// GameObject*

		SABE_PA_DLL void operator>>(GameObject*& o_value);

		SABE_PA_DLL void operator>>(SFXTriggerGameObject*& o_value);

		SABE_PA_DLL void operator>>(SongTriggerGameObject*& o_value);

		SABE_PA_DLL void operator>>(DashRingObject*& o_value);

		SABE_PA_DLL void operator>>(EnterEffectObject*& o_value);

		// vector

		template <class T>
		SABE_PA_DLL void operator>>(gd::vector<T>& o_value) {
			unsigned int l_size;
			read(reinterpret_cast<char*>(&l_size), 4);
			//geode::log::info("VECTOR SIZE in: {}", l_size);
			if (l_size == 0) return;
			T value;
			for (int i=0; i < l_size; i++) {
				read(reinterpret_cast<char*>(&value), sizeof(T));
				o_value.push_back(value);
			}
		}
		
		template <>
		SABE_PA_DLL void operator>><float>(gd::vector<float>& o_value) {
			unsigned int l_size;
			read(reinterpret_cast<char*>(&l_size), 4);
			//geode::log::info("VECTOR SIZE in: {}", l_size);
			if (l_size == 0) return;
			o_value.reserve(l_size);
			float value;
			for (int i=0; i < l_size; i++) {
				read(reinterpret_cast<char*>(&value), sizeof(float));
				//geode::log::info("VALUE VEC READ FLOAT: {}", value);
				o_value.push_back(value);
			}
		}

		template <>
		SABE_PA_DLL void operator>><SavedObjectStateRef>(gd::vector<SavedObjectStateRef>& o_value);

		template <>
		SABE_PA_DLL void operator>><SavedActiveObjectState>(gd::vector<SavedActiveObjectState>& o_value);

		template <>
		SABE_PA_DLL void operator>><SavedSpecialObjectState>(gd::vector<SavedSpecialObjectState>& o_value);

		template <>
		SABE_PA_DLL void operator>><CountTriggerAction>(gd::vector<CountTriggerAction>& o_value);

		template <>
		SABE_PA_DLL void operator>><TouchToggleAction>(gd::vector<TouchToggleAction>& o_value);

		template <>
		SABE_PA_DLL void operator>><CollisionTriggerAction>(gd::vector<CollisionTriggerAction>& o_value);

		template <>
		SABE_PA_DLL void operator>><ToggleTriggerAction>(gd::vector<ToggleTriggerAction>& o_value);

		template <>
		SABE_PA_DLL void operator>><SpawnTriggerAction>(gd::vector<SpawnTriggerAction>& o_value);

		template <>
		SABE_PA_DLL void operator>><GroupCommandObject2>(gd::vector<GroupCommandObject2>& o_value);

		template <>
		SABE_PA_DLL void operator>><KeyframeObject>(gd::vector<KeyframeObject>& o_value);

		template <>
		SABE_PA_DLL void operator>><TimerTriggerAction>(gd::vector<TimerTriggerAction>& o_value);

		template <>
		SABE_PA_DLL void operator>><EventTriggerInstance>(gd::vector<EventTriggerInstance>& o_value);

		template <>
		SABE_PA_DLL void operator>><EnterEffectInstance>(gd::vector<EnterEffectInstance>& o_value);

		template <>
		SABE_PA_DLL void operator>><AdvancedFollowInstance>(gd::vector<AdvancedFollowInstance>& o_value);

		template <>
		SABE_PA_DLL void operator>><CAState>(gd::vector<CAState>& o_value);

		template <>
		SABE_PA_DLL void operator>><CheckpointObject*>(gd::vector<CheckpointObject*>& o_value);

		template <>
		SABE_PA_DLL void operator>><SongTriggerState>(gd::vector<SongTriggerState>& o_value);

		template <>
		SABE_PA_DLL void operator>><SFXTriggerState>(gd::vector<SFXTriggerState>& o_value);

		template <>
		SABE_PA_DLL void operator>><DynamicObjectAction>(gd::vector<DynamicObjectAction>& o_value);

		template <>
		SABE_PA_DLL void operator>><PulseEffectAction>(gd::vector<PulseEffectAction>& o_value);

		// unordered_map

		template <class K, class V>
		SABE_PA_DLL void operator>>(gd::unordered_map<K,V>& o_value) {
			if (o_value.size() != 0) {
				o_value.clear();
			}
			unsigned int l_size;
			read(reinterpret_cast<char*>(&l_size), 4);
			//geode::log::info("Unordered Map SIZE in: {}", l_size);
			if (l_size == 0) return;
			K l_key;
			V l_value;
			for (int i = 0; i < l_size; i++) {
				read(reinterpret_cast<char*>(&l_key), sizeof(K));
				read(reinterpret_cast<char*>(&l_value), sizeof(V));
				o_value[l_key] = l_value;
			}
		}

		template <class K, class V>
		SABE_PA_DLL void operator>>(gd::unordered_map<K,gd::vector<V>>& o_value) {
			if (o_value.size() != 0) {
				//geode::log::info("VECTOR SIZE SHOULD NOT BE HERE AGRIA: {}", o_value.size());
				o_value.clear();
			}
			unsigned int l_size;
			read(reinterpret_cast<char*>(&l_size), 4);
			//geode::log::info("Unordered Map key->vector<T> SIZE in: {}", l_size);
			if (l_size == 0) return;
			K l_key;
			for (int i = 0; i < l_size; i++) {
				read(reinterpret_cast<char*>(&l_key), sizeof(K));
				*this >> o_value[l_key];
			}
		}

		template <>
		SABE_PA_DLL void operator>><int, SequenceTriggerState>(gd::unordered_map<int, SequenceTriggerState>& o_value);

		template <>
		SABE_PA_DLL void operator>><int, FMODQueuedMusic>(gd::unordered_map<int, FMODQueuedMusic>& o_value);

		template <>
		SABE_PA_DLL void operator>><int, FMODSoundState>(gd::unordered_map<int, FMODSoundState>& o_value);

		template <>
		SABE_PA_DLL void operator>><int, TimerItem>(gd::unordered_map<int, TimerItem>& o_value);

		template <>
		SABE_PA_DLL void operator>><int, EnhancedGameObject*>(gd::unordered_map<int, EnhancedGameObject*>& o_value);

		template <>
		SABE_PA_DLL void operator>><int, SongChannelState>(gd::unordered_map<int, SongChannelState>& o_value);

		template <>
		SABE_PA_DLL void operator>><int, GJValueTween>(gd::unordered_map<int, GJValueTween>& o_value);

		template <>
		SABE_PA_DLL void operator>><int, GameObjectPhysics>(gd::unordered_map<int, GameObjectPhysics>& o_value);

		template <>
		SABE_PA_DLL void operator>><int, OpacityEffectAction>(gd::unordered_map<int, OpacityEffectAction>& o_value);

		// unordered_set

		template <class K>
		SABE_PA_DLL void operator>>(gd::unordered_set<K>& o_value) {
			if (o_value.size() != 0) {
				//geode::log::info("VECTOR SIZE SHOULD NOT BE HERE AGRIA: {}", o_value.size());
				o_value.clear();
			}
			unsigned int l_size;
			read(reinterpret_cast<char*>(&l_size), 4);
			//geode::log::info("Unordered Set SIZE in: {}", l_size);
			if (l_size == 0) return;
			K l_key;
			for (int i = 0; i < l_size; i++) {
				read(reinterpret_cast<char*>(&l_key), sizeof(K));
				o_value.insert(l_key);
			}
		}

		// map

		template <class K, class V>
		SABE_PA_DLL void operator>>(gd::map<K,V>& o_value) {
			if (o_value.size() != 0) {
				//geode::log::info("VECTOR SIZE SHOULD NOT BE HERE AGRIA: {}", o_value.size());
				o_value.clear();
			}
			unsigned int l_size;
			read(reinterpret_cast<char*>(&l_size), 4);
			//geode::log::info("Map SIZE in: {}", l_size);
			if (l_size == 0) return;
			K l_key;
			V l_value;
			for (int i = 0; i < l_size; i++) {
				read(reinterpret_cast<char*>(&l_key), sizeof(K));
				read(reinterpret_cast<char*>(&l_value), sizeof(V));
				o_value[l_key] = l_value;
			}
		}

		template <class K, class V>
		SABE_PA_DLL void operator>>(gd::map<K,gd::vector<V>>& o_value) {
			if (o_value.size() != 0) {
				//geode::log::info("VECTOR SIZE SHOULD NOT BE HERE AGRIA: {}", o_value.size());
				o_value.clear();
			}
			unsigned int l_size;
			read(reinterpret_cast<char*>(&l_size), 4);
			//geode::log::info("Map key->vector<T> SIZE in: {}", l_size);
			if (l_size == 0) return;
			K l_key;
			V l_value;
			for (int i = 0; i < l_size; i++) {
				read(reinterpret_cast<char*>(&l_key), sizeof(K));
				*this >> o_value[l_key];
			}
		}

		template <>
		SABE_PA_DLL void operator>><std::pair<int,int>, SFXTriggerInstance>(gd::map<std::pair<int,int>, SFXTriggerInstance>& o_value);

		template <>
		SABE_PA_DLL void operator>><int, EnterEffectAnimValue>(gd::map<int, EnterEffectAnimValue>& o_value);

		template <>
		SABE_PA_DLL void operator>><std::pair<int,int>, FMODSoundTween>(gd::map<std::pair<int,int>, FMODSoundTween>& o_value);
		
		// set

		template <class K>
		SABE_PA_DLL void operator>>(gd::set<K>& o_value) {
			if (o_value.size() != 0) {
				//geode::log::info("VECTOR SIZE SHOULD NOT BE HERE AGRIA: {}", o_value.size());
				o_value.clear();
			}
			unsigned int l_size;
			read(reinterpret_cast<char*>(&l_size), 4);
			//geode::log::info("Set SIZE in: {}", l_size);
			if (l_size == 0) return;
			K l_key;
			for (int i = 0; i < l_size; i++) {
				read(reinterpret_cast<char*>(&l_key), sizeof(K));
				o_value.insert(l_key);
			}
		}

		// gd::string

		SABE_PA_DLL void operator>>(gd::string& o_value) {
			if (o_value.size() != 0) {
				//geode::log::info("VECTOR SIZE SHOULD NOT BE HERE AGRIA: {}", o_value.size());
				o_value.clear();
			}
			unsigned int l_size;
			read(reinterpret_cast<char*>(&l_size), 4);
			//geode::log::info("String SIZE in: {}", l_size);
			if (l_size == 0) return;
			char* l_buf = new char[l_size+1];
			read(l_buf, l_size);
			l_buf[l_size] = '\0';
			o_value = l_buf;
			delete[] l_buf;
		}

		// custom operators write

		// GameObject*

		SABE_PA_DLL void operator<<(GameObject*& i_value);

		SABE_PA_DLL void operator<<(SFXTriggerGameObject*& i_value);

		SABE_PA_DLL void operator<<(SongTriggerGameObject*& i_value);

		SABE_PA_DLL void operator<<(DashRingObject*& i_value);

		SABE_PA_DLL void operator<<(EnterEffectObject*& i_value);

		// vector

		template <class T>
		SABE_PA_DLL void operator<<(gd::vector<T>& i_value) {
			unsigned int l_size = i_value.size();
			//geode::log::info("VECTOR SIZE out: {}", l_size);
			write(reinterpret_cast<char*>(&l_size), 4);
			write(reinterpret_cast<char*>(i_value.data()), l_size*sizeof(T));
		}

		template <>
		SABE_PA_DLL void operator<<<SavedObjectStateRef>(gd::vector<SavedObjectStateRef>& i_value);

		template <>
		SABE_PA_DLL void operator<<<SavedActiveObjectState>(gd::vector<SavedActiveObjectState>& i_value);

		template <>
		SABE_PA_DLL void operator<<<SavedSpecialObjectState>(gd::vector<SavedSpecialObjectState>& i_value);

		template <>
		SABE_PA_DLL void operator<<<CountTriggerAction>(gd::vector<CountTriggerAction>& i_value);

		template <>
		SABE_PA_DLL void operator<<<TouchToggleAction>(gd::vector<TouchToggleAction>& i_value);

		template <>
		SABE_PA_DLL void operator<<<CollisionTriggerAction>(gd::vector<CollisionTriggerAction>& i_value);

		template <>
		SABE_PA_DLL void operator<<<ToggleTriggerAction>(gd::vector<ToggleTriggerAction>& i_value);

		template <>
		SABE_PA_DLL void operator<<<SpawnTriggerAction>(gd::vector<SpawnTriggerAction>& i_value);

		template <>
		SABE_PA_DLL void operator<<<GroupCommandObject2>(gd::vector<GroupCommandObject2>& i_value);

		template <>
		SABE_PA_DLL void operator<<<KeyframeObject>(gd::vector<KeyframeObject>& i_value);

		template <>
		SABE_PA_DLL void operator<<<TimerTriggerAction>(gd::vector<TimerTriggerAction>& i_value);

		template <>
		SABE_PA_DLL void operator<<<EventTriggerInstance>(gd::vector<EventTriggerInstance>& i_value);

		template <>
		SABE_PA_DLL void operator<<<EnterEffectInstance>(gd::vector<EnterEffectInstance>& i_value);

		template <>
		SABE_PA_DLL void operator<<<AdvancedFollowInstance>(gd::vector<AdvancedFollowInstance>& i_value);

		template <>
		SABE_PA_DLL void operator<<<CAState>(gd::vector<CAState>& i_value);

		template <>
		SABE_PA_DLL void operator<<<SongTriggerState>(gd::vector<SongTriggerState>& i_value);

		template <>
		SABE_PA_DLL void operator<<<SFXTriggerState>(gd::vector<SFXTriggerState>& i_value);

		template <>
		SABE_PA_DLL void operator<<<DynamicObjectAction>(gd::vector<DynamicObjectAction>& i_value);

		template <>
		SABE_PA_DLL void operator<<<PulseEffectAction>(gd::vector<PulseEffectAction>& i_value);

		// unordered_map

		template <class K, class V>
		SABE_PA_DLL void operator<<(gd::unordered_map<K,V>& i_value) {
			unsigned int l_size = i_value.size();
			//geode::log::info("Unordered Map SIZE out: {}", l_size);
			write(reinterpret_cast<char*>(&l_size), 4);
			for (std::pair<K,V> l_pair : i_value) {
				write(reinterpret_cast<char*>(&l_pair.first), sizeof(K));
				write(reinterpret_cast<char*>(&l_pair.second), sizeof(V));
			}
		}

		template <class K, class V>
		SABE_PA_DLL void operator<<(gd::unordered_map<K,gd::vector<V>>& i_value) {
			unsigned int l_size = i_value.size();
			//geode::log::info("Unordered Map key->vector<T> SIZE out: {}", l_size);
			write(reinterpret_cast<char*>(&l_size), 4);
			for (std::pair<K,gd::vector<V>> l_pair : i_value) {
				write(reinterpret_cast<char*>(&l_pair.first), sizeof(K));
				*this << l_pair.second; 
			}
		}

		template <>
		SABE_PA_DLL void operator<<<int, SequenceTriggerState>(gd::unordered_map<int, SequenceTriggerState>& i_value);

		template <>
		SABE_PA_DLL void operator<<<int, FMODQueuedMusic>(gd::unordered_map<int, FMODQueuedMusic>& i_value);

		template <>
		SABE_PA_DLL void operator<<<int, FMODSoundState>(gd::unordered_map<int, FMODSoundState>& i_value);

		template <>
		SABE_PA_DLL void operator<<<int, TimerItem>(gd::unordered_map<int, TimerItem>& i_value);

		template <>
		SABE_PA_DLL void operator<<<int, EnhancedGameObject*>(gd::unordered_map<int, EnhancedGameObject*>& i_value);

		template <>
		SABE_PA_DLL void operator<<<int, SongChannelState>(gd::unordered_map<int, SongChannelState>& i_value);

		template <>
		SABE_PA_DLL void operator<<<int, GJValueTween>(gd::unordered_map<int, GJValueTween>& i_value);

		template <>
		SABE_PA_DLL void operator<<<int, GameObjectPhysics>(gd::unordered_map<int, GameObjectPhysics>& i_value);

		template <>
		SABE_PA_DLL void operator<<<int, OpacityEffectAction>(gd::unordered_map<int, OpacityEffectAction>& i_value);

		// unordered_set

		template <class K>
		SABE_PA_DLL void operator<<(gd::unordered_set<K>& i_value) {
			unsigned int l_size = i_value.size();
			//geode::log::info("Unordered Set SIZE out: {}", l_size);
			write(reinterpret_cast<char*>(&l_size), 4);
			for (K l_key : i_value) {
				write(reinterpret_cast<char*>(&l_key), sizeof(K));
			}
		}

		// map

		template <class K, class V>
		SABE_PA_DLL void operator<<(gd::map<K,V>& i_value) {
			unsigned int l_size = i_value.size();
			//geode::log::info("Map SIZE out: {}", l_size);
			write(reinterpret_cast<char*>(&l_size), 4);
			for (std::pair<K,V> l_pair : i_value) {
				write(reinterpret_cast<char*>(&l_pair.first), sizeof(K));
				write(reinterpret_cast<char*>(&l_pair.second), sizeof(V));
			}
		}

		template <class K, class V>
		SABE_PA_DLL void operator<<(gd::map<K,gd::vector<V>>& i_value) {
			unsigned int l_size = i_value.size();
			//geode::log::info("Unordered Map key->vector<T> SIZE out: {}", l_size);
			write(reinterpret_cast<char*>(&l_size), 4);
			for (std::pair<K,gd::vector<V>> l_pair : i_value) {
				write(reinterpret_cast<char*>(&l_pair.first), sizeof(K));
				*this << l_pair.second; 
			}
		}

		template <>
		SABE_PA_DLL void operator<<<std::pair<int,int>, SFXTriggerInstance>(gd::map<std::pair<int,int>, SFXTriggerInstance>& i_value);

		template <>
		SABE_PA_DLL void operator<<<int, EnterEffectAnimValue>(gd::map<int, EnterEffectAnimValue>& i_value);

		template <>
		SABE_PA_DLL void operator<<<std::pair<int,int>, FMODSoundTween>(gd::map<std::pair<int,int>, FMODSoundTween>& i_value);

		// set

		template <class K>
		SABE_PA_DLL void operator<<(gd::set<K>& i_value) {
			unsigned int l_size = i_value.size();
			//geode::log::info("Set SIZE out: {}", l_size);
			write(reinterpret_cast<char*>(&l_size), 4);
			for (K l_key : i_value) {
				write(reinterpret_cast<char*>(&l_key), sizeof(K));
			}
		}

		// gd::string

		SABE_PA_DLL void operator<<(gd::string& i_value) {
			unsigned int l_size = i_value.size();
			write(reinterpret_cast<char*>(&l_size), 4);
			//geode::log::info("String SIZE in: {}", l_size);
			if (l_size == 0) return;
			write(i_value.data(), l_size);
		}
	};
}