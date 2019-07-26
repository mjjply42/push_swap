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

P_MAIN = push_swap.c
c_MAIN = checker.c

P_SRC_C = init.c \
		helpers.c \
		a_operations.c \
		b_operations.c \
		both_operations.c \
		print.c \
		standard.c \
		extra.c \
		error.c \
		spot.c \
		final.c \
		side.c \
		stack.c \
		free_data.c \

C_SRC_C = checker.c \

P_SRC = $(addprefix push_src/, $(P_SRC_C))
C_SRC = $(addprefix check_src/, $(C_SRC_C))

P_OBJ = $(P_SRC_C:.c=.o)\
		$(P_MAIN:.c=.o)\

C_OBJ = $(C_SRC_C:.c=.o)\
		$(C_MAIN:.c=.o)\
		$(P_SRC_C:.c=.o)\

LIBFT = libft/libft.a
LIBFTH = libft/libft.h
LIBFTLINK = -L libft/ -l ft

all: $(NAME) $(NAME1)

##Compiles home made C-Standard library fucntions
$(LIBFT):
	@make -C libft

$(P_OBJ): $(P_MAIN)
	@gcc $(CFLAGS) -c $(P_MAIN) $(P_SRC)

$(C_OBJ): $(C_MAIN)
	@gcc $(CFLAGS) -c $(C_MAIN) $(C_SRC)

##Compiles Push_Swap executable and all dependencies
$(NAME): $(LIBFT) $(P_OBJ)
	@printf "Making $(Purple)push_swap$(End) . . . "
	@gcc $(P_OBJ) -o $(NAME) $(LIBFTLINK)
	@printf "$(Yellow)Done$(End)\n"

##Compiles Checker executable and all dependencies
$(NAME1): $(C_OBJ)
	@printf "Making $(Green)checker$(End) . . . "
	@gcc $(C_OBJ) -o $(NAME1) $(LIBFTLINK)
	@printf "$(Yellow)Done$(End)\n"

clean:
	@/bin/rm -rf $(P_OBJ)
	@/bin/rm -rf $(C_OBJ)

pclean: clean
	@/bin/rm -f push_swap
	@/bin/rm -f checker

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f push_swap
	@/bin/rm -f checker

re: fclean all

pre: pclean all