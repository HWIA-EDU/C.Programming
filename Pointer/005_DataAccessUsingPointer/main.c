#include <stdio.h>

#define PRINT_WITH_LINE(fmt,...) printf("% 3d : " fmt ,__LINE__, __VA_ARGS__)

int main() {
	int num = 0;
	num = 100;
	PRINT_WITH_LINE("&num : %p\n", &num);
	PRINT_WITH_LINE("num : %d\n", num);

	int* ptr = NULL;
	PRINT_WITH_LINE("&ptr : %p\n",&ptr);
	PRINT_WITH_LINE("ptr  : %p\n", ptr);

	ptr = &num;
	PRINT_WITH_LINE("ptr : %p\n", ptr);

	*ptr = 100;
	PRINT_WITH_LINE("ptr : %p\n", ptr);
	PRINT_WITH_LINE("*ptr : %d\n", *ptr);
	PRINT_WITH_LINE("num : %d\n", num);

	num = 200;
	PRINT_WITH_LINE("num : %d\n", num);
	PRINT_WITH_LINE("*ptr : %d\n", *ptr);

	//������ �ɼ�(������Ʈ > �Ӽ� > ��Ŀ > ��� > ���� ���� �ּ�)
	//���� ���� �ּҸ� ��Ȱ��(/DYNAMICBASE:NO)�� �׽�Ʈ 

}