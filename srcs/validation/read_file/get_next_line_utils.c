/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:09:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 19:24:23 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Calculates the number of characters in the string pointed to by *str.
** Returns the number of characters it contains excluding the null character
** that is not included.
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
** Locates the first occurrence of c (converted to unsigned char) in the string
** pointed to by s (including the null character). RETURN: The function returns
** a pointer from the character found. If the character, c, was not found, then
** it returns a NULL pointer.
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
** Searches for a substring contained within a string. For example, if in a
** variable S we have the string "abcdef", the following function will get the
** string "cde": s1=substr(s,2,3) The parameters are usually the following: The
** first parameter the source string, the second parameter the starting
** position (which usually starts counting from 0, not 1) and the third
** parameter the size.
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
			while (i < len && s[start + i] != '\0')
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
** This function allocates memory and returns a new string terminated by a '0'
** which is the result of what the concatenation of the parameters s1 and s2
** would occupy in bytes. If the assignment fails it returns NULL
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
