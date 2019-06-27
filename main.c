#include "libft/libft.h"
#include "libft/printf/ft_printf.h"
#include "push_swap.h"

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

struct s_stack *initStack()
{
    struct s_stack *stack = NULL;

    if(NULL == (stack = malloc(sizeof(struct s_stack))))
        return NULL;
    stack->capacity = 0;
    stack->max = 0;
    stack->min = 0;
    stack->stack = NULL;
    return stack;
}

int main(int ac, char **av)
{
    int length;
    int *num_list;
    struct s_stack *stackA;
    struct s_stack *stackB;

    length = ft_strlen(av[ac-1]);
    stackA = initStack();
    stackB = initStack();
    num_list = initList(av, length);
    
    return 1;
}