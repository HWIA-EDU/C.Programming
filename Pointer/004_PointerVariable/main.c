#include <stdio.h>

struct Pointer {
	int x;
	int y;
};

int main() {
	char c = 100;
	int n = 100;
	float f = 3.14;
	struct Pointer pt = { 10,20 };
	printf("%p\n", &c);
	printf("%p\n", &n);
	printf("%p\n", &f);
	printf("%p\n", &pt);

	char* pchar = &c;
	printf("%d\n", sizeof(char*));
	printf("%p\n", &pchar);

	int* pint = &n;
	printf("%d\n", sizeof(int*));
	printf("%p\n", &pint);

	float* pfloat = &f;
	printf("%d\n", sizeof(int*));
	printf("%p\n", &pfloat);

	struct Pointer* ppt = &pt;
	printf("%d\n", sizeof(struct Pointer*));
	printf("%p\n", &ppt);

}