#include <stdio.h>

struct Point {
	int x;
	int y;
};

int main() {

	//sizeof(char)�� �޸� Ȯ��
	char c = 100;
	printf("size : %d\n", sizeof(char));
	printf("%p\n", &c);

	//sizeof(int)�� �޸� Ȯ��
	int n = 100;
	printf("size : %d\n", sizeof(int));
	printf("%p\n", &n);

	float f = 3.14;
	printf("size : %d\n", sizeof(float));
	printf("%p\n", &f);

	//sizeof(struct Point)�� �޸� Ȯ��
	struct Point pt = { 10, 20 };
	printf("size : %d\n", sizeof(struct Point));

}