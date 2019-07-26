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

int		find_side(struct s_stack **a, int value)
{
	int				side;
	struct s_node	*tmp;

	tmp = (*a)->stack;
	side = 0;
	while (tmp->value != value)
	{
		side++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		side--;
		tmp = tmp->next;
	}
	side = (side >= 0 ? 1 : 0);
	return (side);
}

void	side1(struct s_stack **a, struct s_stack **b,
			struct s_node *spot, int incoming)
{
	if ((*b)->stack->next != NULL)
		set_pos(a, b, spot, incoming);
	else
		return ;
}

void	analyze(struct s_stack **a, struct s_stack **b,
			int incoming, struct s_node *spot)
{
	struct s_node *tmp;

	tmp = (*b)->stack;
	to_end(&tmp);
	while ((*b)->stack->value < incoming &&
			(*b)->stack->next->value > (*b)->stack->value)
		to_spot3(a, b, &tmp, 1);
	while ((*b)->stack->value != spot->value)
		to_spot3(a, b, &tmp, 1);
	return ;
}

void	side0(struct s_stack **a, struct s_stack **b,
			struct s_node *spot, int incoming)
{
	struct s_node *tmp;

	tmp = (*b)->stack;
	to_end(&tmp);
	if ((*b)->stack->next != NULL)
	{
		if (incoming < (*b)->stack->value && incoming < tmp->value)
		{
			while (spot->value != (*b)->stack->value)
				to_spot3(a, b, &tmp, 1);
		}
		else if (incoming < (*b)->stack->value && incoming > tmp->value)
		{
			while (incoming > tmp->value)
				to_spot3(a, b, &tmp, 0);
		}
		else if (incoming > (*b)->stack->value && incoming > tmp->value)
			analyze(a, b, incoming, spot);
		else if (incoming > (*b)->stack->value && incoming < tmp->value)
			return ;
	}
	else
		return ;
}

void	prep_b(struct s_stack **a, struct s_stack **b, int incoming)
{
	int				side;
	struct s_node	*spot;

	spot = (*b)->stack;
	side = 0;
	(*b)->max_a = find_big(b);
	if ((*b)->stack != NULL)
	{
		spot = find_spot(b, incoming);
		side = find_side(b, spot->value);
		if (side == 1)
			side1(a, b, spot, incoming);
		else
			side0(a, b, spot, incoming);
	}
}
