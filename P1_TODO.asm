; -----------------------------------------------------------------------------
; A function that returns the result of multiplying two 32-bit integer
; arguments. The function has signature:
;
;   unsigned int multByDoublingAndHalving(unsigned int, unsigned int)
;
; Note that the parameters have already been passed in edi and esi.  We
; just have to return the value in eax.
;
; @author Jacob Schrum, 8/3/2022
; -----------------------------------------------------------------------------

	global multByDoublingAndHalving
	section .text
multByDoublingAndHalving:
	mov eax, edi		; Store first parameter in EAX (A)
	mov ebx, esi		; Store second parameter in EBX (B)
	mov ecx, 0          ; Store final result here, but initialize C = 0

    ; TODO: Code written by student
    
	mov eax, ecx		; Store result C = A*B in return register EAX
	ret 				; Implicitly returns EAX