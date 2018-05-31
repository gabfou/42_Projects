segment .text
	GLOBAL _ft_isdigit

_ft_isdigit:
	push rdi
	mov rax, 1
	cmp rdi, 0x30
	jb error
	cmp rdi, 0x39
	ja error
	jmp end
	error :
	mov rax, 0

end :
	pop rdi
	ret
