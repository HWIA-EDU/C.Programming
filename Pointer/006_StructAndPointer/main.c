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

struct Point {
	int x;
	int y;
};

int main() {

	struct Point pos = { 1,2 };

	//직접접근 
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	//메모리 구조 확인 
	TRACE("&pos = %p\n", &pos);
	TRACE("&pos.x = %p\n", &pos.x);
	TRACE("&pos.y = %p\n", &pos.y);

	//포인터 변수 선언 
	struct Point* ptr = NULL;
	TRACE("&ptr = %p\n", &ptr);

	//포인터 변수에 pos 변수의 주소 저장 
	ptr = &pos;
	TRACE("ptr = %p\n", ptr);

	//간접참조를 이용한 멤버 읽기 
	TRACE("(*ptr).x = %d\n", (*ptr).x); //*ptr.x 오류 발생
	TRACE("(*ptr).y = %d\n", (*ptr).y);

	//Arrow 연산자를 이용한 멤버 읽기 
	TRACE("ptr->x = %d\n", ptr->x);
	TRACE("ptr->y = %d\n", ptr->y);

	//간접참조를 이용한 멤버 쓰기 
	(*ptr).x = 10;
	(*ptr).y = 20;
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	//Arrow연사자를 이용한 멤버 쓰기 
	ptr->x = 100;
	ptr->y = 200;
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	//간접참조, Arrow 연산자를 이용한 멤버 주소 얻기
	TRACE("&(*ptr).x = %p\n", &(*ptr).x);
	TRACE("&(*ptr).y = %p\n", &(*ptr).y);

	TRACE("&ptr->x = %p\n", &ptr->x);
	TRACE("&ptr->y = %p\n", &ptr->y);

	return 0;
}