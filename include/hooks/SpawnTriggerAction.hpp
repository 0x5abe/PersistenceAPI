#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/SpawnTriggerAction.hpp"
#include "../util/Stream.hpp"
#include "../import_export.hpp"

namespace persistenceAPI {
    class $modify(PASpawnTriggerAction, SpawnTriggerAction) {
    protected:
        friend void operator>>(persistenceAPI::Stream& i_stream, PASpawnTriggerAction& o_value);
        friend void operator<<(persistenceAPI::Stream& o_stream, PASpawnTriggerAction& i_value);

    public:
        SABE_PA_DLL void load(persistenceAPI::Stream& i_stream);
        SABE_PA_DLL void save(persistenceAPI::Stream& o_stream);

    #if defined(PA_DEBUG) && defined(PA_DESCRIBE)
        SABE_PA_DLL void describe();
    #endif
    };
}