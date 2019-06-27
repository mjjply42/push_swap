##Colors
Black=\e[1;30m
Blue=\e[1;34m
Green=\e[1;32m
Cyan=\e[1;36m
Red=\e[1;31m
Purple=\e[1;35m
Brown=\e[1;33m
Gray=\e[1;37m
Dark_Gray=\e[1;30m
Light_Blue=\e[1;34m
Light_Green=\e[1;32m
Light_Cyan=\e[1;36m
Light_Red=\e[1;31m
Light_Purple=\e[1;35m
Yellow=\e[1;33m
White=e[1;37m
End=\e[0m


NAME = push_swap
NAME1 = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MAIN = main.c

SRC_C = init.c

SRC = $(addprefix src/, $(SRC_C))

OBJ = $(SRC_C:.c=.o)\
	  $(MAIN:.c=.o)

LIBFT = libft/libft.a
LIBFTH = libft/libft.h
LIBFTLINK = -L libft/ -l ft

all: $(NAME) $(NAME1)

##Compiles home made C-Standard library fucntions
$(LIBFT):
	@make -C libft

$(OBJ): $(MAIN)
	@gcc $(CFLAGS) -c $(MAIN) $(SRC)

##Compiles Push_Swap executable and all dependencies
$(NAME): $(LIBFT) $(OBJ)
	@printf "Making $(Purple)push_swap$(End) . . . "
	@gcc $(OBJ) -o $(NAME) $(LIBFTLINK)
	@printf "$(Yellow)Done$(End)\n"

##Compiles Checker executable and all dependencies
$(NAME1):
	@printf "Making $(Green)checker$(End) . . . "
	@gcc $(OBJ) -o $(NAME1) $(LIBFTLINK)
	@printf "$(Yellow)Done$(End)\n"

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f push_swap
	@/bin/rm -f checker

re: fclean all