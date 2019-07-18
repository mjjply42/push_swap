#include "push_swap.h"
#include "checker.h"

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
    while(tmp->next)
        tmp = tmp->next;
    (*A)->tail = tmp;
    (*A)->pivot = splitter(A,B);
    if(isSorted(A) && isEmpty(B))
    {
        print_moves(A);
        return ;
    }
    sorter(A,B,num_arr);
    print_moves(A);
}

int main(int ac, char **av)
{
    int length;
    int *num_list;
    struct s_stack *A;
    struct s_stack *B;

    length = ac-1;
    check_noLet_error(ac,av);
    A = initStack();
    B = initStack();
    num_list = initArray(av, length);
    check_doubles(num_list,length);
    set_datum(&A, num_list, length);
    if(isSorted(&A))
        return 1;
    push_swap(&A,&B);
    return 1;
}