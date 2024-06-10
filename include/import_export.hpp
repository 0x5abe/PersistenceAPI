#pragma once

#ifdef SABE_PU_EXPORTING
    #define SABE_PU_DLL __declspec(dllexport)
#else
    #define SABE_PU_DLL __declspec(dllimport)
#endif