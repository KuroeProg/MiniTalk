NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_integers.c ft_puthexa.c ft_putptr.c \
		ft_putstr.c ft_unsignednbr.c

OBJECTS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		rm -f $(OBJECTS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean re all
