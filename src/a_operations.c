#include "../push_swap.h"

void    SA(struct s_stack **A)
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
    add_command(A, "sa");
}

void    PA(struct s_stack **B, struct s_stack **A)
{
    struct s_node *node;
    
    node = NULL;
    if((*A)->capacity == 0)
        return ;
    node = pop(B);
    (*B)->capacity--;
    push(A, node);
    (*A)->capacity++;
    add_command(A,"pa");
}

void    RA(struct s_stack **A)
{
    struct s_node *tmp;
    struct s_node *curr;
    
    tmp = (*A)->stack;
    curr = tmp;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = curr;
    curr->prev = tmp;
    curr = curr->next;
    (*A)->stack->next = NULL;
    (*A)->stack = curr;
    add_command(A,"ra");
}

void    RRA(struct s_stack **A)
{

    struct s_node *tmp;
    struct s_node *curr;

    tmp = (*A)->stack;
    curr = tmp;
    if(tmp->next)
    tmp = tmp->next;
    while(tmp->next)
    {
        curr = tmp;
        tmp = tmp->next;
    }
    tmp->prev = NULL;
    curr->next = NULL;
    tmp->next = (*A)->stack;
    (*A)->stack = tmp;
    add_command(A,"rra");
}