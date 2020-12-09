/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 02:00:55 by borjagrd          #+#    #+#             */
/*   Updated: 2019/12/18 14:04:14 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	s1_cpy = (char *)malloc(sizeof(char) * (len_s1 + 1));
	if (s1_cpy == 0)
		return (NULL);
	return (ft_strcpy(s1_cpy, s1));
}
