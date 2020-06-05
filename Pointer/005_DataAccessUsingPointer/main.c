#include "../000_DebugMode/trace.h"
#include <conio.h>

int main() {
	/* 일반 변수 초기화 */
	int num = 10;

	/* 포인터 변수 초기화 */
	int* ptr = NULL;

	//변수의 메모리 주소 확인
	TRACE("&num : %p \n", &num);
	TRACE("&ptr : %p \n", &ptr);

	//변수에 저장된 값 확인	
	TRACE("num : %d \n", num);
	TRACE("ptr : %p \n", ptr);

	//num  변수의 주소를 ptr변수에 저장
	ptr = &num; 
	TRACE("ptr : %p\n", ptr);

	//간접참조 연산자를 통해서 값 읽기 
	TRACE("*ptr : %d\n", *ptr);

	//간접참조 연산자를 통해서 값 쓰기 
	*ptr = 500;
	TRACE("num : %d\n", num);

	//임의 기준 주소 해제 상태에서 확인 가능 
	//프로젝트 속성 > 링크 > 고급 > 임의 기준 주소 > 아니요(/DYNAMICBASE:NO) 
	//보안에 취약함으로 반드시 활성화 상태로 유지 !!
	*((int*)0x0019FED8) = 1000;
	TRACE("num : %d\n", num);
	TRACE("*ptr : %d\n", *((int*)0x0019FED8));

	_getch();

}