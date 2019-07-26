/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:15:19 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 03:15:22 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_max(int content, int *big)
{
	if (content > *big)
		*big = content;
	return (*big);
}

void	swap(int *a, int *b)
{
	int tmp;

	tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	add_command(struct s_stack **a, char *command)
{
	if (command == NULL)
		return ;
	init_list(&(*a)->list, command);
}

int		is_sorted(struct s_stack **a)
{
	struct s_node *tmp;

	tmp = (*a)->stack;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	set_count_array(struct s_stack **a, int *num_arr)
{
	struct s_node	*tmp;
	int				i;

	i = 0;
	tmp = NULL;
	while (i <= (*a)->max_a)
	{
		num_arr[i] = 0;
		i++;
	}
	tmp = (*a)->stack;
	while (tmp)
	{
		if (tmp->value >= 0)
			num_arr[tmp->value] += 2;
		else
			num_arr[(tmp->value) * -1]--;
		tmp = tmp->next;
	}
}
