/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:18:24 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 13:26:22 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Devuelve error en caso de que el usuario le pase mas argumentos que el que
**	se pide. Si todo esta correcto, abre el fichero con la funcion open pra po-
**	der leer el fichero que contiene todos los valores del mapa que tiene que
** interpretar
*/
int	main(int argc, char **argv)
{
	t_cub3d	*cub;
	int fd;

	cub = malloc(sizeof(t_cub3d));
	if (argc == 3 && (ft_strncmp(argv[2], "--save", -1) == 0))
		cub->bmp_flag = '1';
	init_structures(cub);
	if (argc > 2)
		print_error("Error. Debe introducir un único fichero con extensión '.map' \n");
	else if (argc == 2 && file_validation(argv[1]) == 1)
	{
		ft_printf("Mapa introducido --> %s \n\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		file_reading(fd, cub);
	}
	else if (argc < 2)
		print_error("Eres un estupido, no vales ni para meter un fichero");
	graphic(cub);
	ft_printf("\n \n 🚧 LEAKS 🚧 \n \n");
	system("leaks -fullContent cub3D");
	return (0);
}
