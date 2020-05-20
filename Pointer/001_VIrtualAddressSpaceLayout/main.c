#include <stdio.h>
#include <stdlib.h>
#define PRINT_ADDR(var) printf("=========> %s \t\t %p\n", #var, var);

/* 
����ڰ� �Է��� �� ��ŭ ������ ������ 
���� �����ϴ� ���α׷�
*/
int* buffer = NULL;

void genRandom(int cnt) {
	srand(time(NULL));
	for (int i = 0; i < cnt;i++) {
		buffer[i] = rand();
	}
}

int main() {
	int count = 0;
	printf("������ ���� �Է��ϼ��� : ");
	scanf_s("%d", &count);

	buffer = malloc(sizeof(int)*count);
	if (buffer != NULL) {
		genRandom(count);
		for (int i = 0; i < count; i++) {
			printf("%d\n", buffer[i]);
		}
		free(buffer);
	}
	
	return 0;
}