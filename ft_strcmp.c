/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <elivet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:46:20 by elivet            #+#    #+#             */
/*   Updated: 2014/05/17 16:44:06 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index])
	{
		if (s1[index] == '\0')
			return (0);
		index++;
	}
	if (s1[index] < s2[index])
		return (-1);
	if (s2[index] < s1[index])
		return (1);
	return (0);
}
