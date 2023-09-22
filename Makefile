files = ft_printf.c ft_char.c ft_itoa_unsigned.c ft_numbers.c ft_hex.c\

objects = $(files:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(objects)
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(objects)

%.o: %.c
	cc -c -Wall -Wextra -Werror $<

clean:
	rm -f ./libft/*.o
	rm -f $(objects)

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re