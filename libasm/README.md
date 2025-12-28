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

## Build
```bash
make            # Build library
make test       # Build test program
./test          # Run tests
make clean      # Clean objects
make fclean     # Clean everything
make re         # Rebuild
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


gcc main.c -L. -lasm -o