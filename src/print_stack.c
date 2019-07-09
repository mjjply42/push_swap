#include "../push_swap.h"

void    print_stack(struct s_stack **Stack)
{
    struct s_node *tmp;

    tmp = (*Stack)->stack;
    while(tmp)
    {
        ft_printf("%i, ",tmp->value);
        tmp = tmp->next;
    }
    ft_printf("\n");
}