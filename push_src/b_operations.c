#include "../push_swap.h"

//Swaps top elements of stack B
void    SB(struct s_stack **A,struct s_stack **B)
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
    add_command(A,"sb");
}

//Pushes Top element of stack A to stack B
void    PB(struct s_stack **A, struct s_stack **B)
{
    struct s_node *node;
    
    node = NULL;
    if((*A)->capacity == 0)
        return ;
    node = pop(A);
    (*A)->capacity--;
    push(B, node);
    (*B)->capacity++;
    add_command(A,"pb");
}

//Moves top element of stack B to bottom of stack
void    RB(struct s_stack **A,struct s_stack **B)
{
    struct s_node *tmp;
    struct s_node *curr;
    
    tmp = (*B)->stack;
    curr = tmp;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = curr;
    curr->prev = tmp;
    curr = curr->next;
    (*B)->stack->next = NULL;
    (*B)->stack = curr;
    add_command(A,"rb");
}

//Moves bottom element of stack B to top of stack
void    RRB(struct s_stack **A,struct s_stack **B)
{

    struct s_node *tmp;
    struct s_node *curr;

    tmp = (*B)->stack;
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
    tmp->next = (*B)->stack;
    (*B)->stack = tmp;
    add_command(A,"rrb");
}