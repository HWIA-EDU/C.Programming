#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
����ڰ� �Է��� �� ��ŭ ������ ������ 
���� �����ϴ� ���α׷�
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
	int count = 0;

	printf("������ ���� �Է��ϼ��� : ");
	scanf_s("%d", &count);

	buffer = malloc(sizeof(int) * count);
	if (buffer != NULL) {
		createData(count);
		showData(count);
		free(buffer);
	}
	
	return 0;
}