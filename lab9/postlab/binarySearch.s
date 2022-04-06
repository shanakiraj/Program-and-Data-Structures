
	global binarySearch
	section .text
	
binarySearch:
	;address of first element(edi)
	;lowest (esi)
	;highest (edx)
	;target (ecx)
	
	xor	eax, eax
	xor	r10d, r10d
	xor	r11d, r11d

start:
	;
	;
	cmp 	esi, edx
	jg	end
	mov	r10d, esi
	add	r10d, edx
	shr	r10d, 1
	mov 	r11d, [edi+4*r10d]
	cmp 	r11d, ecx
	jg	greater
	je	equal
	inc	r10d
	mov	esi, r10d
	jmp	start
	
greater:
	
	dec	r10d
	mov	edx, r10d
	jmp	start

equal: 
	mov	eax, r10d
	ret

end:
	mov	eax, 1
	neg 	eax
	ret

