segment .text
	GLOBAL _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy

extern _ft_puts
_ft_strdup:
	push rdi
	call _ft_strlen
	mov rdi, rax
	add rdi, 1
	call _malloc
	mov rsi, rax
	mov rcx, 0
	pop rdi
	push rdi
	mov rbx, rsi
	mov rax, rdi
	rep movsb
	pop rdi
	ret
