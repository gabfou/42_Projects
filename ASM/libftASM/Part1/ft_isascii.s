segment .text
	GLOBAL _ft_isascii

_ft_isascii:
	push rdi
	cmp rdi, 0x00
	jb error
	cmp rdi, 0x7f
	ja error
	mov rax, 0x01
	jmp end

error :
	mov rax, 0x00

end :
	pop rdi
	ret
