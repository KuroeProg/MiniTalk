NAME = libft.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRCS := ft_atoi.c

OBJ := $(SRCS:.c=.o)

INC_DIR = includes

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re