/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 02:29:50 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 02:29:58 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			push(struct s_stack **st, struct s_node *node)
{
	node->next = (*st)->stack;
	if ((*st)->stack == NULL)
		(*st)->stack = node;
	else
	{
		(*st)->stack->prev = node;
		(*st)->stack = node;
	}
}

struct	s_node	*pop(struct s_stack **st)
{
	struct s_node *tmp;

	tmp = (*st)->stack;
	(*st)->stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

int				is_empty(struct s_stack **stack)
{
	int ret;

	ret = 0;
	if ((*stack)->stack == NULL)
		ret = 1;
	else
		ret = 0;
	return (ret);
}

struct s_node	*find_node(struct s_stack **st, int val)
{
	struct s_node *tmp;

	tmp = (*st)->stack;
	while (tmp && tmp->value != val)
		tmp = tmp->next;
	return (tmp);
}

void			quicksort(int *number, int first, int last)
{
	int i;
	int j;
	int pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
				swap(&number[i], &number[j]);
		}
		swap(&number[pivot], &number[j]);
		quicksort(number, first, j - 1);
		quicksort(number, j + 1, last);
	}
}
