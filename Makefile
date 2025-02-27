CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strncmp.c \
			ft_memcmp.c \
			ft_memchr.c \
			ft_strlcpy.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_memmove.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strlcat.c \
			ft_strmapi.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_strdup.c \
			ft_striteri.c
CFILES = $(FILES:%.c=src/%.c)
OFILES = $(FILES:%.c=obj/%.o)

NAME = libft.a

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OFILES)
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
