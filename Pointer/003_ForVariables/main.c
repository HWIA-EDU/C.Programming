#include <stdio.h>

struct Point {
	int x;
	int y;
};

int main() {
	char c = 'A';
	printf("%c\n", c);

	int n = 100;
	printf("%d\n", n);

	struct Point pt = { 10, 20 };
	printf("%d, %d\n", pt.x, pt.y);

	int arr[2][3] = { {1,2,3},{4,5,6} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\n", arr[i][j]);
		}
	}
}