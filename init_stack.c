/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafajula <jafajula@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:44:49 by jafajula          #+#    #+#             */
/*   Updated: 2026/02/05 20:54:23 by jafajula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	int		i;
	int		n;
	long	nb;

	i = 0;
	n = 1;
	nb = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		n *= -1;
		i++;
	}
	while ((str[i]) && (str[i] >= '0') && (str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * n);
}

void	init_stack(t_stack_node **a, char **argv, bool argc_2)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_error(a, argv, argc_2);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a, argv, argc_2);
		if (error_duplicate(*a, (int)n))
			free_error(a, argv, argc_2);
		append_node(a, (int)n);
		i++;
	}
	if (argc_2)
		free(argv);
}
