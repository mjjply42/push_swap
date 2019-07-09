#include "../push_swap.h"

void SA(struct s_stack **B)
{
    struct s_stack **b;
    struct s_node *tmp;
    
    b = B;
    tmp = (*b)->stack;
    if((*b)->capacity == 0 || (*b)->capacity == 1)
        return ;
    else
    {
        tmp = (*b)->stack->next;
        tmp->next->prev = (*b)->stack;
        (*b)->stack->next = tmp->next;
        tmp->next = (*b)->stack;
        tmp->prev = NULL;
        (*b)->stack = tmp;
    }
}