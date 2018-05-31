segment .text
	GLOBAL _ft_isalpha
	extern _ft_isupper
	extern _ft_islower

_ft_isalpha:
	push rdi

	call _ft_isupper
	cmp rax, 0x01
	je end
	call _ft_islower
	cmp rax, 0x01
	je end
	mov rax, 0x00

end:
	pop rdi
	ret
