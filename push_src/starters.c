#include "../push_swap.h"

//Splits initial lower-than-pivot-values to stack B. This sort, and particular
//sorting algorithm, is based on quicksort, and the partition function of quicksort, respectively
struct  s_node  *splitter(struct s_stack **A, struct s_stack **B)
{
    struct s_node *pivot_node;
    struct s_node *tmp;

    tmp = (*A)->stack;
    while(tmp->next)
        tmp = tmp->next;
    pivot_node = tmp;
    tmp = (*A)->stack;
    while((*A)->stack->value != pivot_node->value)
    {
        if((*A)->stack->value < pivot_node->value)
            PB(A,B);
        else
            RA(A);
    }
    return pivot_node;
}

//Sets next value available to sort, and checks to see if any of the values at the 
//top of stackA, or top/bottom of stcak B match
void    setter(struct s_stack **A,struct s_stack **B,int *num_arr,int *index)
{
    while((*A)->stack != (*A)->pivot)
    {
        if((*A)->stack->value == *index || (*A)->stack->next->value == *index)
            (*index) = checkA_Stack(A,num_arr,index);
        else if((*B)->stack->value == *index || (*B)->tail->value == *index)
            checkB_Stack(A,B,index);
        else
            PB(A,B);
    }
}

//Seeks all 0(1) opportunities of for next value in line to be sorted to bottom of stack A
void    seeker(struct s_stack **A,struct s_stack **B,int *num_arr,int *index)
{
    if((*B)->stack != NULL)
        (*B)->tail = setB_Tail(B);
    while(checkA_Match(A,index) || checkB_Match(B,index))
    {
        if((*A)->stack->value == *index || ((*A)->stack->next && (*A)->stack->next->value == *index))
            (*index) = checkA_Stack(A,num_arr,index);
        else if(((*B)->stack != NULL)&&((*B)->stack->value == *index || (*B)->tail->value == *index))
            checkB_Stack(A,B,index);
        if((isSorted(A)) == 1 && (*B)->stack == NULL)
            return;
    }
}

//Strips values higher than the pivot from stack A, moves pivot to the bottom of stack A,
//then sorts B and appends to bottom of stack A in order
void    stripper(struct s_stack **A,struct s_stack **B,int *num_arr)
{
    int i;
    
    i = checkNext(num_arr,A);
    if((*A)->pivot->value != (*A)->tail->value)
    {
        RA(A);
        (*A)->tail = (*A)->tail->next;
    }
    while((*A)->stack->value != (*A)->end)
        PB(A,B);
    (*B)->tail = setB_Tail(B);
    (*B)->pivot = (*B)->tail;
    while((isEmpty(B) == 0) || (*A)->stack->value != (*A)->end)
    {
        if((*A)->stack->value != (*A)->end && (*B)->stack == NULL)
            setter(A,B,num_arr,&i);
        else
            seeker(A,B,num_arr,&i);
        if((*B)->stack != NULL && (*B)->stack == (*B)->pivot)
        {
            PA(B,A);
            (*B)->pivot = (*B)->tail;
            continue;
        }
        if((*B)->stack == NULL)
            return ;
        if((*B)->stack->value > (*B)->pivot->value)
            PA(B,A);
        else
        {
            (*B)->tail = (*B)->tail->prev;
            RRB(A,B);   
        }
        
    }
}

//Function begins initial sort of stack B. The sorting is done in 3 main functions.
//We first split lower values from A and move them to B.
//Then we empty/sort values from B to A. Once all values lower than the pivot are sorted,
//we strip A of those high values, and push them to B, to start the sort process all over again.
//That will be the last step.A sort is always gauaranteed after the last sorting step.
void    sorter(struct s_stack **A, struct s_stack **B,int *num_arr)
{
    int i;
    (*B)->tail = setB_Tail(B);
    (*B)->pivot = (*B)->tail;
    i = checkNext(num_arr,A);
    while((*B)->stack != NULL || (*A)->stack != (*A)->pivot || !isSorted(A))
    {
        if((*A)->stack != (*A)->pivot && (*B)->stack == NULL)
            setter(A,B,num_arr,&i);
        else
            seeker(A,B,num_arr,&i);
        if(isSorted(A) && (isEmpty(B) == 1) )
            return ;
        if((*B)->stack != NULL && (*B)->stack == (*B)->pivot)
        {
            PA(B,A);
            (*B)->pivot = (*B)->tail;
            continue;
        }
        if((*B)->stack != NULL && (*B)->stack->value > (*B)->pivot->value)
            PA(B,A);
        else
        {
            if((*B)->stack == NULL)
                break ;
            else
            {
                (*B)->tail = (*B)->tail->prev;
                RB(A,B);
            }   
        }
    }
    if((*A)->stack->value != (*A)->end)
        stripper(A,B,num_arr);
}