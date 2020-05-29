#include <windows.h>
#include <stdio.h>

#pragma warning(disable : 4996 6053 )
void _trace(const char* szFormat, ...)
{
	char szBuff[1024];
	va_list arg;
	va_start(arg, szFormat);
	_vsnprintf(szBuff, sizeof(szBuff), szFormat, arg);
	va_end(arg);
	OutputDebugString(szBuff);
}