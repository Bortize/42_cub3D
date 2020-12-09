/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:18:24 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/08 12:54:23 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int argc, char **argv)
{
	map_config	map;

	int fd;
	char	*long_argv;
	initialize_params(&map);
	if (argc > 2)
		ft_printf("Error. Introduzca solo un fichero .map \n");
	else if (argc == 2 && file_validation(argv[1]) == 1)
	{
		long_argv = argv[1];
		ft_printf("Mapa introducido --> %s \n", long_argv);
		fd = open(argv[1], O_RDONLY);
		read_map(fd);
	}
	else if (argc < 2)
		ft_printf("Eres un estupido, no vales ni para meter un fichero \n");
		return (-1);
	return (0);
}
