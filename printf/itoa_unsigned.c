/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:26:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 01:24:51 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_size(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}

char		*itoa_unsigned(unsigned int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	index;
	unsigned int	size;

	nb = (unsigned int)n;
	size = (unsigned int)get_size(nb);
	index = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size))))
		return (NULL);
	index = size - 1;
	while (nb >= 10)
	{
		str[index--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[index] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
