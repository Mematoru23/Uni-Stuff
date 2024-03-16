ASSUME cs:code, ds:data

data SEGMENT
    numar db ?
	sir db 20, ?, 20 dup(0)
    msg_paritate db 13, 10, 'Paritate: $'
    msg_impar db 'impar$'
    msg_par db 'par$'
data ENDS

code SEGMENT
start:
    mov ax, data
    mov ds, ax

    mov ah, 0Ah
	mov dl, offset sir
    int 21h
		
    mov ah, 09h
	lea dx, sir
    int 21h

    mov ah, 0
    mov al, numar
    test al, 1
    jz par	
	
    impar:
        mov ah, 09h
        lea dx, msg_impar
        int 21h
        jmp end_program
    par:
        mov ah, 09h
        lea dx, msg_par
        int 21h

    end_program:
    mov ah, 4Ch
    int 21h
code ENDS
end start
