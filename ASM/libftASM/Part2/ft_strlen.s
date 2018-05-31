segment .text
	GLOBAL _ft_strlen

_ft_strlen:
	push rdi
	mov rcx, 0x00
	mov rax, 0x00
	not rcx
	repne scasb
	not rcx
	dec rcx
	mov rax, rcx
	pop rdi
	ret
