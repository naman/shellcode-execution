#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void function1()
{
	unsigned char buff[256];
	memset(buff, 0, 256);
	gets(buff);
	
	printf("Input string: %s\n", buff);

	printf("Inside function1. Must not return to main()\n");
}

void target()
{
	printf("This is the target function\n");
	exit(0);
}

int main(int argc, unsigned char **argv)
{
	printf("Called function1()!\n");
	function1();
	printf("back to main!\n");

	return 0;
}