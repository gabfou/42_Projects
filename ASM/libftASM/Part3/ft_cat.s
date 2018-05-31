%define MACH_SYSCALL(nb)	0x2000000 | nb
%define READ				3
%define WRITE				4

segment .bss
	buf		resb	1024

segment .text
	GLOBAL	_ft_cat
	extern	_ft_puts

_ft_cat:
	while:
	push rdi
	lea rsi, [rel buf]
	mov rdx, 1024
	mov rax, MACH_SYSCALL(READ)
	syscall
	jc end
	cmp rax, 0x00
	jle end
	mov rdi, 1
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rdi
	jmp while

end :
	pop rdi
	ret
