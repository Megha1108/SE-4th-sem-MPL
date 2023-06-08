;to accept five 64-bit hexadecimal numbers from user and store them in an array and display the accepted numbers.

%macro display 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall 
%endmacro

section .data
m1 db "please enter 5 number of 64 bits(16 digits)",10
l1 equ $-m1

m2 db "entered numbers are :",10
l2 equ $-m2

count db 05

section .bss
array resb 100

section .text
global _start
_start:

;logic to accept the numbers 
mov rbx,00
display m1,l1

up:
mov rax,00
mov rdi,00
mov rsi,array
add rsi,rbx
mov rdx,17
syscall

add rbx,17
dec byte[count]
jnz up

;display logic


display m2,l2
mov byte[count],05
mov rbx,00

up1:
mov rax,01
mov rdi,01
mov rsi,array
add rsi,rbx
mov rdx,17
syscall

add rbx,17
dec byte[count]
jnz up1

exit:
mov rax,60
mov rdi,00
syscall
