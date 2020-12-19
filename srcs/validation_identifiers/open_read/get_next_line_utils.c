/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:14:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/19 19:28:13 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/get_next_line.h"

/*
** Calcula el número de caracteres que tiene la cadena apuntada por *str.
** Retorna el número de caracteres que contiene sin contar el carácter nulo que
** no se incluye.
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
** Localiza la primera aparición de c (convertido a unsigned char) en la cadena
** apuntada por s (incluyendo el carácter nulo).
** RETORNO:
** La función retorna un puntero a partir del carácter encontrado. Si no se ha
** encontrado el carácter, c, entonces retorna un puntero NULL.
*/
char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

/*
** Busca una subcadena contenida dentro de una cadena. Por ejemplo, si en una
** variable S tenemos la cadena de caracteres "abcdef", la siguiente función
** obtendrá la cadena "cde": s1=substr(s,2,3)
** Los parámetros suelen ser los siguientes: El primero parámetro la cadena de
** origen, el segundo parámetro la posición inicial (que suele comenzar a
** contarse desde el 0, no desde el 1) y el tercer parámetro el tamaño.
*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char) * (len + 1));
	if (new)
	{
		i = 0;
		if (ft_strlen(s) > start)
			while (i < len)
			{
				new[i] = s[start + i];
				i++;
			}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}

/*
** Esta función reserva memoria y devuelve una nueva cadena terminada por un '\0'
** que es el resultado de lo que ocuparia en bytes la concatenación de los
** parámetros s1 y s2. Si la asignación falla devuelve NULL
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size_s1;
	unsigned int	size_s2;
	unsigned int	i;
	unsigned int	j;
	char			*new;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (new)
	{
		i = -1;
		while (++i < size_s1)
			new[i] = s1[i];
		j = 0;
		while (j < size_s2)
			new[i++] = s2[j++];
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
