NAME = libft.a

CFLAGS = -c -Werror -Wall -Wextra

SRCS = ft_isalpha.c    ft_isprint.c    ft_memset.c     ft_strlcpy.c    ft_tolower.c\
ft_bzero.c      ft_isascii.c    ft_memcpy.c     ft_strchr.c     ft_strlen.c     ft_toupper.c\
ft_isalnum.c    ft_isdigit.c    ft_memmove.c    ft_strlcat.c    ft_strrchr.c	ft_strncmp.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

.c.o:
	cc $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all