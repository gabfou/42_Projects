segment .text
	GLOBAL _ft_isprint

_ft_isprint:
	push rdi
	cmp rdi, 0x20
	jb error
	cmp rdi, 0x7e
	ja error
	mov rax, 0x01
	jmp end

error :
	mov rax, 0x00

end :
	pop rdi
	ret
