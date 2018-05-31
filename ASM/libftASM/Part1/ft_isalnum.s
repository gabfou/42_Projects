segment .text
	GLOBAL _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	push rdi

	call _ft_isalpha
	cmp rax, 0x01
	je end
	call _ft_isdigit
	cmp rax, 0x01
	je end
	mov rax, 0x00

end:
	pop rdi
	ret
