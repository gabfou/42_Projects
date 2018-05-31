segment .text
	GLOBAL _ft_bzero

_ft_bzero:
	push rdi
	push rsi
	cmp rsi, 0
	je end
	mov rcx, rsi

_while:
	mov byte [rdi], 0x00
	inc rdi
	loop _while

end:
	pop rsi
	pop rdi
ret
