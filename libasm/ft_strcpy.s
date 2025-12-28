section .text
    global _ft_strcpy

_ft_strcpy:
    xor rax, rax
    mov r8, rdi

.loop:
    mov cl, byte [rsi + rax]
    mov byte [rdi + rax], cl
    cmp cl, 0
    je .done
    inc rax
    jmp .loop

.done:
    mov rax, r8
    ret