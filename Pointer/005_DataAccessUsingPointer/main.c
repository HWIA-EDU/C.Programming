#include <stdio.h>
#include "../trace/trace.h"

int main() {
	
	int num = 0;
	num = 100;
	TRACE("&num : %p\n", &num);
	TRACE("num : %d\n", num);

	int* ptr = NULL;
	TRACE("&ptr : %p\n",&ptr);
	TRACE("ptr  : %p\n", ptr);

	ptr = &num;
	TRACE("ptr : %p\n", ptr);

	*ptr = 100;
	TRACE("ptr : %p\n", ptr);
	TRACE("*ptr : %d\n", *ptr);
	TRACE("num : %d\n", num);

	num = 200;
	TRACE("num : %d\n", num);
	TRACE("*ptr : %d\n", *ptr);

	//컴파일 옵션(프로젝트 > 속성 > 링커 > 고급 > 임의 기준 주소)
	//임의 기준 주소를 비활성(/DYNAMICBASE:NO)후 테스트 
}