#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void target()
{
	printf("This is the target function\n");
	exit(0);
}


void function1()
{
	printf("Inside function1. Must not return to main()\n");
	
	char* cptr;
	unsigned long long* ptr;

	char tmp[8];
	memset(tmp, 0, 8);
	strcpy(tmp,"CRAP"); 

	cptr = tmp + 8 + 8;
	ptr = (unsigned long long *)cptr;
	*ptr = 0x00000000004005c6;
}


int main(int argc, unsigned char **argv)
{
	function1();
	printf("back to main!\n");

	return 0;
}