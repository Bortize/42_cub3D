/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:55:06 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/08 20:50:34 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	Call-Function --> main
**	Read the .map file line by line to identify if it contains the values to be
**	collected
*/
int	file_reading(int fd, t_cub3d *cub)
{
	char *line;
	int i;
	i = 0;

	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
		{
//			ft_printf("\nGNL has read this line 📖 --> %s \n", line);
				if (cub->map.i < 8)
					find_identifiers(line, cub);
				if (cub->map.flag_map_ready == 1)
				{
					validate_plan(line, cub);
					save_plane_lines(line, cub);
				}
				free(line);// Necesito liberarlo cada vez para dejar la linea libre
				if (cub->map.i == 8)
					cub->map.flag_map_ready = 1;
		}
	}
	cub->zbuffer = malloc(sizeof(double) * cub->map.width);
	if (cub->map.i < 8)
		print_error("Faltan identificadores, revise su mapa");
	if (cub->plan.values_ok == 0)
		assigning_plane_values(cub);
//	while (i < cub->plan.rows_size)// pinta el plano una vez tratado por el algoritmo floodfill. BORRAR
//		ft_printf("🌎 %s \n", cub->plan.plan[i++]);// pinta el plano. BORRAR
	return (0);
}
