#include <stdio.h>
int main() {

	printf("%c\n", 'A');
	printf("%s\n", "ABC");

	//문자의 정수 표현
	printf("%c\n",65);

	//문자열의 정수 표현
	char arr[] = { 65, 66, 67,0 };
	printf("%s\n", &arr);

	int n = 4407873;
	printf("%s\n",&n);
	
	return 0;
}