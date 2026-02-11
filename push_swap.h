/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafajula <jafajula@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:46:50 by jafajula          #+#    #+#             */
/*   Updated: 2026/02/11 20:54:08 by jafajula         ###   ########.fr       */
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
//ft_split
char			**ft_split(char const *s, char c);
static int		wcount(char const *s, char c);
static char		*wfill(char const *m, int s, int l);
static void		ft_free(char **s, int n);
static void		body(char const *s, char c, char **res);
//init_stack
static long		ft_atol(const char *str);
void			init_stack(t_stack_node **a, char **argv, bool argc_2);
//init_utils
t_stack_node	*locale_last_node(t_stack_node *head);
void			append_node(t_stack_node **stack, int n);
t_stack_node	*locale_smallest(t_stack_node *stack);
t_stack_node	*cheapest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

//push_sawp
int				main(int argc, char **argv);
//push
static void		push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
//reverse_rotate
static void		reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
//rotate
static void		rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
//set_stack
static void		swap(t_stack_node **head);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
//sort_stack

//sort_three

//swap

//utils
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);

#endif