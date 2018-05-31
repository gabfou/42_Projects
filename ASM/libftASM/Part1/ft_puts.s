%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

segment .text
	GLOBAL _ft_puts
	extern _ft_strlen

_ft_puts:
	push rdi
	call _ft_strlen
	mov rsi, rdi
	mov rdi, STDOUT
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rdi
	ret
