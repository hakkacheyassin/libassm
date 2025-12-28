section .text
global _ft_write
extern ___error

_ft_write:
    mov rax, 0x2000004     
    syscall
    jc .error
    ret

.error:
    push r14                
    mov r14, rax           
    call ___error           
    mov [rax], r14        
    pop r14
    mov rax, -1
    ret
