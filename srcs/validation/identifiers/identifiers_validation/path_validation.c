/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:33:13 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/14 03:27:57 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		path_validation(char *str)
{
	char	*extension;
	int		str_len;
	int		extension_len;
	int		i;

	extension = ".xpm";
	str_len = ft_strlen(str);
	extension_len = ft_strlen(extension);
	i = 1;
	while (i < 5)
	{
		if (str[str_len - i] == extension[extension_len - i])
			i++;
		else
			print_error("The extension of the file entered is not correct \n");
	}
}
