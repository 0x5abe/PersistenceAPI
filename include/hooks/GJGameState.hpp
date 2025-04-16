#pragma once
#include "Geode/Geode.hpp"
#include "Geode/modify/GJGameState.hpp"
#include "../util/Stream.hpp"
#include "../import_export.hpp"

namespace persistenceAPI {
    class $modify(PAGJGameState, GJGameState) {
    protected:
        friend void operator>>(persistenceAPI::Stream& i_stream, PAGJGameState& o_value);
        friend void operator<<(persistenceAPI::Stream& o_stream, PAGJGameState& i_value);

    public:
        SABE_PA_DLL void load(persistenceAPI::Stream& i_stream);
        SABE_PA_DLL void save(persistenceAPI::Stream& o_stream);

        SABE_PA_DLL void clean();

    #if defined(PA_DEBUG) && defined(PA_DESCRIBE)
        SABE_PA_DLL void describe();
    #endif
    };
}