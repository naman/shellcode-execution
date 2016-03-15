all:
	echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
	gcc -ggdb -fno-stack-protector -z execstack -o input input.c
	gcc -ggdb -fno-stack-protector -z execstack -o ptr ptr.c 

clean:
	rm input ptr

