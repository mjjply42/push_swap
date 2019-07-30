/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:03:27 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 03:03:30 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

struct s_node	*init_node(int value)
{
	struct s_node *node;

	node = NULL;
	if (NULL == (node = malloc(sizeof(struct s_node))))
		return (NULL);
	node->value = value;
	node->sorted = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

struct s_stack	*init_stack(void)
{
	struct s_stack *stack;

	stack = NULL;
	if (NULL == (stack = malloc(sizeof(struct s_stack))))
		return (NULL);
	stack->capacity = 0;
	stack->max_a = 0;
	stack->end = 0;
	stack->pivot = NULL;
	stack->list = NULL;
	stack->stack = NULL;
	stack->tail = NULL;
	return (stack);
}

int				*init_array(char **list, int length)
{
	int i;
	int number;
	int *num_list;

	i = 1;
	number = 0;
	if (NULL == (num_list = malloc(sizeof(int) * (length + 1))))
		return (NULL);
	while (i <= length)
	{
		number = ft_atoi(list[i]);
		num_list[i - 1] = number;
		i++;
	}
	num_list[length] = '\0';
	return (num_list);
}

struct s_lis	*init_comm_node(char *str)
{
	struct s_lis *node;

	if (NULL == (node = malloc(sizeof(struct s_lis))))
		return (NULL);
	else
	{
		node->command = ft_strdup(str);
		node->next = NULL;
	}
	return (node);
}

void			init_list(struct s_lis **list, char *str)
{
	struct s_lis *tmp;
	struct s_lis *node;

	node = init_comm_node(str);
	if (*list == NULL)
	{
		*list = node;
		node->next = NULL;
	}
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}
