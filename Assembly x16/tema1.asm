ASSUME cs:text,ds:data

data SEGMENT 
a dw -1
b db 2
res dw ?
data ENDS

text SEGMENT

start:
    ;z=a+bb-(2/(b*b))/(1+2/(b*b))
    mov ax, data
    mov ds, ax

    ;b b
    mov al, b ; al = b
    mul al ; ax = al * b -> al * al -> b * b = 2 * 2 = 4

    ;2 / b * b
    mov bx, ax ; bx = ax = 4
    mov ax, 2 ; ax = 2
    cwd ; ax = 2 -> dx:ax = 2
    idiv bx ; ax = dx:ax / bx = 2 / 4; ax = 0, dx = 2

    ; 1+2/(b*b)
    mov cx, ax ; cx = 2 / b b = 0
    add cx, 1 ; cx = 1 + 2 / b * b = 1

    ;(2/(bb))/(1+2/(bb))
    cwd ; ax -> dx:ax
    idiv cx ; ax = dx:ax / cx = (2/(b*b))/(1+2/(b*b)) = 0 / 1 = 0
    mov cx, ax ; cx = (2/(b*b))/(1+2/(b*b))

    ; b * b
    mov al, b
    imul al ; ax = al * b = b * b = 4
    add ax, a ; ax = ax + a = 4 + 1 = 5

    sub ax, cx ; ax = 5 - 0 = 5
    mov res, ax

    ; exit program
    mov ax, 4C00h
    int 21h

text ENDS

END start