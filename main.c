#include "push_swap.h"

void    begin_prog(struct s_stack *A, struct s_stack *B, int *num_arr, int size)
{
    struct s_node *linked;
    struct s_node *node;
    int i;

    i = 0;
    node = NULL;
    linked = NULL;
    while(i < size)
    {
        node = initNode(num_arr[i]);
        linked = initList(node);
        i++;
    }
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
    begin_prog(stackA, stackB, num_list, length);
    return 1;
}