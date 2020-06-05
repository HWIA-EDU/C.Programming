#include "../000_DebugMode/trace.h"

struct Point {
	int x;
	int y;
};

int main() {

	//sizeof(char)의 메모리 확보
	char c = 100;
	TRACE("size : %d\n", sizeof(char));
	TRACE("%p\n", &c);

	//sizeof(int)의 메모리 확보
	int n = 100;
	TRACE("size : %d\n", sizeof(int));
	TRACE("%p\n", &n);

	float f = 3.14f;
	TRACE("size : %d\n", sizeof(float));
	TRACE("%p\n", &f);

	//sizeof(struct Point)의 메모리 확보
	struct Point pt = { 10, 20 };
	TRACE("size : %d\n", sizeof(struct Point));

}