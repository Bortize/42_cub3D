/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:33:13 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/19 11:52:26 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	path_validation(char *str)
{
	char *extension;
	int str_len;
	int extension_len;
	int i;

	extension = ".xpm";
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
			ft_printf("PATH file extension ❌  \n");
			return (-1);
		}
	}
	ft_printf("PATH file extension ✅ \n");
	return (1);
}
