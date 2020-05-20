#include <stdio.h>
#include <stdlib.h>
#define PRINT_ADDR(var) printf("=========> %s \t\t %p\n", #var, var);

/* 
사용자가 입력한 수 만큼 입의의 렌덤한 
수를 생성하는 프로그램
*/
int* buffer = NULL;

void createData(int cnt) {
	srand(time(NULL));
	for (int i = 0; i < cnt;i++) {
		buffer[i] = rand();
	}
}

void showData(int cnt) {
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", buffer[i]);
	}
}

int main() {

	while (1) {
		int count = 0;

		printf("생성할 수를 입력하세요 : ");
		scanf_s("%d", &count);

		buffer = malloc(sizeof(int) * count);
		if (buffer != NULL) {
			createData(count);
			showData(count);
			printf("힙 할당 영역 : %p\n", buffer);
			free(buffer);
		}
	}
	
	return 0;
}