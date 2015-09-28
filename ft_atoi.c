/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:38:26 by elivet            #+#    #+#             */
/*   Updated: 2013/12/01 16:22:49 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_p.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		n;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str == NULL)
		return (0);
	while (ft_nospace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 44 - str[i++];
	while (ft_isdigit(str[i]) == 1)
	{
		nbr = nbr * 10;
		n = str[i] - '0';
		nbr = nbr + n;
		i++;
	}
	return (nbr * sign);
}
