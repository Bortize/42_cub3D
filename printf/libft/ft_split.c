/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 13:11:17 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/22 17:51:32 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
** Cuenta las palabras de la cadena para saber de cuantas cadenas se va a
** componer nuestro nuevo array. Lo hacemos porque necesitamos saberlo para
** reservar memoria para la nueva tabla.
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
** Reserva memoria para copiar en un nuevo puntero los strings que ha ido
** encontrado la funcon split dentro del string principal. Este string ira
** dentro de una matriz que contendra todas las cadenas que devuelve la funcion
** ft_plit
*/

static char	*ft_wordcopy(const char *s, size_t n)
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
** Recorre la cadena que le es pasada por parametro hasta que encuentra el
** caracter 'c' el cual omite. En ese momento guarda el string que ha encontrado
** en una matriz y continua leyendo hasta que encuentre el siguiente caracter
** 'c' para de nuevo guardarlo en la matriz. La funcion devuelve un numero
** puntureo compuesto por todos los valores que ha encotrado en el string por
** separado.
*/

char	**ft_split(char const *s, char c)
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
			tab[k++] = ft_wordcopy(s + j, i - j);
		}
	}
	tab[k] = NULL;
	return (tab);
}

