SRCS = ft_strlen.c ft_strcmp.c ft_addchar.c ft_strdup.c\
ft_memcpy.c ft_realloc.c ft_strrchr.c ft_itoa.c ft_putchar.c\
ft_putstr.c ft_putnbr.c ft_strsplit.c ft_atoi.c ft_isdigit.c
NAME = libft.a


FLAGS=-Wall -Wextra -Werror

OBJ=$(SRCS:.c=.o)

%.o : %.c libft.h
	@$(CC) $(FLAGS) -c $< -o $@


$(NAME): $(OBJ)
	@ar rcs $@ $^

all: $(NAME)

clean:
	@rm -f	$(OBJ) $(NAME)

fclean: clean
	@rm	-f $(NAME)

re: fclean all