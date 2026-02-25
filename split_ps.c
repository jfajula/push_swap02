/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafajula <jafajula@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:55:12 by jafajula          #+#    #+#             */
/*   Updated: 2026/02/25 13:55:54 by jafajula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cw(char *str, char space)
{
	int		c;
	bool	inside;

	c = 0;
	while (*str)
	{
		inside = false;
		while (*str == space && *str)
			str++;
		while (*str != space && *str)
		{
			if (!inside)
			{
				c++;
				inside = true;
			}
			str++;
		}
	}
	return (c);
}

static char	*next_word(char *str, char space)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == space)
		cursor++;
	while ((str[cursor + len] != space) && str[cursor + len])
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (next_str == NULL)
		return (NULL);
	while ((str[cursor] != space) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**split_ps(char *str, char space)
{
	int		word_count;
	char	**word_list;
	int		i;

	i = 0;
	word_count = cw(str, space);
	word_list = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (word_list == NULL)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			word_list[i] = malloc(sizeof(char));
			if (word_list == NULL)
				return (NULL);
			word_list[i++][0] = '\0';
			continue ;
		}
		word_list[i++] = next_word(str, space);
	}
	word_list[i] = NULL;
	return (word_list);
}
