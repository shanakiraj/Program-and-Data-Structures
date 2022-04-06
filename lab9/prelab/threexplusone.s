
	global threexplusone
	section .text
	
threexplusone:
	; starting num (rdi)
	xor	rax, rax		;got rid of extra r10 "xor" line
start:
	mov	r10, 1
	cmp 	rdi, r10
	je	end
loop:
	inc	rax 			;got rid of pushes and pops of rax
	mov 	r11, rdi		;using bitshift saved the use of rax register
	and	r11, 1			;using "and" to tell if function is odd
	cmp	r11, 0
	jne	next		
	shr	rdi, 1			;bitshift instead of idiv
	call	start
	jmp	end
next:
	imul	rdi, rdi, 3		;realized I could use lea for this but it was kind of confusing
	inc 	rdi
	call	start
end:	
	ret


