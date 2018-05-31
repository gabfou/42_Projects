segment .text
	GLOBAL _ft_toupper
	extern _ft_islower

_ft_toupper:
	push rdi
	call _ft_islower
	cmp rax, 0x00
	je _impossible
	sub rdi, 0x20

_impossible:
	mov rax, rdi
	pop rdi
	ret
