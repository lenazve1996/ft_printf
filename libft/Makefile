NAME		=	libft.a
CC			= 	gcc
FLAGS		= 	-Wall -Wextra -Werror
SRC			= 	ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c \
ft_tolower.c ft_toupper.c ft_atoi.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putendl_fd.c  ft_putnbr_fd.c
OB			=	$(SRC:.c=.o)

BONUS_SRC	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

override TMP_OBJ ?= $(OB)

$(NAME) : $(TMP_OBJ)
		ar rc $(NAME) $?
		ranlib $(NAME)

all : $(NAME)

%.o : %.c libft.h
		$(CC) $(FLAGS) -c $< -o $@

bonus :
		@make TMP_OBJ="$(BONUS_OBJ)" all

clean:
		rm -f $(OB) $(BONUS_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONE: clean fclean re all bonus
