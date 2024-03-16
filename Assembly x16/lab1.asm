; Sa se calculeze expresia aritmetica :
; e=((a+b*c-d)/f+g*h)/i

; Am considerat a,d,f - cuvant
; b,c,g,h,i -byte
; ca sa putem executa impartirea cu f convertim impartitorul la dublucuvant
; ne vor interesa doar caturile impartirilor
; rezultatul va fi de tip octet


assume cs:code,ds:data
data segment
a dw 5
b db 6
c db 10
d dw 5
f dw 6
g db 10
h db 11
i db 10
interm dw ?
rez db ?
data ends
code segment
incepe:
mov ax,data
mov ds,ax
mov al,b
imul c
; in ax avem b*c
add ax,a
; ax=b*c+a
sub ax,d
; ax=b*c+a-d
cwd
; am convertit cuvantul din ax , in dublu cuvantul , retinut in dx:ax
idiv f
; obtinem catul in ax
; si restul in dx
; ax=(a+b*c-d)/f
mov interm, ax
; interm=(a+b*c-d)/f
mov al,g
imul h
; ax=g*h
add ax, interm
;ax=(a+b*c-d)/f+g*h
idiv i
; obtinem catul in al si restul in ah
mov rez,al
mov ax, 4C00h
int 21h
code ends
end incepe


; Date de test : vom obtine rezultatul ((a+b*c-d)/f+g*h)/i=((5+6*10-5)/6+10*11)/10=12