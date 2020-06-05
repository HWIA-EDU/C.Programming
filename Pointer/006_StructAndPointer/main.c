#include "../000_DebugMode/trace.h"

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