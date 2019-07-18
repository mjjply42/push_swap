#include "../push_swap.h"

void    terminate_program()
{
    ft_printf("ERROR\n");
    exit(0);
}

void    print_stack(struct s_stack **Stack)
{
    struct s_node *tmp;

    tmp = (*Stack)->stack;
    while(tmp)
    {
        ft_printf("%i    ",tmp->value);
        tmp = tmp->next;
    }
    ft_printf("\n");
}

void    print_set(struct s_stack **A, struct s_stack **B)
{
    ft_printf("A|   ");
    print_stack(A);
    ft_printf("\n");
    ft_printf("B|   ");
    print_stack(B);
    ft_printf("\n");
    ft_printf("\n");
}

void    print_moves(struct s_stack **A)
{
    struct t_list *tmp;
    int count;

    count = 0;
    tmp = (*A)->list;
    while(tmp)
    {
        count++;
        ft_printf("%s\n",tmp->command);
        tmp = tmp->next;
    }
}