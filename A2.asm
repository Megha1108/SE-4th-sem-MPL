%macro print 2      ;macro for print
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro read 2
mov rax,0
mov rdi,0
mov rsi,%1
mov rdx,%2
syscall
%endmacro


section .data
m db 10,"ALPto print the entered string and its length",10
l equ $-m
m1 db 10d,"enter a string: ",10
l1 equ $-m1	
m2 db 10d,"entered a string: ",10
l2 equ $-m2
m3 db 10d,"length: "
l3 equ $-m3

section .bss
buffer resb 50               ;buffer array of size 50
size equ $-buffer            ;size variable to have input
count resd 1                 ;to store size of buffer
dispnum resb 16              ;to display 16 digits length

section .text
global _start
_start:

print m,l
print m1,l1
read buffer,50

mov [count],rax              ;length of buffer gets stored in count
print m2,l2
print buffer,[count]


	call display
					;
Exit:
				mov rax,60
				mov rbx,0
				syscall

display:
mov rsi,dispnum+15           ;rsi points to 16th location of dispnum
mov rax,[count]              ;rax now store the value of count
mov rcx,16                   ;rcx gets initialised with 16
dec rax                      ;decrement the value of rax


UP1:                         ;UP1 label
mov rdx,0                    ;rdx gets initialised with 0
mov rbx,10                   ;rbx gets initialised with 10
div rbx                      ;divide the content of rax(divident) with rbx(divisor)
add dl,30h                   ;add 30 to the remainder for ascii conversion
mov [rsi],dl                 ;dl contents get copied at rsi
dec rsi                      ;decrement rsi
loop UP1


print m3,l3
print dispnum+14,02         
ret
