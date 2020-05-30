#include <windows.h>
#include <stdio.h>

#define TRACE(fmt,...) {\
	char _c_buf[1024] = { 0, };\
	_snprintf_s(_c_buf,sizeof(_c_buf),sizeof(_c_buf),"% 3d > " fmt, __LINE__, __VA_ARGS__);\
	OutputDebugString(_c_buf);\
	printf(_c_buf);\
}

int main() {
	/* 일반 초기화 */
	int num = 100;
	TRACE("&num : %p\n", &num);
	TRACE("num : %d\n", num);

	/* 포인터변수 초기화*/
	int* ptr = NULL;
	TRACE("&ptr : %p\n", &ptr);
	TRACE("ptr : %p\n", ptr);

	/* num 의 메모리 주소를 포인터 ptr에 저장 */
	ptr = &num;
	TRACE("ptr : %p\n", ptr);

	/* 간접참조 연산자를 통해서 값 읽기 */
	TRACE("*ptr : %d\n", *ptr);

	/* 간접참조 연산자를 통해서 값 쓰기 */
	*ptr = 500;
	TRACE("num : %d\n", num);
}