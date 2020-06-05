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

	//
	//일반 변수의 데이터 형변환
	//
	float f = 3.14f;
	int n1= (int)f;
	TRACE("f = %f, n1 = %d\n",f, n1);

	//
	//포인터의 형변환은 데이터를 변형 시킬까?
	//

	float* pf = &f;
	int* pn = pf;
	int n2 = *pn;
	//int n2 = *((int*)&f);
	TRACE("f = %f, n1 = %d, n2 = %d\n",f,n1,n2); //n1과 , n2의 값이 다르다..

	struct Point pos = { 1024,2 };
	TRACE("&pos = %p\n", &pos);
	TRACE("&pos.x = %p\n", &pos.x);
	TRACE("&pos.y = %p\n", &pos.y);
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	//
	//void* 형에 대하여 
	//void v; // void 선언 불가
	//
	
	void* ptr = &pos;
	TRACE("ptr = %p\n", ptr);
	//TRACE("&ptr->x = %p\n", &ptr->x); //오류  void* 해석불가
	//TRACE("&ptr->y = %p\n", &ptr->y); //오류  void* 해석불가
	//TRACE("ptr->x = %d\n", ptr->x); //오류  void* 해석불가
	//TRACE("ptr->y = %d\n", ptr->x); //오류  void* 해석불가
	
	//
	//다양한 포인터 형 변환에 대하여 
	//

	int* nptr = (int*)&pos;
	TRACE("nptr = %p\n", nptr);
	TRACE("*nptr = %d\n", *nptr);

	*nptr = 2048; 
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	char* cptr = (char*)&pos;
	TRACE("cptr = %p\n", cptr);
	TRACE("*cptr = %d\n", *cptr);

	*cptr = 1;
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	float* fptr = (float*)&pos;
	TRACE("fptr = %p\n", fptr);
	TRACE("*fptr = %f\n", *fptr);

	*fptr = 3.14f;
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	return 0;
}