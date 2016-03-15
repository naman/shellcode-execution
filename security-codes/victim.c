#include <stdio.h>
int main(){
        char name[64];
        printf("buffer address: %p\n", name);  //print address of buffer
        puts("Enter text for name:");
        gets(name);
        printf("content of buffer: %s\n", name);
        return 0;
}