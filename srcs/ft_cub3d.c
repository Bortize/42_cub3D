/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:39:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/08 12:47:11 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int argc, char **argv)
{
	int fd;
	char	*long_argv;
	if (argc == 2)
	{
		long_argv = argv[1];
		file_validation(argv[1]);
		ft_printf("Mapa introducido --> %s \n", long_argv);
		fd = open(argv[1], O_RDONLY);
		read_map(fd);
	}
	else
		ft_printf("Eres un estupido, no vales ni para meter un fichero \n");
		return (-1);
	return (0);
}
