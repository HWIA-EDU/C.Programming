#include "../000_DebugMode/trace.h"

struct Point {
	int x;
	int y;
};

int main() {

	//sizeof(char)�� �޸� Ȯ��
	char c = 100;
	TRACE("size : %d\n", sizeof(char));
	TRACE("%p\n", &c);

	//sizeof(int)�� �޸� Ȯ��
	int n = 100;
	TRACE("size : %d\n", sizeof(int));
	TRACE("%p\n", &n);

	float f = 3.14f;
	TRACE("size : %d\n", sizeof(float));
	TRACE("%p\n", &f);

	//sizeof(struct Point)�� �޸� Ȯ��
	struct Point pt = { 10, 20 };
	TRACE("size : %d\n", sizeof(struct Point));

}