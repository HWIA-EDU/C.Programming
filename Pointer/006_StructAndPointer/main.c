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


struct Point {
	int x;
	int y;
};

int main() {
	struct Point pos = { 1,2 };
	
	//���� ����
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	//�޸� ���� Ȯ��
	TRACE("&pos = %p\n", &pos);
	TRACE("&pos.x = %p\n", &pos.x);
	TRACE("&pos.y = %p\n", &pos.y);
	
	//������ ���� ����
	struct Point* ptr = NULL;
	TRACE("&ptr = %p\n", &ptr);
	
	//������ ������ pos ������ �ּ� ����
	ptr = &pos;
	TRACE("ptr = %p\n", ptr);

	//���������� �̿��� ��� �ϱ�
	TRACE("(*ptr).x = %d\n", (*ptr).x);
	TRACE("(*ptr).y = %d\n", (*ptr).y);

	//Arrow �����ڸ� �̿��� ��� �б�
	TRACE("ptr->x = %d\n", ptr->x);
	TRACE("ptr->y = %d\n", ptr->y);

	//���������� �̿��� ��� ����
	(*ptr).x = 10;
	(*ptr).y = 20;
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	//Arrow �����ڸ� �̿��� ��� ����
	ptr->x = 100;
	ptr->y = 200;
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	//�������� ,Arrow �����ڸ� �̿��� ��� �ּ� ���
	TRACE("&pos.x = %p\n", &(*ptr).x);
	TRACE("&pos.y = %p\n", &ptr->y);

	TRACE("&pos.x = %p\n", &((*ptr).x));
	TRACE("&pos.y = %p\n", &(ptr->y));


	return 0;
}