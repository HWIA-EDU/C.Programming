#include "../000_DebugMode/trace.h"
#include <conio.h>

int main() {
	/* �Ϲ� ���� �ʱ�ȭ */
	int num = 10;

	/* ������ ���� �ʱ�ȭ */
	int* ptr = NULL;

	//������ �޸� �ּ� Ȯ��
	TRACE("&num : %p \n", &num);
	TRACE("&ptr : %p \n", &ptr);

	//������ ����� �� Ȯ��	
	TRACE("num : %d \n", num);
	TRACE("ptr : %p \n", ptr);

	//num  ������ �ּҸ� ptr������ ����
	ptr = &num; 
	TRACE("ptr : %p\n", ptr);

	//�������� �����ڸ� ���ؼ� �� �б� 
	TRACE("*ptr : %d\n", *ptr);

	//�������� �����ڸ� ���ؼ� �� ���� 
	*ptr = 500;
	TRACE("num : %d\n", num);

	//���� ���� �ּ� ���� ���¿��� Ȯ�� ���� 
	//������Ʈ �Ӽ� > ��ũ > ��� > ���� ���� �ּ� > �ƴϿ�(/DYNAMICBASE:NO) 
	//���ȿ� ��������� �ݵ�� Ȱ��ȭ ���·� ���� !!
	*((int*)0x0019FED8) = 1000;
	TRACE("num : %d\n", num);
	TRACE("*ptr : %d\n", *((int*)0x0019FED8));

	_getch();

}