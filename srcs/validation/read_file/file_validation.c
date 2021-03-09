/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:32:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 01:51:19 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"
#include <stdio.h>

/*	Call-Function --> main
**	Gestiona el error en caso de que el fichero que le pase el usuario por
**	linea de comandos no tenga extion ".cub"
*/
int	file_validation(char *str)
{
	char *extension;
	int str_len;
	int extension_len;
	int i;

	extension = ".cub";
	str_len = ft_strlen(str);
	extension_len = ft_strlen(extension);
	i = 1;
	while(i < 5)
	{
		if (str[str_len - i] == extension[extension_len - i])
			i++;
		else
			print_error("Map file extension ❌  \n");
	}
	return (1);
}
