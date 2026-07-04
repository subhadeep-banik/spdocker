.global _start
.section .text
_start:
	mov $1 , %rax
    mov $1 , %rdi
    mov $msg, %rsi
    mov $13, %rdx
    syscall
    
    mov $60, %rax
    mov $0, %rdi
    syscall

msg:
   .asciz "Hello world \n" 
// rax-id
// rdi-1
// rsi-2
// rdx-3
// r10-4
// r8-5
// r9-6

