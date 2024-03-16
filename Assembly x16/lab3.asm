;sir db -2,2,-10,4,-10,40,100,96
assume cs:code,ds:data

data segment
	sir db -2,2,-10,4,-10,40,100,96
	l equ ($-sir)	
	sir_rez db l dup(?)
	cate db 0
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax
	mov cx, l  ; punem in cx lungimea primului sir 
	mov si, offset sir
	mov di, offset sir_rez
	cld
	repeta:
		lodsb ; DS:SI -> al, SI = SI + 1
		mov bx,cx ; copiem cx in bx deoarece lucram cu cx in al doilea loop
		mov cate, 0
		mov cx, 8; punem in cx 8 deoarece parcurgem octetul pe biti
		mov ah, al; copiem al in ah deoarece distrugem al cand il parcurgem
		suma:
			shl ah, 1
			adc cate, 0
			clc
		loop suma 
		cmp cate, 5; comparam numarul de biti de 1 din octet cu 5 deoarece trebuie sa avem un >= 5 biti de 1
		jae adauga
		cmp al, 1Fh
		jl exit_mai_mic
		cmp al, 60h
		jng adauga
		exit_mai_mic:
			mov al,0
		adauga:
			stosb; ES:DI <- al,DI = DI + 1
		mov cx, bx
	loop repeta
	mov ax, 4c00h
	int 21h
code ends
end start