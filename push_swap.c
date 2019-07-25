#include "push_swap.h"
#include "checker.h"

void    final(struct s_stack **A,struct s_stack **B)
{
    struct s_node *tmp;

    tmp = (*A)->stack;
    toEnd(&tmp);
    while(!isEmpty(B))
    {
        if((*A)->stack->value < (*B)->stack->value)
        {
            RA(A);
            tmp = tmp->next;
        }
        else if((*B)->stack->value < tmp->value && tmp->value != (*A)->max_a)
        { 
            tmp = tmp->prev;
            RRA(A);
        }
        if(isSorted(A) && !isSorted(B))
            while((*B)->stack->value != findBig(B))
                RRB(A,B);
        PA(B,A);
        (*A)->stack->sorted = 1;
    }
}

//Sets the low value, or supposed beginning element of the stack.
//Once this values is at the top, it signifies that the current sort, is the last sort
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

void    other_end(struct s_stack **A,struct s_stack **B,int next_up)
{
    if((*A)->stack->value != (*A)->max_a)
    {
        if((*A)->stack->value == next_up && (*A)->stack->next->value == (*A)->max_a)
        {
            RA(A);
            (*A)->tail = (*A)->tail->next;
        }
        else if((*A)->stack->value == next_up && (*A)->stack->sorted == 0)
            SA(A);
        else
        {
            prepB(A,B,(*A)->stack->value);
            PB(A,B);   
        }
    }
    else
    {
        RA(A);
        (*A)->tail = (*A)->tail->next;
    }
}

void    highEnd(struct s_stack **A,struct s_stack **B,int side)
{
    int next_up;
    next_up = getNextValue(A,(*A)->max_a);
    while((*A)->tail->value != (*A)->max_a)
    {
        if(side == 1)
        {
            (*A)->tail = (*A)->tail->prev;
            RRA(A);
        }
        else
            other_end(A,B,next_up);
    }
}

//Starts Push_Swap algorithm
void    push_swap(struct s_stack **A, struct s_stack **B)
{
    int num_arr[(*A)->max_a];
    int side;
    struct s_node *tmp;

    tmp = (*A)->stack;
    set_count_array(A,num_arr);
    setCue(A,num_arr);
    toEnd(&tmp);
    (*A)->tail = tmp;
    side = findSide(A,(*A)->max_a);
    highEnd(A,B,side);
    set_sort_status(A);
    align_to_front(A,B);
    final(A,B);
    print_moves(A);
}

//Main function to grab console input,turn it into an array of values, push those values to a stack,
//as well as start the Push_Swap algorithm to sort the stack contents
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
    if(isSorted(&A) == 1)
        return 1;
    push_swap(&A,&B);
    return 1;
}