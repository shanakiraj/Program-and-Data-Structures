;
;
;
;
;
;
	global linearSearch
	section .text
	
linearSearch:
	;starting address of array (edi) 
	;array size (esi)
	;target element(edx)
	;
	xor 	eax, eax
	xor	r10d, r10d
	
start:
	; 
	; 
	mov	eax, r10d
	cmp	edx, [edi+4*r10d]	;if the int is equal to the target 
	je	done			;jmp to done
	cmp	esi, r10d		;if counter reaches the last element
	je	do			;if equal jmp to do
	
loop:
	inc 	r10d
	jmp	start
	
do:
	mov	eax, 0			;set rax to 0
	dec	eax			;subtract one to get -1
	jmp	done			;jump to done
	
done:
	ret	
	
	
