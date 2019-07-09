#include "push_swap.h"

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
    //struct s_node *linked;
    struct s_node *node;
    int i;
    int big;

    i = 0;
    node = NULL;
    //linked = NULL;
    big = 0;
    while(i < size)
    {
        //node = initNode(num_arr[i]);
        (*A)->max_a = checkMax(/*node->value*/num_arr[i], &big);
        //linked = initList(linked,node);
        i++;
    }
    i--;
    while(i >= 0)
    {
        toStack(num_arr[i], A);
        i--;
    }
}

int main(int ac, char **av)
{
    int length;
    int *num_list;
    struct s_stack *A;
    struct s_stack *B;

    length = ac-1;
    A = initStack();
    B = initStack();
    num_list = initArray(av, length);
    set_datum(&A, num_list, length);
    print_set(&A, &B);
    PB(&A, &B);
    PB(&A, &B);
    PB(&A, &B);
    RRA(&A);
    print_set(&A, &B);
    return 1;
}