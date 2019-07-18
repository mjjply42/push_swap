#include "../push_swap.h"

/*Creates a node for the Stack, and returns it*/
struct s_node   *initNode(int value)
{
    struct s_node *node = NULL;

    if(NULL == (node = malloc(sizeof(struct s_node))))
        return NULL;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/*Creates a Stack struct, and returns it*/
struct s_stack *initStack()
{
    struct s_stack *stack = NULL;

    if(NULL == (stack = malloc(sizeof(struct s_stack))))
        return NULL;
    stack->capacity = 0;
    stack->max_a = 0;
    stack->end = 0;
    stack->pivot = NULL;
    stack->list = NULL;
    stack->stack = NULL;
    stack->tail = NULL;
    return stack;
}

/*Initializes a list of all the integers passed from ARGV(list). Returns the list*/
int  *initArray(char **list, int length)
{
    int i;
    int number;
    int *num_list;

    i = 1;
    number = 0;
    if(NULL == (num_list = malloc(sizeof(int) * length + 1)))
        return NULL;
    while(i <= length)
    {
        number = ft_atoi(list[i]);
        num_list[i - 1] = number;
        i++;
    }
    num_list[length] = '\0';
    return num_list; 
}

//Creates node for commands, to put into linked list of commands for algorithm
struct t_list   *initCommNode(char *str)
{
    struct t_list *node;

    if(NULL ==(node = malloc(sizeof(struct t_list))))
        return NULL;
    else
    {
        node->command = ft_strdup(str);
        node->next = NULL;
    }
    return node;
}

//Initializes the linked list of commands
void        initList(struct t_list **list, char *str)
{
    struct t_list *tmp;
    struct t_list *node;

    node = initCommNode(str);
    if(*list == NULL)
    {
        *list = node;
        node->next = NULL;
    }
    else
    {
        tmp = *list;
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    }
}