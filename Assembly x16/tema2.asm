ASSUME cs:code,ds:data

data SEGMENT 
a dw 100001011b ; 267
b dw 11111010011b ; 2003
c dw ?
data ENDS

code SEGMENT
start:
	; 1. Se dau doua cuvinte A si B. Sa se obtina cuvÃ¢ntul C:
	; - bitii 0-2 ai lui C coincid cu bitii 7-9 ai lui A
    ; - bitii 3-6 ai lui C coincid cu bitii 9-12 ai lui B
	; - bitii 7-15 ai lui C au valoarea 0
	; init program
	mov ax, data
    mov ds, ax
	
	; a, b -> ax, bx
    mov ax, a
	mov bx, b
	xor cx, 0 ; in cx creez rezultatul
	
	; bitii 0-2 ai lui C coincid cu bitii 7-9 ai lui A
	shr ax, 7 ; 000000>010<(0001011) - izolez bitii A[7-9] in cei mai de jos 3 biti, ptr a-i pune in C[0-2]
	and ax, 000000000000111 ; sterg bitii superiori si salvez cei mai de jos biti cu ajutorul mastii
	or cx, ax ; pun o parte de rez in cx(C) - 0000000000000>010<
	
	; bitii 3-6 ai lui C coincid cu bitii 9-12 ai lui B
	shr bx, 9 ; 000>0011<(111010011) - izolez bitii B[9-12] in cei mai de jos 4 biti, ptr a-i pune in C[3-6]
	and bx, 000000000001111 ; sterg bitii superiori si salvez ce am nevoie cu ajutorul mastii
	shl bx, 3 ; mut bitii 3 poz la stanga ptr a-i alinia cu C[3-6]
	or cx, bx ; combin rezultatele in cel final - 000000000>0011<>010< C[0-2][3-6], [7-15] e 0 deja
	
	; bitii 7-15 ai lui C au valoarea 0 - 0000000000011010 C[7-15] sunt 0
	; copiez rez in c si obtinem c
	mov c, cx ; C = 26 = 1Ah
	
    ; exit program
    mov ax, 4C00h
    int 21h
code ENDS
END start 