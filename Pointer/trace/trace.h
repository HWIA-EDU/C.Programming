#pragma once
#include <stdio.h>
#ifdef _DEBUG 
	#ifdef _WIN64
		#pragma comment(lib, "../x64/Debug/trace.lib")
	#else
		#pragma comment(lib, "../Debug/trace.lib")
	#endif
#else
	#ifdef _WIN64
		#pragma comment(lib, "../x64/Release/trace.lib")
	#else
		#pragma comment(lib, "../Release/trace.lib")
	#endif
#endif

#ifdef __cplusplus 
extern "C" {
#endif 

void _trace(const char* szFormat, ...);

#ifdef __cplusplus
}
#endif

#define TRACE(fmt,...) { _trace("% 3d > " fmt,__LINE__, __VA_ARGS__); printf("% 3d > " fmt,__LINE__, __VA_ARGS__); }