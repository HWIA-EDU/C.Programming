#include "../000_DebugMode/trace.h"

struct Pointer {
	int x;
	int y;
};

int main() {
	char c = 100;
	int n = 100;
	float f = 3.14f;
	struct Pointer pt = { 10,20 };
	TRACE("%p\n", &c);
	TRACE("%p\n", &n);
	TRACE("%p\n", &f);
	TRACE("%p\n", &pt);

	char* pchar = &c;
	TRACE("%d\n", sizeof(char*));
	TRACE("%p\n", &pchar);

	int* pint = &n;
	TRACE("%d\n", sizeof(int*));
	TRACE("%p\n", &pint);

	float* pfloat = &f;
	TRACE("%d\n", sizeof(int*));
	TRACE("%p\n", &pfloat);

	struct Pointer* ppt = &pt;
	TRACE("%d\n", sizeof(struct Pointer*));
	TRACE("%p\n", &ppt);

}