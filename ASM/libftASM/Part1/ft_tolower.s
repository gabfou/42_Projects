segment .text
	GLOBAL _ft_tolower
	extern _ft_isupper

_ft_tolower:
	push rdi
	call _ft_isupper
	cmp rax, 0x00
	je _impossible
	add rdi, 0x20

_impossible :
	mov rax, rdi
	pop rdi
	ret
