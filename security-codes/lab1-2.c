#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {


        char name[64], *cptr;
        unsigned long *ptr;
        // printf("buffer address: %p\n", name);  //print address of buffer
        // puts("Enter text for name:");
                // printf("Hello!\n");
        // gets(name);
        // printf("content of buffer: %s\n", name);

        // memset(name, 0, 64);
        strcpy(name, "Hello!");

        cptr = name + 64 + 8;
        ptr = (unsigned long *)cptr;
        *ptr = 0x00007ffff7a37b1;
        *(ptr + 1) = (unsigned long *)1;
        *(ptr + 2) = 0x00007ffff7b44dc1;
        *(ptr + 3) = (unsigned long *)name;
        *(ptr + 4) = 0x00007ffff7b1d145;
        *(ptr + 5) = (unsigned long *)strlen(name);
        *(ptr + 6) = 0x00007ffff7b00860;
        // *(ptr + 7) = 0x00007ffff7a37b1;
        // *(ptr + 8) = (unsigned long)0;
        *(ptr + 7) = 0x00007ffff7b00860;        
        *(ptr + 8) = 0x00007ffff7a51290;

        return 0;

}
