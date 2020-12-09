/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:15:46 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/08 12:59:05 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	read_map(int fd)
{
	char *line;
	int i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		//printf("%d", i);
		ft_printf("%s\n", line);
		free(line);
		line = NULL;
		i++;
	}
	return (0);
}
