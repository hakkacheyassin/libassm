section .text
    global _ft_strdup
    extern _malloc
    extern _ft_strlen
    extern _ft_strcpy

_ft_strdup:
    push rdi
    call _ft_strlen
    inc rax
    mov rdi, rax
    call _malloc
    test rax, rax
    jz .malloc_failed
    pop rsi
    mov rdi, rax
    push rax
    call _ft_strcpy
    pop rax
    ret

.malloc_failed:
    pop rdi
    xor rax, rax
    ret