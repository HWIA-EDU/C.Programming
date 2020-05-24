#include <stdio.h>

struct Point {
	int x;
	int y;
};

int main() {

	//sizeof(char)의 메모리 확보
	char c = 'A';
	printf("size : %d\n", sizeof(char));

	//sizeof(int)의 메모리 확보
	int n = 100;
	printf("size : %d\n", sizeof(int));

	//sizeof(struct Point)의 메모리 확보
	struct Point pt = { 10, 20 };
	printf("size : %d\n", sizeof(struct Point));

	//sizeof(int[2][3])의 메모리 확보
	int arr[2][3] = { {1,2,3},{4,5,6} };
	printf("size : %d\n", sizeof(int[2][3]));
}