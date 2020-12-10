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

#include "../headers/cub3d.h"

int	read_map(int fd, map_config *map)
{
	char *line;
	int i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		//printf("%d", i);
		ft_printf("%s\n", line);
		find_identifier(line, map);
		free(line);
		line = NULL;
		i++;
	}
	ft_printf("\nResolucion %i \n", map->r);
	ft_printf("Resolucion %i \n", map->no);
	ft_printf("Resolucion %i \n", map->so);
	ft_printf("Resolucion %i \n", map->ea);
	ft_printf("Resolucion %i \n", map->we);
	ft_printf("Resolucion %i \n", map->s);
	ft_printf("Resolucion %i \n", map->f);
	ft_printf("Resolucion %i \n", map->c);
	
	return (0);
}
