/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafajula <jafajula@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:59:40 by jafajula          #+#    #+#             */
/*   Updated: 2026/01/22 20:07:18 by jafajula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	wcount(char const *s, char c);
static char	*wfill(char const *m, int s, int l);
static void	ft_free(char **s, int n);
static void	body(char const *s, char c, char **res);

char	**ft_split(char const *s, char c)
{
	char	**res;

	res = ft_calloc((wcount(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	body(s, c, res);
	return (res);
}

static int	wcount(char const *s, char c)
{
	int	j;
	int	n;

	j = 0;
	n = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			n++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (n);
}

static char	*wfill(char const *m, int s, int l)
{
	char	*w;
	int		i;

	i = 0;
	w = (char *)malloc((l - s + 1));
	if (!w)
		return (NULL);
	while (s < l)
	{
		w[i] = m[s];
		i++;
		s++;
	}
	w[i] = 0;
	return (w);
}

static void	ft_free(char **s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return ;
}

static void	body(char const *s, char c, char **res)
{
	size_t	i;
	int		j;
	int		sw;

	i = 0;
	j = 0;
	sw = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && sw < 0)
			sw = i;
		else if ((s[i] == c || i == ft_strlen(s)) && sw >= 0)
		{
			res[j] = wfill(s, sw, i);
			if (!res[j])
			{
				ft_free(res, j);
				return ;
			}
			sw = -1;
			j++;
		}
		i++;
	}
	return ;
}
