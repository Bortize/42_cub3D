/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:03:24 by bortize           #+#    #+#             */
/*   Updated: 2020/12/19 11:16:22 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Devuelve el contador de los caracteres o strings que ha ido encontrando por
** el camino. Cuenta como string todos aquellos caracteres que estan separados
** por c y t
*/

static int			ft_countword(char const *s, char c, char t)
{
	unsigned int	i;
	int				words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c || s[i] == t)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] && (s[i] != c && s[i] != t))
			i++;
	}
	return (words);
}

/*
** Asigna a una matriz, los caractres o strings que ha encontrando en la linea.
*/

static char			*ft_wordcopy(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

/*
** Devuelve un array de strings de la linea que le pasa get_next_line.
** Este array que devuelve esta compuesto por los strins que aparecen
** en la cadena omitiendo los caracteres c y t
*/

char				**ft_split_plus(char const *s, char c, char t)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_countword(s, c, t)) + 1)))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c || s[i] == t)
			i++;
		j = i;
		while (s[i] && (s[i] != c && s[i] != t))
			i++;
		if (i > j)
		{
			tab[k++] = ft_wordcopy(s + j, i - j);
		}
	}
	tab[k] = NULL;
	return (tab);
}
