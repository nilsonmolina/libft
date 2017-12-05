NAME = libft.a
FLAGS = -Wall -Wextra -Werror
C_FILES = ft_*.c
O_FILES = ft_*.o

$(NAME):
	gcc -c $(FLAGS) $(C_FILES)
	ar rc libft.a $(O_FILES) libft.h
	ranlib libft.a

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean 
	rm -rf $(NAME)

re: fclean all
