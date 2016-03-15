.text
.globl _start

	_start :
		movl $20, %ebx	; pushing the number 20 in ebx
		movl $1, %eax	; exit function
		int $0x80		; interrupt to kernel

