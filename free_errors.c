/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafajula <jafajula@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:23:39 by jafajula          #+#    #+#             */
/*   Updated: 2026/01/22 20:27:44 by jafajula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i]);
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack(t_stack_node **stack)
{

}

void	free_error(t_stack_node **a, char **argv, bool argc_2)
{
	
}

