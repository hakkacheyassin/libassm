section .text
    global _ft_strcmp

_ft_strcmp:
    xor rax, rax

.loop:
    mov cl, byte [rdi + rax]
    mov dl, byte [rsi + rax]
    cmp cl, dl
    jne .difference
    cmp cl, 0
    je .equal
    inc rax
    jmp .loop

.equal:
    xor rax, rax
    ret

.difference:
    movzx rax, cl
    movzx rdx, dl
    sub rax, rdx
    ret