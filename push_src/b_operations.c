/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:02:27 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 03:04:17 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		sb(struct s_stack **a, struct s_stack **b)
{
	struct s_stack	**b_b;
	struct s_node	*tmp;

	b_b = b;
	tmp = (*b)->stack;
	if ((*b_b)->capacity == 0 || (*b_b)->capacity == 1)
		return ;
	if ((*b_b)->capacity > 2)
	{
		tmp = (*b_b)->stack->next;
		tmp->next->prev = (*b_b)->stack;
		(*b_b)->stack->next = tmp->next;
		tmp->next = (*b_b)->stack;
		tmp->prev = NULL;
		(*b_b)->stack = tmp;
	}
	else
	{
		tmp = (*b_b)->stack->next;
		tmp->next = (*b_b)->stack;
		(*b_b)->stack->next = NULL;
		(*b_b)->stack = tmp;
	}
	add_command(a, "sb");
}

void		pb(struct s_stack **a, struct s_stack **b)
{
	struct s_node *node;

	node = NULL;
	if ((*a)->capacity == 0)
		return ;
	node = pop(a);
	(*a)->capacity--;
	push(b, node);
	(*b)->capacity++;
	add_command(a, "pb");
}

void		rb(struct s_stack **a, struct s_stack **b)
{
	struct s_node *tmp;
	struct s_node *curr;

	tmp = (*b)->stack;
	curr = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = curr;
	curr->prev = tmp;
	curr = curr->next;
	(*b)->stack->next = NULL;
	(*b)->stack = curr;
	add_command(a, "rb");
}

void		rrb(struct s_stack **a, struct s_stack **b)
{
	struct s_node *tmp;
	struct s_node *curr;
	
	if ((*b)->capacity == 0)
		return ;
	tmp = (*b)->stack;
	curr = tmp;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp->next)
	{
		curr = tmp;
		tmp = tmp->next;
	}
	curr->next = NULL;
	tmp->prev = NULL;
	tmp->next = (*b)->stack;
	(*b)->stack = tmp;
	add_command(a, "rrb");
}
