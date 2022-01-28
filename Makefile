NAME = libftprintf.a

SRC = ft_printf.c ft_output_for_csd.c ft_output_for_px.c ft_lstnew_bonus.c

OBJ = $(SRC:.c=.o)

GCC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)

$(OBJ): $(SRC) ft_printf.h
	cd libft && $(MAKE)
	cp libft/libft.a $(NAME)
	$(GCC) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f *.o
	cd libft && $(MAKE) clean

fclean:
	cd libft && $(MAKE) fclean
	rm -f $(NAME)
	rm -f *.o

re: fclean all

.PHONY: all clean fclean re