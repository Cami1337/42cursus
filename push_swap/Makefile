NAME = push_swap

CFLAGS = -c -Werror -Wall -Wextra

SRCS = algorithm.c errors.c check_input.c helper.c push_swap.c sorting.c operations/push.c operations/rotate.c operations/swap.c operations/reverse_rotate.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) libft/libft.a printf/libftprintf.a

%.o: %.c
	@make -C libft
	@make -C printf
	cc $(CFLAGS) -o $@ $<

clean:
	@make -C libft clean
	@make -C printf clean
	rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@make -C printf fclean
	rm -f $(NAME)

re: fclean all