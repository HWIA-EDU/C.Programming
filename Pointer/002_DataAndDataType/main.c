#include <stdio.h>
int main() {

	printf("%c\n", 'A');
	printf("%s\n", "ABC");

	//������ ���� ǥ��
	printf("%c\n",65);

	//���ڿ��� ���� ǥ��
	char arr[] = { 65, 66, 67,0 };
	printf("%s\n", &arr);

	int n = 4407873;
	printf("%s\n",&n);
	
	return 0;
}