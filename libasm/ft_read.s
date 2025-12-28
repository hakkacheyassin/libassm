section .text
global _ft_read
extern ___error

_ft_read:
    mov rax, 0x2000003     
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
