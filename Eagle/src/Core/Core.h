#pragma once


#ifdef EAGLE_WINDOWS

	#ifdef EAGLE_LIB
		#define EAGLE_API __declspec(dllexport)
	#else
		#define	EAGLE_API __declspec(dllimport)
	#endif

#else

	#ifdef EAGLE_LIB
		#define	EAGLE_API __attribute__((visibility("default")))
	#else
		#define	EAGLE_API
	#endif

#endif
