#include "../000_DebugMode/trace.h"

struct Point {
	int x;
	int y;
};

int main() {

	struct Point pos = { 1,2 };

	//�������� 
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

	//���������� �̿��� ��� �б� 
	TRACE("(*ptr).x = %d\n", (*ptr).x); //*ptr.x ���� �߻�
	TRACE("(*ptr).y = %d\n", (*ptr).y);

	//Arrow �����ڸ� �̿��� ��� �б� 
	TRACE("ptr->x = %d\n", ptr->x);
	TRACE("ptr->y = %d\n", ptr->y);

	//���������� �̿��� ��� ���� 
	(*ptr).x = 10;
	(*ptr).y = 20;
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	//Arrow�����ڸ� �̿��� ��� ���� 
	ptr->x = 100;
	ptr->y = 200;
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	//��������, Arrow �����ڸ� �̿��� ��� �ּ� ���
	TRACE("&(*ptr).x = %p\n", &(*ptr).x);
	TRACE("&(*ptr).y = %p\n", &(*ptr).y);

	TRACE("&ptr->x = %p\n", &ptr->x);
	TRACE("&ptr->y = %p\n", &ptr->y);

	return 0;
}