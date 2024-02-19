NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= fractol.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"
	@make -C printf
	@make -C libft

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C libft clean
	@make -C printf clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@make -C printf fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx







# NAME = fractol

# CFLAGS = -c -Werror -Wall -Wextra

# SRCS =

# OBJS = $(SRCS: .c=.o)

# all: $(NAME)
	
# $(NAME): $(OBJ)
# 	cc -o $(NAME) $(OBJS)

# %.o: %.c
# 	cc $(CFLAGS) -o $@ $<

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all