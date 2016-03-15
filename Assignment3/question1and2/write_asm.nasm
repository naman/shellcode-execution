global _start

section .text
	_start:	
		push 98
		lea rdi, [rsp]

		xor rax, rax
		add rax, 2 					; 2 for open syscall
		xor rsi, rsi				; 0 
		xor rdx, rdx
		cmp	rax, rdi				; Handling the error in open, if no file is there, jump to exit
		je	exit

		syscall

		mov rcx, rax				; copying return value for open syscall [file descriptor]

    	xor rax, rax				; 0  for read syscall
		mov rdi, rcx				; load file descriptor from rcx
		lea rsi, [rsp-10]			; address of stack - 0x10 in rsi  
		xor rdx, rdx				
		add dl, 0x10				; size of buffer = 0x10

		cmp	rax, rdi				; Handling the error in read, if size is 0, jump to exit
		je	exit

		syscall

		mov rcx, rax				; copy number of bytes read in read syscall to rcx

		xor rax, rax
		add rax, 1					; rax = 1 for write syscall
		xor rdi, rdi
		inc rdi						; 1 for stdout
		mov rdx, rcx				; rdx = number of bytes 
		syscall

		exit:
			xor rax, rax
			add rax, 60				; syscall number 60 for exit syscall
			xor rdi, rdi 				; EXIT_CODE == 0
			syscall