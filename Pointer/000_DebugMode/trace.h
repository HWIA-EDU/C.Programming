#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <windows.h>

inline void _trace(const char* fmt, ...) {
	char _cbuf[1024] = { 0, };
	va_list args;

	va_start(args, fmt);
	vsnprintf_s(_cbuf, sizeof(_cbuf), sizeof(_cbuf), fmt, args);
	va_end(args);

	//����� ���ÿ� ���â�� �޽����� ���
	OutputDebugStringA(_cbuf);

	//�ܼ�ȭ�鿡 ���
	printf("%s", _cbuf);
}

#define TRACE(fmt,...) _trace("% 3d > " fmt, __LINE__,__VA_ARGS__)