/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:18:24 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/13 21:31:37 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int argc, char **argv)
{
	map_config	map;

	int fd;
	init_identifier(&map);
	if (argc > 2)
		ft_printf("Error. Debe introducir un único fichero con extensión '.map' \n");
	else if (argc == 2 && file_validation(argv[1]) == 1)
	{
		ft_printf("Mapa introducido --> %s \n\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		read_map(fd, &map);
	}
	else if (argc < 2)
		ft_printf("Eres un estupido, no vales ni para meter un fichero \n");
		return (-1);
	system("leaks cub3D");
	return (0);
}
