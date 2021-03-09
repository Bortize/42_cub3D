/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:18:24 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 23:33:21 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Returns error in case the user passes more arguments than requested. If
** everything is correct, it opens the file with the open function in order
** to read the file containing all the map values it has to interpret.
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
		print_error("Error. You must enter a single file with extension '.cub' \n");
	else if (argc == 2 && file_validation(argv[1]) == 1)
	{
		ft_printf("Map introduced --> %s \n\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		file_reading(fd, cub);
	}
	else if (argc < 2)
		print_error("You're stupid, you're not even worth to put a file");
	graphic(cub);
	ft_printf("\n \n 🚧 LEAKS 🚧 \n \n");
	system("leaks -fullContent cub3D");
	return (0);
}
