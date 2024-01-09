NAME = push_swap.a

CFLAGS = -c -Werror -Wall -Wextra

SRCS = errors.c helper.c push_swap.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) libft/libft.a printf/libftprintf.a

$(OBJ): $(SRCS)
	@make -C libft
	@make -C printf
	cc $(CFLAGS) $(SRCS)

clean:
	@make -C libft clean
	@make -C printf clean
	rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@make -C printf fclean
	rm -f $(NAME)

re: fclean all