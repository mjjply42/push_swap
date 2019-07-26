/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 01:45:39 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 01:45:44 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			to_stack(int value, struct s_stack **a)
{
	struct s_node *node;

	node = NULL;
	node = init_node(value);
	if ((*a)->stack == NULL)
	{
		(*a)->stack = node;
		node->next = NULL;
	}
	else
	{
		(*a)->stack->prev = node;
		node->next = (*a)->stack;
		(*a)->stack = node;
	}
	(*a)->capacity++;
}
