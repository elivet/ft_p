/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:45:46 by elivet            #+#    #+#             */
/*   Updated: 2013/12/01 19:08:20 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_p.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	ft_strclr(str);
	return (str);
}
