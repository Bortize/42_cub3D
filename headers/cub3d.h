/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:28:33 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/17 19:24:36 by bgomez-r         ###   ########.fr       */
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
	int			flag_widht;
	int			height;
	int			flag_height;
	char		*no;
	int			flag_no;
	char		*so;
	int			flag_so;
	char		*ea;
	int			flag_ea;
	char		*we;
	int			flag_we;
	char		*s;
	int			flag_s;
	int			floor[3];
	int			flag_floor;
	int			ceilling[3];// Igual meter el color por separado tambien como la rsolucion map->r, map->g, map->b (RGB)
	int			flag_ceilling;
	char		**tab;
	char		**tabcf;
}				map_config;

int		file_validation(char *str);
void	init_identifier(map_config *map);
int 	read_map(int fd, map_config *map);
int		find_identifier(char *str, map_config *map);
void	assignment_identifiers(map_config *map);
void	assignment_identifiers_colours(map_config *map);
void	assignment_identifiers_resolution(map_config *map);
void	validation_identifiers_ceilling(map_config *map);
void	validation_identifiers_floor(map_config *map);
int		integer_validation(map_config *map);
void	print_error(char *str);
int		integer_validation_resolution(map_config *map);
int		integer_validation_size(map_config *map);

#endif
