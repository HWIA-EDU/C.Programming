#include <stdio.h>

struct Point {
	int x;
	int y;
};

int main() {

	//sizeof(char)의 메모리 확보
	char c = 100;
	printf("size : %d\n", sizeof(char));
	printf("%p\n", &c);

	//sizeof(int)의 메모리 확보
	int n = 100;
	printf("size : %d\n", sizeof(int));
	printf("%p\n", &n);

	float f = 3.14;
	printf("size : %d\n", sizeof(float));
	printf("%p\n", &f);

	//sizeof(struct Point)의 메모리 확보
	struct Point pt = { 10, 20 };
	printf("size : %d\n", sizeof(struct Point));

}