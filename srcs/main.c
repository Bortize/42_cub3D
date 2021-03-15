/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 00:50:35 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 00:51:02 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <errno.h>

/*
** Returns error in case the user passes more arguments than requested. If
** everything is correct, it opens the file with the open function in order
** to read the file containing all the map values it has to interpret.
*/

int	main(int argc, char **argv)
{
	t_cub3d	*cub;
	int		fd;

	if (argc < 2 || argc > 3)
		print_error("You're stupid, you're not even worth to put a file \n");
	if (!(cub = malloc(sizeof(t_cub3d))))
		print_error("The asignation to cub failed \n");
	init_structures(cub);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", -1) == 0))
		cub->bmp_flag = 1;
	if ((argc == 2 || argc == 3) && file_validation(argv[1]) == 1)
	{
		printf("Map introduced --> %s \n\n", argv[1]);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			print_error(strerror(errno));
		file_reading(fd, cub);
	}
	graphic(cub);
	if (OS == "macos")
	{
		printf("\n \n 🚧 LEAKS 🚧 \n \n");
		system("leaks -fullContent cub3D");
	}
	return (0);
}
