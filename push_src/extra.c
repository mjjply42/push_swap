#include "../push_swap.h"

struct s_node   *setB_Tail(struct s_stack **B)
{
    struct s_node *tmp;

    tmp = (*B)->stack;
    while(tmp->next)
        tmp = tmp->next;
    return tmp;
}

void toStack(int value, struct s_stack **A)
{
    struct s_node *node;

    node = NULL;
    node = initNode(value);
    if((*A)->stack == NULL)
    {
        (*A)->stack = node;
        node->next = NULL;
    }
    else
    {
        (*A)->stack->prev = node;
        node->next = (*A)->stack;
        (*A)->stack = node;
    }
    (*A)->capacity++;
}

void    set_datum(struct s_stack **A, int *num_arr, int size)
{
    struct s_node *node;
    int i;
    int big;

    i = 0;
    node = NULL;
    big = 0;
    while(i < size)
    {
        (*A)->max_a = checkMax(num_arr[i], &big);
        i++;
    }
    i--;
    while(i >= 0)
    {
        toStack(num_arr[i], A);
        i--;
    }
}