#include <stdio.h>
#include <stdlib.h>

char szTitle[] = "Message Enter";

void getMessage(char* msgBuf, size_t size) {
	printf("%s : ", szTitle);
	scanf_s("%s", msgBuf, size);
}

int main() {
	const int bufSize = 32;
	char* msgBuf = malloc(bufSize);
	getMessage(msgBuf, bufSize);

	printf("Message : %s\n", msgBuf);

	free(msgBuf);

	return 0;
}