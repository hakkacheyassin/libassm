NAME = libasm.a
OBJS = ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o ft_read.o ft_strdup.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.s
	nasm -f macho64 $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test

re: fclean all

run: all
	gcc main.c -L. -lasm -o test
	./test

.PHONY: all clean fclean re