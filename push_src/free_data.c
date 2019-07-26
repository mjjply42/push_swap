#include "../push_swap.h"

void		free_stack_struct(struct s_stack *st)
{
	struct s_lis *list_node;
	struct s_node *stack_node;

	stack_node = st->stack;
	list_node = st->list;
	while (st->list)
	{
		st->list = st->list->next;
		if (list_node->command)
			free(list_node->command);
		free(list_node);
		list_node = st->list;
	}
	while(st->stack)
	{
		st->stack = st->stack->next;
		free(stack_node);
		stack_node = st->stack;
	}
	free(st);
}

void		free_num_list(int *num_list)
{
	free(num_list);
}