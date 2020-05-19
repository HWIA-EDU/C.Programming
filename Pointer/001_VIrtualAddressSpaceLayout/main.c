#include <stdio.h>
#include <stdlib.h>

#define PRINT_ADDR(var) printf("=========> %s \t\t %p\n", #var, var);

char szTitle[] = "Message Enter";

void getMessage(char* buf, int size) {

	PRINT_ADDR(getMessage);
	PRINT_ADDR(&buf);
	PRINT_ADDR(&size);

	printf("%s : ", szTitle);
	scanf_s("%s", buf, size);
}

int main() {
	const int bufSize = 32;
	char* msgBuf = NULL;

	msgBuf = malloc(bufSize);
	
	PRINT_ADDR(szTitle);
	PRINT_ADDR(main);
	PRINT_ADDR(&bufSize);
	PRINT_ADDR(&msgBuf);
	PRINT_ADDR(msgBuf);

	getMessage(msgBuf, bufSize);

	printf("Message : %s\n", msgBuf);
	
	printf("Enter!!");
	getch();

	free(msgBuf);

	return 0;
}