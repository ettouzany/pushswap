SRCS=push_swap.c parser.c debug.c instructions/swap.c
NAME= push_swap
FLAGS=-Wall -Wextra -Werror
CC=gcc
OBJ = ${SRCS:.c=.o}

%.o:%.c
	@cc ${flags} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	Make -C libft
	$(CC) $(FLAGS) $(OBJ) libft/libft.a -o ${NAME}
	echo "Compilation finished"

clean:
	@Make -C libft clean
	@rm -f	$(OBJ) $(NAME)

fclean: clean
	@rm	-f $(NAME)