#pragma once

#ifdef SABE_PA_EXPORTING
    #define SABE_PA_DLL __declspec(dllexport)
#else
    #define SABE_PA_DLL __declspec(dllimport)
#endif