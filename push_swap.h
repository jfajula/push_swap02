/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafajula <jafajula@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:46:50 by jafajula          #+#    #+#             */
/*   Updated: 2026/02/05 20:56:23 by jafajula         ###   ########.fr       */
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
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//free_errors
void	free_argv(char **argv);
void	free_stack(t_stack_node **stack);
void	free_error(t_stack_node **a, char **argv, bool checker);
int		syntax_error(char *str_nbr);
int		error_duplicate(t_stack_node *a, int n);

#endif