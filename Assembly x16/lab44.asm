assume ds:data, cs:code 

;2. Sa se citeasca cate un caracter de la tastatura, fara ecou. Daca este cifra, 
;sa se tipareasca pe ecran, daca este caracterul '$', se termina programul, 
;in orice alta situatie se adauga caracterul intr-un buffer care se va tipari in final pe ecran.

data segment 
buffer db 100 dup(0) 
l equ $-buffer
data ends 

code segment
start:
	mov ax,data 
	mov ds,ax
	
	mov di, 0 ;initializez indexul bufferului	

	repeta:
		mov AH, 08h ;citesc fara ecou
		int 21h

		cmp AL, '0' ;daca nu e caracter cifra, adica intre 0-9, sar sa adaug in buffer
		JB adauga
		cmp AL, '9'
		JA adauga
		 
		mov DL, AL ;mut in dl valoarea
		mov AH, 02h ;si afisez in consola
		int 21h 
		jmp repeta ;sar si citesc din nou un caracter

	adauga:
		cmp AL, '$' ;verific daca caracterul introdus e $
		JE sfarsit ;ies din program daca e $
		mov buffer[di], al ;altfel salvez caracterul in buffer
		add di,1 ;incrementez poz la care o sa pun in buffer
		jmp repeta

	sfarsit:
		mov buffer[di], '$' ;adaug in buffer si caracterul $
		mov ah, 09h ;afisez bufferul
		mov dx, offset buffer 
		int 21h
		
		mov ax,4C00h ;ies din program
		int 21h
code ends 
end start
