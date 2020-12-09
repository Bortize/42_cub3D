/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 01:39:00 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/22 09:15:06 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str1;
	size_t	str2;

	if (s1 == 0 || s2 == 0)
		return (0);
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (str1 + str2 + 1));
	if (str == 0)
		return (0);
	ft_strcpy(str, s1);
	ft_strlcat(str, s2, (str1 + str2 + 1));
	return (str);
}
