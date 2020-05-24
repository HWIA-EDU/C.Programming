#include <stdio.h>

struct Point {
	int x;
	int y;
};

typedef int ARRAY_5INT[5];
int main() {

	printf("%d", sizeof(int[5]));

	ARRAY_5INT arr;
	
	return 0;
}