/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 04:38:44 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 04:38:47 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa2(struct s_stack **a_a, struct s_node **tmp)
{
	*tmp = (*a_a)->stack->next;
	(*tmp)->next = (*a_a)->stack;
	(*a_a)->stack->next = NULL;
	(*a_a)->stack = *tmp;
}

void	sa(struct s_stack **a)
{
	struct s_stack	**a_a;
	struct s_node	*tmp;

	a_a = a;
	tmp = (*a_a)->stack;
	if ((*a_a)->capacity == 0 || (*a_a)->capacity == 1)
		return ;
	else
	{
		if ((*a_a)->capacity > 2)
		{
			tmp = (*a_a)->stack->next;
			tmp->next->prev = (*a_a)->stack;
			(*a_a)->stack->next = tmp->next;
			tmp->next = (*a_a)->stack;
			tmp->prev = NULL;
			(*a_a)->stack = tmp;
		}
		else
			sa2(a_a, &tmp);
	}
	add_command(a, "sa");
}

void	pa(struct s_stack **b, struct s_stack **a)
{
	struct s_node *node;

	node = NULL;
	if ((*a)->capacity == 0 || (*b)->capacity == 0)
		return ;
	node = pop(b);
	(*b)->capacity--;
	push(a, node);
	(*a)->capacity++;
	add_command(a, "pa");
}

void	ra(struct s_stack **a)
{
	struct s_node *tmp;
	struct s_node *curr;

	tmp = (*a)->stack;
	curr = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = curr;
	curr->prev = tmp;
	curr = curr->next;
	(*a)->stack->next = NULL;
	(*a)->stack = curr;
	add_command(a, "ra");
}

void		rra(struct s_stack **a)
{
	struct s_node *tmp;
	struct s_node *curr;
	if ((*a)->capacity == 0)
		return ;
	tmp = (*a)->stack;
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
	tmp->next = (*a)->stack;
	(*a)->stack = tmp;
	add_command(a, "rra");
}
