#include <windows.h>
#include <stdio.h>

#define TRACE(fmt,...) {\
	char _c_buf[1024] = { 0, };\
	_snprintf_s(_c_buf,sizeof(_c_buf),sizeof(_c_buf),"% 3d > " fmt, __LINE__, __VA_ARGS__);\
	OutputDebugString(_c_buf);\
	printf(_c_buf);\
}

int main() {
	/* �Ϲ� �ʱ�ȭ */
	int num = 100;
	TRACE("&num : %p\n", &num);
	TRACE("num : %d\n", num);

	/* �����ͺ��� �ʱ�ȭ*/
	int* ptr = NULL;
	TRACE("&ptr : %p\n", &ptr);
	TRACE("ptr : %p\n", ptr);

	/* num �� �޸� �ּҸ� ������ ptr�� ���� */
	ptr = &num;
	TRACE("ptr : %p\n", ptr);

	/* �������� �����ڸ� ���ؼ� �� �б� */
	TRACE("*ptr : %d\n", *ptr);

	/* �������� �����ڸ� ���ؼ� �� ���� */
	*ptr = 500;
	TRACE("num : %d\n", num);
}