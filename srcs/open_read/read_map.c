     /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortize <bortize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:15:46 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/09 23:03:54 by bortize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*	Call-Function --> main
**	Read the .map file line by line to identify if it contains the values to be
**	collected
*/
int	read_map(int fd, map_config *map)
{
	char *line;
	int i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		//printf("%d", i);
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
