#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define PRINT_ADDR(var) printf("%s\t\t\t%p\n", #var, var);

int sum = 0;

void calc(int start, int end) {
	sum = 0;
	for (int i = start; i <= end; i++) {
		sum += i;
	}

	char* msg = malloc(1024);
	if (NULL != msg) {
		memset(msg, 0, 1024);
		snprintf(msg, 1024, "\n¥Ò(%d,%d) = %d\n\n", start, end, sum);
		printf(msg);
		free(msg);
	}
}

int main() {
	int start;
	int end;

	while (1) {
		
		printf("begin number : ");
		scanf_s("%d", &start);

		printf("end number : ");
		scanf_s("%d", &end);
	
		calc(start, end);
	}

	return 0;
}