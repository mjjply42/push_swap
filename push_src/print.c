/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:28:00 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 03:28:05 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	terminate_program(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

void	print_stack(struct s_stack **stack)
{
	struct s_node *tmp;

	tmp = (*stack)->stack;
	while (tmp)
	{
		ft_printf("%i    ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	print_set(struct s_stack **a, struct s_stack **b)
{
	ft_printf("A|   ");
	print_stack(a);
	ft_printf("\n");
	ft_printf("B|   ");
	print_stack(b);
	ft_printf("\n");
	ft_printf("\n");
}

void	print_moves(struct s_stack **a)
{
	struct s_lis	*tmp;
	int				count;

	count = 0;
	tmp = (*a)->list;
	while (tmp)
	{
		count++;
		ft_printf("%s\n", tmp->command);
		tmp = tmp->next;
	}
}
