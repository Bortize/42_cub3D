/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:32:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/08 10:50:24 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <stdio.h>

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
		{
			ft_printf("El char %c coincide\n", str[str_len - i]);
			i++;
		}
		else
		{
			ft_printf("Map file extension ❌  \n");
			return (-1);
		}
	}
	ft_printf("Map file extension ✅ \n");
	return (1);
}
