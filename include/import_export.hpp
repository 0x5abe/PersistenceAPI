#pragma once


#ifdef GEODE_IS_WINDOWS
    #ifdef SABE_PA_EXPORTING
		#define SABE_PA_DLL __declspec(dllexport)
	#else
		#define SABE_PA_DLL __declspec(dllimport)
	#endif
#else
    #define SABE_PA_DLL __attribute__((visibility("default")))
#endif