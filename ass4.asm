;write an X86/64 ALP to count numbers of positive and negative numbers from the array


;MACRO
%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data

msg db 10,"counting +ve and -ve elements of an array",10
msglen equ $-msg
msg1 db "+ve numbers are ="
msglen1 equ $-msg1
msg2 db "-ve numbers are ="
msglen2 equ $-msg2

;CREATING AN ARRAY
array dq 1234h,90ffh,8700h,8800h,8a9h,0a0dfh,0200h
pcnt db 0   ;+VE COUNT 
ncnt db 0   ;-VE COUNT
newline db 10


section .bss
dispbuff resb 2



section .txt
global _start
_start:

print msg,msglen

mov rsi,array
mov rcx,07 ;total 7 number

again:  ;AGAIN LABEL
		bt qword[rsi],63
		jnc pnxt
		inc byte[ncnt]
		jmp pskip
	pnxt: inc byte[pcnt]
	pskip: inc rsi
loop again            ;WILL DECREMENT COUNTER(7,6,5...)
print msg1,msglen1
mov bl,[pcnt]
call disp_result ;PROCEDURE/FUNCTION
print newline,1

print msg2,msglen2
mov bl,[ncnt]
call disp_result
print newline,1

mov rax,60
mov rdi,0
syscall

disp_result:
		mov rdi,dispbuff
		mov rcx,02
	dispup1:
		rol bl,4
		mov dl,bl
		and dl,0fh
		add dl,30h
		cmp dl,39h
		jbe dispskip1    ;JUMP BELOW EQUAL
		add dl,07h
	dispskip1:
		mov [rdi],dl
		inc rdi
		loop dispup1
		print dispbuff,2
	ret




