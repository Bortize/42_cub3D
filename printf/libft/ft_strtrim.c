/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:46:41 by borjagrd          #+#    #+#             */
/*   Updated: 2019/12/18 13:43:44 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_no_char(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0' && set[i] != c)
		i++;
	if (!set[i])
		return (0);
	return (1);
}

static int	pos_first(char const *s, char const *set)
{
	int i;

	i = 0;
	while (s[i] && first_no_char(s[i], set))
		i++;
	return (i);
}

static int	pos_final(char const *s, char const *set)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && first_no_char(s[i], set))
		i--;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*aux;
	int		i;
	int		k;
	int		p;

	if (!s1 || !set)
		return (NULL);
	i = pos_first(s1, set);
	if ((int)ft_strlen(s1) == i)
		return (ft_strdup(""));
	k = pos_final(s1, set);
	p = ft_strlen(s1) - k - 1;
	aux = (char *)malloc(sizeof(char) * (ft_strlen(s1) - p - i + 1));
	if (!aux)
		return (NULL);
	p = 0;
	while (i <= k)
	{
		aux[p] = s1[i];
		i++;
		p++;
	}
	aux[p] = '\0';
	return (aux);
}
