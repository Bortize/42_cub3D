/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 13:11:17 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/12 20:33:45 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Count the words in the string to know how many strings our new array will be
** composed of. Our new array is going to be composed of. We do this because we
** need to know this to reserve memory for the new table.
*/

static int	ft_countword(char const *s, char c)
{
	unsigned int	i;
	int				words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (words);
}

/*
** Reserves memory to copy into a new pointer the strings found by the split
** funcon inside the main string. Found by the split function inside the main
** string. This string will go inside an array that will contain all the strings
** returned by the functionft_plit
*/

static char	*ft_wordcopy(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

/*
** It traverses the string that is passed as a parameter until it finds the
** character 'c' which it omits. At that point it saves the string it has found
** in an array and continues reading until it finds the next character 'c' and
** saves it again in the array. 'c' and saves it again in the array. The
** function returns a number number composed of all the values it has found in
** the string separately.
*/

char		**ft_split_map(char const *s, char c, int min_size)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k++] = ft_wordcopy(s + j, min_size);
		}
	}
	tab[k] = NULL;
	return (tab);
}
