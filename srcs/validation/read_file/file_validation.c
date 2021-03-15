/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:32:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/12 11:36:34 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Handles the error in case the file passed by the user via command line does
** not have extion ".cub"
*/

int	file_validation(char *str)
{
	char	*extension;
	int		str_len;
	int		extension_len;
	int		i;

	extension = ".cub";
	str_len = ft_strlen(str);
	extension_len = ft_strlen(extension);
	i = 1;
	while (i < 5)
	{
		if (str[str_len - i] == extension[extension_len - i])
			i++;
		else
			print_error("The extension of the loaded map is not valid. \n"
				"Enter a map with '.cub' extension \n");
	}
	return (1);
}
