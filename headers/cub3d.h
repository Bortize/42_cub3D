/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:28:33 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/14 14:36:55 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include "../printf/libft/libft.h"
# include "../printf/ft_printf.h"
# include "get_next_line.h"
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	config
{
	int			i;
	int			width;
	int			height;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*s;
	int			**floor;
	int			**ceilling;
	char		**tab;
	char		**tabcf;
	int			**ptrcf;
	//char		**R;
}				map_config;

int		file_validation(char *str);
void	init_identifier(map_config *map);
int 	read_map(int fd, map_config *map);
int		find_identifier(char *str, map_config *map);
void	assignment_identifiers(map_config *map);
void	assignment_identifiers_colours(map_config *map);
void	assignment_identifiers_resolution(map_config *map);
void	validation_identifiers(map_config *map);

#endif
