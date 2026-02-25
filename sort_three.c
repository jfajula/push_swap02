/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafajula <jafajula@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:17:22 by jafajula          #+#    #+#             */
/*   Updated: 2026/02/25 09:56:31 by jafajula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sort(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack_node	*locate_biggest(t_stack_node *stack)
{
	int				biggest;
	t_stack_node	*biggest_node;

	if (stack == NULL)
		return (NULL);
	biggest = INT_MIN;
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = locate_biggest(*a);
	if (*a == biggest)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, locate_smallest(*a), 'a');
		pb(b, a);
	}
}
