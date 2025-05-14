;to perform non overlapped block transfer without string specific instruction


%macro print 2
mov rax ,1
mov rdi ,1
mov rsi ,%1
mov rdx ,%2
syscall
%endmacro

section .data
m db 10,"ALP to perform BDT without using string related INsruction",10
l equ $-m

m1 db 10,"Source block content before transfer:-"
l1 equ $-m1

m2 db 10,"destination block content after transfer:-"
l2 equ $-m2

space db " "
spacelen equ $-space
cnt equ 5

srcblk db 10h,20h,30h,40h,50h
dstblk db 00,00,00,00,00,00

section .bss
ans resb 2

section .text
global _start
_start:

print m,l
print m1,l1

mov rsi,srcblk
call display

print m2,l2
mov rsi,srcblk
mov rdi,dstblk
mov rcx,05
again:
mov dl,[rsi]
mov[rdi],dl
inc rsi
inc rdi
loop again

mov rsi,dstblk
call display

exit:
mov rax,60
mov rdi,0
syscall

display:
mov rbp,cnt
up:mov al,[rsi]
push rsi
call disp_8
print space,1
pop rsi
inc rsi
dec rbp
jnz up
ret

disp_8:
mov rdi,ans
mov rcx,02
up1:

	rol al,4
	mov dl,al
	and dl,0fh
	add dl,30h
	cmp dl,39h
	jbe dispskip1
	add dl,07h
	
dispskip1:
	mov [rdi],dl
	inc rdi
	loop up1
	print ans,2
	ret


