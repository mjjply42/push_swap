#include "../push_swap.h"

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