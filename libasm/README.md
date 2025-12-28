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

- [ ] ft_strlen
- [ ] ft_strcpy
- [ ] ft_strcmp
- [ ] ft_write
- [ ] ft_read
- [ ] ft_strdup

## Resources

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