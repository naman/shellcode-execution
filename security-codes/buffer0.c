#include <stdio.h>

void ShouldNotExec(){
	printf("I am here.\n");
}

void GetInput(){
	char buffer[8];
	gets(buffer);	//if address og ShouldNotExec is passed in gets, 
				   // it jumps to that location
	
	puts(buffer);
}



int main(int argc, char const *argv[])
{
	GetInput();

	return 0;
}