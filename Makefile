NAME = libftprintf.a

SRC = ft_printf.c output_for_csd.c output_for_px.c ft_lstnew.c flags.c \
output_for_u.c utils.c

SRC_BONUS = ft_printf_bonus.c output_for_csd_bonus.c output_for_px_bonus.c \
ft_lstnew_bonus.c flags_bonus.c output_for_u_bonus.c utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

D_FILES = $(SRC:.c=.d)

D_BONUS_FILES = $(SRC_BONUS:.c=.d)

GCC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ) ft_printf.h
	cd libft && $(MAKE)
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(NAME) $(OBJ_BONUS) ft_printf_bonus.h
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $? -o $@ -MD

clean:	
	rm -f $(OBJ) 
	rm -f $(OBJ_BONUS)
	rm -f $(D_FILES)
	rm -f $(D_BONUS_FILES) 
	cd libft && $(MAKE) clean

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus