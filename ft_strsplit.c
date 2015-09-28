/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:00:42 by elivet            #+#    #+#             */
/*   Updated: 2014/05/17 16:51:34 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_p.h"

static int			ft_countwords(char const *s, char c)
{
	int		i;
	int		w;

	w = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			w++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (w);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	if ((str = (char **)malloc(sizeof(char*) * (ft_countwords(s, c) + 1)))\
			== NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > j)
		{
			str[l] = ft_strsub(s, j, i - j);
			l++;
		}
	}
	str[l] = '\0';
	return (str);
}
