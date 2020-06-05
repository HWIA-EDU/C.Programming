#include "trace.h"
#include <stdio.h>
#include <time.h>

void createData(int cnt);
void showData(int cnt);

int* buffer = NULL;

int main()
{
	int count = 0;

	printf("Enter Number : ");
	scanf_s("%d", &count);

	buffer = malloc(sizeof(int) * count);
	if (buffer != NULL) {
		createData(count);
		showData(count);
		free(buffer);
	}

	return 0;
}

void createData(int cnt)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < cnt; i++) {
		buffer[i] = rand();
	}
}

void showData(int cnt)
{
	for (int i = 0; i < cnt; i++) {
		TRACE("%d\n", buffer[i]);
	}
}
