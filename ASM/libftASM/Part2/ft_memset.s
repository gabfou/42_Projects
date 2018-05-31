segment .text
	GLOBAL _ft_memset

_ft_memset:
	push rdi
	push rsi
	push rdx
	mov rbx, rdi
	mov rax, rsi
	mov rcx, rdx
	rep stosb
	mov rax, rbx
	pop rdx
	pop rsi
	pop rdi
	ret
