.model small
.data

r1 db 0
r2 db 0
r3 db 0 
r4 db 0
r5 db 0
r6 db 0
r7 db 0
r8 db 0
r9 db 0
r10 db 0 
resi db 0 

;cadenas:  
cad2 db 10,13, "Resultado:  $"

.stack
.code
;Inicio de la seccion de operaciones



;MULTIPLICACION
MOV AL, 8
MOV BX, 8
MUL BL
MOV r1,AL

;DIVISION
MOV AL, 16
MOV BL, 4
DIV BL
MOV r2,AL

;RESTA
MOV AL, r1
MOV BL, r2SUB AL,BL
MOV r3,AL

;SUMA
MOV AL, r3
MOV BL, 2
ADD AL,BL
MOV r4,AL

;imprimir cadena "Resultado: "
mov ah,09h
mov dx,offset cad2  ;mueve la cadena a imprimir
mov ah,09          ;instruccion de int 21h
int 21h            ;interrupcion

;imprimir resultado <99
xor ah,ah           ;registros en 0
MOV AL, r4
aam                 ;ajuste para numeros de dos digitos
mov bx,ax           ;movimiento de registros
add bx,3030h        ;conversion a base 10

;imprimir primer digito
mov ah,02           ;intruccion de int 21h
mov dl,bh           ;mover al registro de impresion
int 21h

;imprimir 2do digito
mov ah,02
mov dl,bl
int 21h

.exit