/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:55:06 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/22 13:49:39 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*	Call-Function --> main
**	Read the .map file line by line to identify if it contains the values to be
**	collected
*/
int	file_reading(int fd, map_config *map, map_plan *plan)
{
	char *line;
	int i;
	i = 0;

	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
		{
			ft_printf("\nGNL has read this line 📖 --> %s \n", line);
				if (map->i < 8)
					find_identifiers(line, map);
				if (map->flag_map_ready == 1)
				{
					validate_plan(line, plan);
					save_plane_lines(line, plan);
				}
				free(line);// Necesito liberarlo cada vez para dejar la linea libre
				if (map->i == 8)
					map->flag_map_ready = 1;
		}
	}
	if (map->i < 8)
		print_error("Faltan identificadores, revise su mapa");
	if (plan->values_ok == 0)
		assigning_plane_values(plan);
	while (i < plan->rows_size)// pinta el plano una vez tratado por el algoritmo floodfill. BORRAR
		ft_printf("🪐 %s \n", plan->plan[i++]);// pinta el plano. BORRAR
	return (0);
}
