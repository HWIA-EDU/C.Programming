#include "../000_DebugMode/trace.h"

int main() {

	TRACE("%c\n", 'A');
	TRACE("%s\n", "ABC");

	//������ ���� ǥ��
	TRACE("%c\n",65);

	//���ڿ��� ���� ǥ��
	char arr[] = { 65, 66, 67,0 };
	TRACE("%s\n", &arr);

	//�޸� ������ ���
	int n = 4407873;
	TRACE("%s\n",&n);
	
	return 0;
}