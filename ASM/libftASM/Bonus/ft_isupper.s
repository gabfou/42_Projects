segment .text
	GLOBAL _ft_isupper

_ft_isupper:
	push rdi

	mov rax, 1
	cmp rdi, 0x41
	jb error
	cmp rdi, 0x5a
	ja error
	jmp end
	error :
	mov rax, 0
	end :

	pop rdi
ret
