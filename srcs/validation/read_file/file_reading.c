/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 18:55:06 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/22 21:26:47 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*	Call-Function --> main
**	Read the .map file line by line to identify if it contains the values to be
**	collected
*/
int	file_reading_identifiers(int fd, map_config *map)
{
	char *line;
	int i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_printf("GNL has read this line 📖 --> %s \n", line);
		if (map->i < 8)
			find_identifier(line, map);
		if (map->i == 8)
			ft_printf("congrats, estas leyendo el plano \n");
		free(line);//puedo liberarlo al final del programa, asi podria pasarle la direccion de la ultima linea leida a file_reading_map y no tener que volver a leerlo todo desde el principio
		line = NULL;
		i++;
	}
	if (map->i < 8)
		print_error("Faltan identificadores, revise su mapa");
	map->flag_map_ready = 1;
	return (0);
}
