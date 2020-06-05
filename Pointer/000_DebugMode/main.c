#include <stdio.h>

#include <stdarg.h>
#include <windows.h>
void _trace(const char* fmt, ...) {
	char _cbuf[1024] = { 0, };
	va_list args;

	va_start(args, fmt);
	vsnprintf_s(_cbuf, sizeof(_cbuf), sizeof(_cbuf), fmt, args);
	va_end(args);

	//디버그 모드시에 출력창에 메시지를 출력
	OutputDebugString(_cbuf);

	//콘솔화면에 출력
	printf("%s", _cbuf);
}

#define TRACE(fmt,...) _trace("% 3d > " fmt, __LINE__,__VA_ARGS__)


int main() {
	int a = 100;
	TRACE("&a = %p\n", &a);
	TRACE("a = %d\n", a);
	return 0;
	return 0;
}