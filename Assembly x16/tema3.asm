ASSUME cs:code,ds:data

data SEGMENT 

s1 db 2, 1, 3, 3, 4, 2, 6
ls1 equ $ - s1

s2 db 4, 5, 7, 6, 2, 1
ls2 equ $ - s2

total_l equ ls1 + ls2
ans db total_l dup(0)

data ENDS

code SEGMENT
start:
	;13. Se dau 2 siruri de octeti A si B. 
	;Sa se construiasca sirul R care sa contina elementele lui B in ordine inversa 
	;urmate de elementele pare ale lui A. 
	mov ax, data
    mov ds, ax
	
	; Concat elemente din S2 (de la dreapta la stânga) în ans
    mov cx, ls2
    mov si, ls2 - 1 ; Init index pentru S2 cu ultima poz
    mov di, 0 ; Init index pentru ans

	concat_s2:
		mov al, [s2 + si]
		mov [ans + di], al

		dec si
		inc di

	loop concat_s2

	; Concat elemente pare din S1 (de la stânga la dreapta) în ans
    mov cx, ls1
    mov si, 0 ; Init index pentru S1

	concat_s1:
		mov al, [s1 + si]
		test al, 1
		jnz next ; Dacă numărul este impar, treci la următorul

		mov [ans + di], al
		inc di

		next:
			inc si
	loop concat_s1
	
    ; exit program
    mov ax, 4C00h
    int 21h
code ENDS
END start