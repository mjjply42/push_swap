#include "../push_swap.h"

//Finds the biggest number in the list of numbers sent to the console
int     checkMax(int content, int *big)
{
    if(content > *big)
        *big = content;       
    return *big;
}

void    swap(int *a, int *b)
{
    int tmp;

    tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//adds commands used to move stack elements, to the command list
void    add_command(struct s_stack **A,char *command)
{
    if(command == NULL)
        return ;
    initList(&(*A)->list, command);
}

//checks whether given stack is sorted
int     isSorted(struct s_stack **A)
{
    struct s_node *tmp;

    tmp = (*A)->stack;
    while(tmp->next)
    {
        if(tmp->value < tmp->next->value)
            tmp = tmp->next;
        else
            return 0;
    }
    return 1;
}

//Makes a count array of all values, based on index.
//There are no duplicate values, and negative values.
//To accomodate for non negative indexes in strings,
//for example, if there is a -56 and 56, the index 56, will have value 1.
//This gives the options of -1(only negative), 0(empty), 1(both negative and positve), and 2(only positve)
//for array index values.
void    set_count_array(struct s_stack **A,int *num_arr)
{
    struct s_node *tmp;
    int i;

    i = 0;
    tmp = NULL;
    while(i <= (*A)->max_a)
    {
        num_arr[i] = 0;
        i++;
    }
    tmp = (*A)->stack;
    while(tmp)
    {
        if(tmp->value >= 0)
            num_arr[tmp->value]+= 2;
        else
            num_arr[(tmp->value)*-1]--;
        tmp = tmp->next;
    }
}