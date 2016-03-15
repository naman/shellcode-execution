#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char* args[2];
	args[0] = "/bin/sh";
	args[1] = NULL;

	execve(args[0], args, NULL);
	return 0;
}
