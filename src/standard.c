#include "../push_swap.h"

void    push(struct s_stack **st, struct s_node *node)
{
    node->next = (*st)->stack;
    (*st)->stack = node;
}

struct s_node *pop(struct s_stack **st)
{
    struct s_node *tmp;

    tmp = (*st)->stack;
    (*st)->stack = tmp->next;
    tmp->next = NULL;
    return tmp;
}