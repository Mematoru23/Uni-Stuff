ASSUME ds:data, cs:code

;2. Sa se citeasca cate un caracter de la tastatura, fara ecou. Daca este cifra, 
;sa se tipareasca pe ecran, daca este caracterul '$', se termina programul, 
;in orice alta situatie se adauga caracterul intr-un buffer care se va tipari in final pe ecran.

data SEGMENT
s db 20 dup(0)
buffer db 256 dup(0) ; buffer pentru caractere
count dw 0 ; numar caracterele
data ENDS

code SEGMENT
start:
    mov ax, data
    mov ds, ax

	bucla:
    mov ah, 08h ; functia de citire a unui caracter fara ecou
    int 21h ; citirea caracterului

    cmp al, '$' ; verifica daca caracterul este '$'
    je inchide ; daca da, incheie programul

    cmp al, '0' ; verifica daca caracterul este o cifra
    jl salvare ; daca nu, stocheaza
    cmp al, '9'
    jg salvare

    ; daca este o cifra, tipareste
    mov ah, 02h
    int 21h
    jmp bucla

	salvare:
		; daca nu este o cifra, stocheaza in buffer
		mov ah, 0
		mov bx, count
		mov [buffer + bx], al
		inc count
		jmp bucla

	inchide:
		; la sfarsit, tipareste bufferul
		mov ah, 09h
		lea dx, buffer
		int 21h
		
		mov ax, 4c00h 
		int 21h

code ends
end start