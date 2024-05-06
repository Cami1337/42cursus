# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 17:50:33 by lglauch           #+#    #+#              #
#    Updated: 2024/05/06 13:48:28 by lglauch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CFLAGS	:= -Wextra -Wall -Werror
SRCS	:= src/main.c src/globals.c src/tokenizer.c
OBJS	:= ${SRCS:src/%.c=src/%.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a printf/libftprintf.a -lreadline

src/%.o: src/%.c
	@make -C libft
	@make -C printf
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@make -C libft clean
	@make -C printf clean
	rm -rf src/*.o

fclean: clean
	@make -C libft fclean
	@make -C printf fclean
	rm -rf $(NAME)

re: clean all