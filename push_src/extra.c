/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 02:26:06 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 02:26:14 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../checker.h"

void	set_datum(struct s_stack **a, int *num_arr, int size)
{
	struct s_node	*node;
	int				i;
	int				big;

	i = 0;
	node = NULL;
	big = 0;
	while (i < size)
	{
		(*a)->max_a = check_max(num_arr[i], &big);
		i++;
	}
	i--;
	while (i >= 0)
	{
		to_stack(num_arr[i], a);
		i--;
	}
}

int		get_next_value(struct s_stack **a, int big)
{
	struct s_node	*tmp;
	int				i;
	int				next;

	i = 0;
	tmp = (*a)->stack;
	next = tmp->value;
	while (tmp->next)
	{
		if (next < tmp->next->value && next < big)
			next = tmp->next->value;
		tmp = tmp->next;
	}
	return (next);
}

int		find_big(struct s_stack **b)
{
	int				big;
	struct s_node	*tmp;

	tmp = (*b)->stack;
	big = 0;
	if ((*b)->stack != NULL)
	{
		big = (*b)->stack->value;
		if (tmp->next == NULL)
			return (big);
		while (tmp)
		{
			if (tmp->value > big)
				big = tmp->value;
			tmp = tmp->next;
		}
	}
	return (big);
}

void	to_end(struct s_node **tmp)
{
	while ((*tmp)->next)
		*tmp = (*tmp)->next;
}
