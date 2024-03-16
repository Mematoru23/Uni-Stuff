ASSUME cs:code,ds:data

data SEGMENT 

s1 db 4, 2, 3
ls1 equ $ - s1

s2 db 7, 8, 9, 5, 10
ls2 equ $ - s2

total_l equ ls1 + ls2
ans db total_l dup(0)

data ENDS

code SEGMENT
start:
	;2. Se dau doua siruri de octeti S1 si S2. 
	;Sa se construiasca sirul D prin concatenarea elementelor din sirul S1 1uate de la stanga spre dreapta 
	;si a elementelor din sirul S2 luate de la dreapta spre stanga.
	; init program
	mov ax, data
    mov ds, ax
	
	; Concat elemente din S1 (de la stânga la dreapta) în ans
    mov cx, ls1
    mov si, 0 ; Init index pentru S1
    mov di, 0 ; Init index pentru ans

	concat_s1:
		mov al, [s1 + si]
		mov [ans + di], al

		inc si
		inc di

		loop concat_s1

    ; Concat elemente din S2 (de la dreapta la stânga) în ans
    mov cx, ls2
	mov si, ls2 - 1

	concat_s2:
		mov al, [s2 + si]
		mov [ans + di], al

		dec si
		inc di

		loop concat_s2
	
    ; exit program
    mov ax, 4C00h
    int 21h
code ENDS
END start 