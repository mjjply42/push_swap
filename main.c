#include "push_swap.h"

void    setCue(struct s_stack **A,int *num_arr)
{
    int i;

    i = (*A)->max_a;
    while(num_arr[i] != 1 && i > 0)
        i--;
    if(num_arr[i] == 1)
    {
        (*A)->end = (i)*-1;
        return ;
    }
    while(num_arr[i] != 2 && i < (*A)->max_a)
        i++;
    (*A)->end = i; 
}
void    push_swap(struct s_stack **A, struct s_stack **B)
{
    int num_arr[(*A)->max_a];
    struct s_node *tmp;

    tmp = (*A)->stack;
    set_count_array(A,num_arr);
    setCue(A,num_arr);
    for(int i = 0; i <= (*A)->max_a; i++)
        ft_printf("Index: %i      Value:  %i  \n", i, num_arr[i]);
    while(tmp->next)
        tmp = tmp->next;
    (*A)->tail = tmp;
    (*A)->pivot = splitter(A,B);
    if(isSorted(A) && isEmpty(B))
    {
        print_set(A,B);
        print_moves(A);
        return ;
    }
    print_set(A,B);
    ft_printf("YO\n");
    sorter(A,B,num_arr);
    print_moves(A);
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
    if(isSorted(&A))
    {
        ft_printf("Sorted in 0 moves\n");
        return 1;
    }
    push_swap(&A,&B);
    return 1;
}