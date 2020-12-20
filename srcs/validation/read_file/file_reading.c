/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:55:06 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/20 20:16:04 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*	Call-Function --> main
**	Read the .map file line by line to identify if it contains the values to be
**	collected
*/
int	file_reading(int fd, map_config *map)
{
	char *line;
	int i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_printf("GNL has read this line 📖 --> %s \n", line);
		find_identifier(line, map);
		free(line);
		line = NULL;
		i++;
	}
	if (map->i < 8)
		print_error("Faltan identificadores, revise su mapa");
	return (0);
}