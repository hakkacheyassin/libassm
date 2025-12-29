# Libasm Project

Assembly library implementation.

## Structure
```
libasm/
├── ft_strlen.s      - String length
├── ft_strcpy.s      - String copy
├── ft_strcmp.s      - String compare
├── ft_write.s       - Write syscall
├── ft_read.s        - Read syscall
├── ft_strdup.s      - String duplicate
├── main.c           - Test program
├── Makefile         - Build system
└── README.md        - This file
```

## Build![alt text](https://www.tutorialspoint.com/assembly_programming/images/register1.jpg)
```bash
make            # Build library
make clean      # Clean objects
make fclean     # Clean everything
make re         # Rebuild
make run
```

## Progress

- [X] ft_strlen
- [X] ft_strcpy
- [X] ft_strcmp
- [X] ft_write
- [X] ft_read
- [X] ft_strdup

## Resources


┌─────────┬──────────┬────────┬──────────┐
│  64-bit │  32-bit  │ 16-bit │  8-bit   │
├─────────┼──────────┼────────┼──────────┤
│  RAX    │  EAX     │  AX    │  AL, AH  │
│  RBX    │  EBX     │  BX    │  BL, BH  │
│  RCX    │  ECX     │  CX    │  CL, CH  │
│  RDX    │  EDX     │  DX    │  DL, DH  │
│  RSI    │  ESI     │  SI    │  SIL     │
│  RDI    │  EDI     │  DI    │  DIL     │
│  RSP    │  ESP     │  SP    │  SPL     │
│  RBP    │  EBP     │  BP    │  BPL     │
└─────────┴──────────┴────────┴──────────┘

- NASM syntax: https://nasm.us/doc/
## info 
RCX  = 64 bits = 8 bytes  
ECX  = 32 bits = 4 bytes  
CX   = 16 bits = 2 bytes  
CL   = 8 bits  = 1 byte   
CH   = 8 bits  = 1 byte   

## CPU Register

         ┌───────────────────────┐
         │      CPU Core         │
         │                       │
         │ ┌───────────────┐     │
         │ │  Registers    │     │
         │ │  RAX RBX RCX  │     │
         │ │  RDX RDI RSI  │     │
         │ │  RSP RBP R8-15│     │
         │ └───────────────┘     │
         │                       │
         │ ┌───────────────┐     │
         │ │   ALU         │◄────┤
         │ │ (add, sub...) │     │
         │ └───────────────┘     │
         │                       │
         │ ┌───────────────┐     │
         │ │ Control Unit  │     │
         │ │ (decodes instr)│    │
         │ └───────────────┘     │
         └─────────┬─────────────┘
                   │
                   ▼
         ┌───────────────────────┐
         │      Memory / Stack   │
         │  [data, instructions] │
         └───────────────────────┘

## IMPORTANT REGISTERS

RAX	Return value
AL / AH	8-bit parts of RAX
RDI	Arg 1
RSI	Arg 2
RDX	Arg 3
DL	Low 8-bit of RDX
RCX	Arg 4
CL	Low 8-bit of RCX
R8	Arg 5
R9	Arg 6
RSP	Stack pointer
RBP




gcc main.c -L. -lasm -o


section .data
    a        db 12
    b        db 3
    product  db 0
    quotient db 0

section .text
    global _start

_start:
    mov cl, [a]
    mov al,[b]
    mul cl
    mov [product],al
    xor cl,cl
    xor al,al

    mov cl,[a]
    xor ah, ah 
    div bl

    mov [quotient],bl

    ; exit
    mov rax, 60
    xor rdi, rdi
    syscall
