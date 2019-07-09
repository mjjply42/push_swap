#include "../push_swap.h"

/*void    SA(struct s_stack *A)
{
    struct s_stack *a;
    struct s_node *tmp;

    a = A;
    tmp = a->stack;
    if(a->capacity == 0 || a->capacity == 1)
        return ;
    else
    {
        tmp = tmp->next;
        swap(&a->stack->value, &tmp->value);
    }
}*/

void SA(struct s_stack **A)
{
    struct s_stack **a;
    struct s_node *tmp;
    
    a = A;
    tmp = (*a)->stack;
    if((*a)->capacity == 0 || (*a)->capacity == 1)
        return ;
    else
    {
        tmp = (*a)->stack->next;
        tmp->next->prev = (*a)->stack;
        (*a)->stack->next = tmp->next;
        tmp->next = (*a)->stack;
        tmp->prev = NULL;
        (*a)->stack = tmp;
    }
}