all:
	echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
	gcc -ggdb -fno-stack-protector -z execstack -o q1 q1.c 
	nasm -f elf64 write_asm.nasm
	ld write_asm.o -o write_asm
clean:
	rm *.o write_asm q1