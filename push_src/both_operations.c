/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:04:30 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 03:04:39 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(struct s_stack **a, struct s_stack **b)
{
	sa(a);
	sb(a, b);
	add_command(a, "ss");
}

void	rr(struct s_stack **a, struct s_stack **b)
{
	ra(a);
	rb(a, b);
	add_command(a, "rr");
}

void	rrr(struct s_stack **a, struct s_stack **b)
{
	rra(a);
	rrb(a, b);
	add_command(a, "rrr");
}
