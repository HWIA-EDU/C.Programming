#include <stdio.h>
#include <stdarg.h>

#include <windows.h>
void _trace(const char* fmt, ...) {
	char _cbuf[102] = { 0, };
	va_list args;

	va_start(args, fmt);
	vsnprintf_s(_cbuf, sizeof(_cbuf), sizeof(_cbuf), fmt, args);
	va_end(args);

	OutputDebugString(_cbuf);

	printf("%s", _cbuf);
}

#define TRACE(fmt,...) _trace("% 3d > " fmt, __LINE__,__VA_ARGS__)

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

	getch();

}