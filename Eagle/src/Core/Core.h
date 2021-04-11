#pragma once


#ifdef EAGLE_WINDOWS

	#ifdef EAGLE_LIB
		#define EAGLE_API __declspec(dllexport)
	#else
		#define	EAGLE_API __declspec(dllimport)
	#endif

	// TODO this isnt working rn :pensive:
	#define EAGLE_DISABLE_WARNING_PUSH __pragma(warning( push, 0 ))
	#define EAGLE_DISABLE_WARNING_POP __pragma(warning( pop ))


	// Assertion
	#define EAGLE_ASSERT(X, ...) if (!(X)) {\
									ENGINE_ERR(__VA_ARGS__);\
									__debugbreak();}

#else

	#ifdef EAGLE_LIB
		#define	EAGLE_API __attribute__((visibility("default")))
	#else
		#define	EAGLE_API
	#endif

	// TODO this isnt working rn :pensive:
	#define EAGLE_DISABLE_WARNING_PUSH _Pragma("GCC diagnostic push")
	#define EAGLE_DISABLE_WARNING_POP _Pragma("GCC diagnostic pop")

	// Assertion
	#define EAGLE_ASSERT(X, ...)

#endif
