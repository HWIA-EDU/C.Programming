#include "../000_DebugMode/trace.h"

int main() {

	TRACE("%c\n", 'A');
	TRACE("%s\n", "ABC");

	//문자의 정수 표현
	TRACE("%c\n",65);

	//문자열의 정수 표현
	char arr[] = { 65, 66, 67,0 };
	TRACE("%s\n", &arr);

	//메모리 내용을 출력
	int n = 4407873;
	TRACE("%s\n",&n);
	
	return 0;
}