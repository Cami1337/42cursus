SEVER	:= server
CLIENT	:= client
CFLAGS	:= -Wextra -Wall -Werror -Ofast
INCLUDE	:= -I./lib/libft/libft.a -I./lib/ft_printf/libftprintf.a 
LIBS	:= -L./lib/libft -L./lib/ft_printf -lft -lftprintf
SRCS	:= server.c client.c
OBJS	:= ${SRCS:.c=.o}

all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) && printf "Compiling: $(notdir $<)"
	@make -C printf
	@make -C libft

$(SERVER): server.o
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBS) -o $@

$(CLIENT): client.o
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBS) -o $@

clean:
	rm -rf *.o
	@make -C libft clean
	@make -C printf clean

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	@make -C libft fclean
	@make -C printf fclean

re: clean all


