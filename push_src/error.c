/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:29:37 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 03:29:40 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../checker.h"

int		check_no_let_error(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (ac < 1)
		return (1);
	while (av[i] != '\0')
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isalpha(av[i][j]))
				terminate_program();
			j++;
		}
		check_int(av[i]);
		i++;
	}
	return (1);
}

int		check_int(char *str)
{
	long long test;

	test = ft_atoi(str);
	if (test > 2147483647 || (long)test < -2147483648)
		terminate_program();
	return (1);
}

int		check_doubles(int *num_arr, int length)
{
	int i;
	int j;
	int tmp;
	int index;

	index = 0;
	i = 0;
	j = 0;
	tmp = 0;
	while (i < length)
	{
		tmp = num_arr[i];
		index = i;
		j = 0;
		while (j < length)
		{
			if (tmp == num_arr[j] && index != j)
				terminate_program();
			j++;
		}
		i++;
	}
	return (1);
}

char	*make_char_arr(void)
{
	char *arr;

	if (NULL == (arr = malloc(sizeof(char) * 5)))
		return (NULL);
	arr[0] = 'r';
	arr[1] = 'a';
	arr[2] = 'b';
	arr[3] = 'p';
	arr[4] = 's';
	arr[5] = '\0';
	return (arr);
}

void	check_formatting(char prev_char, char curr_char,
			char next_char)
{
	char	*characters;
	char	space;
	int		i;
	int		match;

	characters = make_char_arr();
	i = -1;
	space = '\n';
	match = 0;
	while (characters[++i])
		if (curr_char == characters[i]
			|| curr_char == space || curr_char == '\0')
			match = 1;
	i = -1;
	if (curr_char == space)
		while (characters[++i])
		{
			if (prev_char == characters[i])
				match = 1;
			if (next_char == characters[i] || next_char == '\0')
				match = 1;
		}
	if (match == 0)
	{
		free(characters);
		terminate_program();
	}
	free(characters);
}
