NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_C = main.c

OBJ = $(SRC_C:.c=.o)

LIBFT = libft/libft.a
LIBFTH = libft/libft.h
LIBFTLINK = -L libft/ -l ft

all: $(NAME)

$(LIBFT):
	@make -C libft

$(OBJ): $(SRC_C)
	@gcc $(CFLAGS) -c $(SRC_C)

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) -o $(NAME) $(LIBFTLINK)

clean:
	@/bin/rm -rf obj

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f push_swap

re: fclean all