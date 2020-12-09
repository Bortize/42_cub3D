/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:14:06 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/01/03 19:05:16 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		d;
	size_t		s;
	size_t		dst_len;
	size_t		src_len;

	d = ft_strlen(dst);
	s = 0;
	dst_len = d;
	src_len = ft_strlen(src);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	while (src[s] && (d + 1) < dstsize)
	{
		dst[d++] = src[s++];
	}
	dst[d] = '\0';
	return (dst_len + src_len);
}
