/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:54:53 by bgomez-r          #+#    #+#             */
/*   Updated: 2019/11/20 18:57:36 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst1;
	const char	*src1;

	if (len == 0 || dst == src)
		return (dst);
	dst1 = dst;
	src1 = src;
	i = 0;
	if (src > dst)
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	else
		while (len > 0)
		{
			len--;
			dst1[len] = src1[len];
		}
	return (dst1);
}
