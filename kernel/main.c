#include <intrin.h>
#include "printf.h"

int main() 
{
	console_initialize();
	int i = 0x12345;
	printf("hello world! i:0x%x",i);
	for (;;);
}