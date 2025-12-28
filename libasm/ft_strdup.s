section .text
    global _ft_strdup
    extern _malloc
    extern _ft_strlen
    extern _ft_strcpy

_ft_strdup:
    push rdi ; save src
    call _ft_strlen ;rax = strlen(src)
    inc rax ;\0
    mov rdi, rax ;rdi=size
    call _malloc ;rax = new buffer
    test rax, rax
    jz .malloc_failed ;Jump if Zero
    pop rsi ;rsi = src
    mov rdi, rax ; rdi = dst
    push rax ; save dst
    call _ft_strcpy
    pop rax ; rax=dst
    ret

.malloc_failed:
    pop rdi
    xor rax, rax ;0
    ret