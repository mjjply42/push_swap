#include "../push_swap.h"

void    push(struct s_stack **st, struct s_node *node)
{
    node->next = (*st)->stack;
    if((*st)->stack == NULL)
        (*st)->stack = node;
    else
    {
        (*st)->stack->prev = node;
        (*st)->stack = node;
    }
    
}

struct  s_node *pop(struct s_stack **st)
{
    struct s_node *tmp;

    tmp = (*st)->stack;
    (*st)->stack = tmp->next;
    tmp->next = NULL;
    return tmp;
}

int     isEmpty(struct s_stack **stack)
{
    int ret;

    ret = 0;
    if((*stack)->stack == NULL)
        ret = 1;
    else
        ret = 0;
    return ret;
}