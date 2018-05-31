segment .text
	GLOBAL _ft_islower

_ft_islower:
	push rdi

	mov rax, 1
	cmp rdi, 0x61
	jb error
	cmp rdi, 0x7a
	ja error
	jmp end
	error :
	mov rax, 0
	end :

	pop rdi
ret
