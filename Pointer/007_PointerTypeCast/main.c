#include "../000_DebugMode/trace.h"

struct Point {
	int x;
	int y;
};

int main() {

	//
	//�Ϲ� ������ ������ ����ȯ
	//
	float f = 3.14f;
	int n1= (int)f;
	TRACE("f = %f, n1 = %d\n",f, n1);

	//
	//�������� ����ȯ�� �����͸� ���� ��ų��?
	//

	float* pf = &f;
	int* pn = (int*)pf;
	int n2 = *pn;
	//int n2 = *((int*)&f);
	TRACE("f = %f, n1 = %d, n2 = %d\n",f,n1,n2); //n1�� , n2�� ���� �ٸ���..

	struct Point pos = { 1024,2 };
	TRACE("&pos = %p\n", &pos);
	TRACE("&pos.x = %p\n", &pos.x);
	TRACE("&pos.y = %p\n", &pos.y);
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	//
	//void* ���� ���Ͽ� 
	//void v; // void ���� �Ұ�
	//
	
	void* ptr = &pos;
	TRACE("ptr = %p\n", ptr);
	//TRACE("&ptr->x = %p\n", &ptr->x); //����  void* �ؼ��Ұ�
	//TRACE("&ptr->y = %p\n", &ptr->y); //����  void* �ؼ��Ұ�
	//TRACE("ptr->x = %d\n", ptr->x); //����  void* �ؼ��Ұ�
	//TRACE("ptr->y = %d\n", ptr->x); //����  void* �ؼ��Ұ�
	
	//
	//�پ��� ������ �� ��ȯ�� ���Ͽ� 
	//

	int* nptr = (int*)&pos;
	TRACE("nptr = %p\n", nptr);
	TRACE("*nptr = %d\n", *nptr);

	*nptr = 2048; 
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	char* cptr = (char*)&pos;
	TRACE("cptr = %p\n", cptr);
	TRACE("*cptr = %d\n", *cptr);

	*cptr = 1;
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	float* fptr = (float*)&pos;
	TRACE("fptr = %p\n", fptr);
	TRACE("*fptr = %f\n", *fptr);

	*fptr = 3.14f;
	TRACE("pos.x = %d\n", pos.x);
	TRACE("pos.y = %d\n", pos.y);

	return 0;
}