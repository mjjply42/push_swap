#include "../push_swap.h"

void    SB(struct s_stack *B)
{
    struct s_stack *b;
    struct s_node *tmp;

    b = B;
    tmp = b->stack;
    if(b->capacity == 0 || b->capacity == 1)
        return ;
    else
    {
        tmp = tmp->next;
        swap(&b->stack->value, &tmp->value);
    }
}