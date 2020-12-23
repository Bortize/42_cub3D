/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:18:24 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/23 18:12:59 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

/*
**	Devuelve error en caso de que el usuario le pase mas argumentos que el que
**	se pide. Si todo esta correcto, abre el fichero con la funcion open pra po-
**	der leer el fichero que contiene todos los valores del mapa que tiene que
** interpretar
*/
int	main(int argc, char **argv)
{
	map_config	map;
	map_plan	plan;

	int fd;
	init_identifiers(&map);
	init_plan_values(&plan);
	if (argc > 2)
		ft_printf("Error. Debe introducir un único fichero con extensión '.map' \n");
	else if (argc == 2 && file_validation(argv[1]) == 1)
	{
		ft_printf("Mapa introducido --> %s \n\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		file_reading(fd, &map, &plan);
		//file_reading_map(fd, &map, &plan);
	}
	else if (argc < 2)
		print_error("Eres un estupido, no vales ni para meter un fichero");
	system("leaks -fullContent cub3D");
	return (0);
}
