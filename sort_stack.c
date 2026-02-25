/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafajula <jafajula@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:43:35 by jafajula          #+#    #+#             */
/*   Updated: 2026/02/25 12:52:11 by jafajula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_ab(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_n)
{
	while (*a != cheapest_n->target_node && *b != cheapest_n)
		rr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

static void	rr_ab(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_n)
{
	while (*a != cheapest_n->target_node && *b != cheapest_n)
		rrr(a, b);
	set_current_position(*a);
	set_current_position(*b);	
}

void	finish_rotation(t_stack_node **s, t_stack_node *top, char stack_name)
{
	while (*s != top)
	{
		if (stack_name == 'a')
		{
			if (top->above)
				ra(s);
			else
				rra(s);
		}
		else if (stack_name == 'b')
		{
			if (top->above)
				rb(s);
			else
				rrb(s);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = cheapest(*b);
	if (cheapest_node->above && cheapest_node->target_node->above)
		r_ab(a, b, cheapest_node);
	else if (!(cheapest_node->above) && !(cheapest_node->target_node->above))
		rr_ab(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = locate_smallest(*a);
	if (smallest->above)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
