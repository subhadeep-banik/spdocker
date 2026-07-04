section .bss
        digitSpace resb 100
        digitSpacePos resb 8
     
section .data
        text db "Hello, World!",10,0
     
section .text
        global _start
     
_start:
     
        mov rax, 25619
        call _printRAX
     
        mov rax, 60
        mov rdi, 0
        syscall
     
     
_printRAX:
        mov rcx, digitSpace
        mov rbx, 10
        mov [rcx], rbx
        inc rcx
 
     
_printRAXLoop:
        mov rdx, 0
        mov rbx, 10
        div rbx
 
        add rdx, 48
     
 
        mov [rcx], dl
        inc rcx
 
        
 
        cmp rax, 0
        jne _printRAXLoop
     
_printRAXLoop2:
 
        dec rcx
        mov rax, 1
        mov rdi, 1
        mov rsi, rcx
        mov rdx, 1
        push rcx
        syscall
        pop rcx
 

 
     
        cmp rcx, digitSpace
        jge _printRAXLoop2
     
        ret


