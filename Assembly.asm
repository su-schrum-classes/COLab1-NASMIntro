; -----------------------------------------------------------------------------
; Simple assembly procedure that gets called from the main function
; in a C program. The function signature is:
;
; int assemblyProcedure(int);
;
; @author Jacob Schrum, 8/4/2022
; -----------------------------------------------------------------------------

	global assemblyProcedure
	section .text
; The int parameter will be in register edi, and the return value comes from eax
assemblyProcedure:
	mov eax, edi		; Put edi in eax
	add eax, 20			; Add 20 to eax
	ret 				; Implicitly returns eax