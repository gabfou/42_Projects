segment .text
	GLOBAL _ft_memcpy
	extern _ft_puts

_ft_memcpy:
	push rbp
	mov rbx, rsi
	mov rax, rdi
	mov rcx, rdx
	rep movsb
	pop rbp
	ret
