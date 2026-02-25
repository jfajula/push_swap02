/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafajula <jafajula@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:46:50 by jafajula          #+#    #+#             */
/*   Updated: 2026/02/25 14:19:09 by jafajula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					cost;
	bool				above;
	bool				cheapest;	
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//free_errors
void			free_argv(char **argv);
void			free_stack(t_stack_node **stack);
void			free_error(t_stack_node **a, char **argv, bool checker);
int				syntax_error(char *str_nbr);
int				error_duplicate(t_stack_node *a, int n);
//init_stack
void			init_stack(t_stack_node **a, char **argv, bool argc_2);
//init_utils
t_stack_node	*locate_last_node(t_stack_node *head);
void			append_node(t_stack_node **stack, int n);
t_stack_node	*locate_smallest(t_stack_node *stack);
t_stack_node	*cheapest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
//push_swap
int				main(int argc, char **argv);
//push
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
//reverse_rotate
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
//rotate
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
//set_stack
void			set_current_position(t_stack_node *stack);
void			set_target_node(t_stack_node *a, t_stack_node *b);
void			set_cost(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
void			init_nodes(t_stack_node *a, t_stack_node *b);
//sort_stack
void			finish_rotation(t_stack_node **s,
					t_stack_node *top, char stack_name);
void			sort_stack(t_stack_node **a, t_stack_node **b);
//sort_three
bool			stack_sort(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_five(t_stack_node **a, t_stack_node **b);
//swap
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
//split_ps
char			**split_ps(char *str, char space);

#endif