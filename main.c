#include "push_swap.h"

struct  s_stack *toStack(int value, struct s_stack *A)
{
    struct s_node *node;

    node = NULL;
    node = initNode(value);
    if(A->stack == NULL)
    {
        A->stack = node;
        node->next = NULL;
    }
    else
    {
        A->stack->prev = node;
        node->next = A->stack;
        A->stack = node;
    }
    A->capacity++;
    return A;
}

void    set_start(struct s_stack *A, struct s_stack *B, int *num_arr, int size)
{
    struct s_node *linked;
    struct s_node *node;
    int i;
    int big;

    i = 0;
    node = NULL;
    linked = NULL;
    big = 0;
    while(i < size)
    {
        node = initNode(num_arr[i]);
        A->max_a = checkMax(node->value, &big);
        linked = initList(linked,node);
        i++;
    }
    i--;
    while(i >= 0)
    {
        A = toStack(num_arr[i], A);
        i--;
    }
    struct s_node *tmp = A->stack;
    while(tmp)
    {
        ft_printf("%i, ",tmp->value);
        tmp = tmp->next;
    }
    ft_printf("\n");
    tmp = A->stack;
    SA(A);
    while(tmp)
    {
        ft_printf("%i, ",tmp->value);
        tmp = tmp->next;
    }
    ft_printf("\n");
    B->max_a = 1;
}

int main(int ac, char **av)
{
    int length;
    int *num_list;
    struct s_stack *stackA;
    struct s_stack *stackB;

    length = ac-1;
    stackA = initStack();
    stackB = initStack();
    num_list = initArray(av, length);
    set_start(stackA, stackB, num_list, length);
    return 1;
}