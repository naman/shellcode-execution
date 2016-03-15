# Assignment 3 Security Engineering

The programs are compiled with `-fno-stack-protector` flag and without `execstack` protection.

Q1. `nasm` assembler has been used for this question. `write_asm.nasm` contains the assembly code for reading a file `b` and printing the contents to STDOUT.

Q2. The bytes output in Q1 are converted into hex bytes in the form of a shellcode. Return address of the main is changed so as to return to the shellcode and execute it.

Q3. I have turned off ASLR (command in Makefile). I got the return address of `target()` by disassembling target() using gdb as 'target_address'.

    a) I have created a temporary `char buffer[8]`. Now, the return address  of `function1()` will be pointing at the location `buffer + 8 + 8`. I wrote the above target_address over the return address of `function1()`. Now when the function1() returns, it will jump to the address of target() function. target function calls the exit(0) syscall to exit.

    b) input: "########################################################################################################################################################################################################################################################################<target_address>"
   
    The program will be run as follows: $ printf "########################################################################################################################################################################################################################################################################\xe5\x06\x40\x00\x00\x00\x00\x00" | ./input

    The first 256 #'s are for filing the buffer. Next 8 #'s will overwrite the saved EBP. Lastly, the target address is given in the form of hex bytes, which overwrites the Return Address of function1().

