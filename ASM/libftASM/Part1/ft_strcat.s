segment .text
	global _ft_strcat

_ft_strcat:
	mov r9, rdi
	xor al, al

first_loop:
	cmp byte [rdi], 0
	je second_loop
	inc rdi
	jmp first_loop

second_loop:
	cmp byte [rsi], 0
	je end
	mov rax, [rsi]
	mov [rdi], al
	inc rsi
	inc rdi
	jmp second_loop

end:
	mov byte [rdi], 0
	mov rax, r9
	ret