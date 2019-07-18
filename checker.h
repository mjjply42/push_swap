#ifndef CHECKER_H
# define CHECKER_H
# define BUFF_SIZE 1
#include "libft/libft.h"
#include "push_swap.h"
#include "libft/printf/ft_printf.h"
#include <unistd.h>


int         check_doubles(int *num_arr,int length);
int         check_int(char *str);
void        check_formatting(char prev_char,char curr_char,char next_char);
int         check_noLet_error(int ac,char **av);
void        terminate_program();

#endif