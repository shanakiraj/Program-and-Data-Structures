; mathlib.s
;
;
;Param 1 (in rdi)
;Param 2 (in rsi)
;
;
;
	global product
	global power
	section .text
	
product:
	;
	;zero out return register and counter
	
	xor	rax, rax
	xor	r10, r10
prod_start:
	;
	;
	cmp	r10, rsi	;check i==n
	je	prod_done	;if so exit loop
	add	rax, rdi 	;add num to rax which holds the sum
	inc	r10		;increment counter i by one
	jmp	prod_start	;jmp to start of loop
	
prod_done: 	
	;returns rax
	ret
;
;


power:
	mov	rax, 1		;set rax to one
	mov 	r11, rsi 	;extra rsi holding var
	cmp	r11, 1 	;check if r11 less than zero
	jl	pow_done 	;if so jump to end and return rax
	sub	r11, 1 	;subtract r11 by one
	mov	rsi, r11 	;move rll into rsi so rsi is effectively -1	
pow_recurse:
	call	power 		;recursively calls power after rsi and r11 is set -1
	mov	rsi, rax	;set rsi to rax 
	call	product 	;call product
pow_done:
	ret


