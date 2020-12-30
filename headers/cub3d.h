/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:28:33 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/30 17:11:55 by bgomez-r         ###   ########.fr       */
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
	char		**tab;// lo uso para trabajar con los identificadores la primera vez que lee la liena
	char		**tabcf;// lo uso para trabajar los identificadores y poder guardar los valroes para finalmente asigarlos a sus respectivas variables de la estructura
	int			flag_map_ready;
}								map_config;

typedef	struct	valid_map
{
	int			i;
	int			rows_size;// guarda el número de filas que contiene el plano del mapa
	char		*one_line_plan;// guarda la posicion de la linea que empieza a leer el mapa
	size_t	row_len;//	guarda la linea mas larga que ha leido del plano del mapa
	char		**plan;// guarda el plano del mapa
	int			values_ok;
}								map_plan;


int		file_validation(char *str);
void	init_identifiers(map_config *map);
int		file_reading(int fd, map_config *map, map_plan *plan);
int		save_plane_lines(char *str, map_plan *plan);
int		file_reading_map(int fd, map_config *map, map_plan *plan);
int		find_identifiers(char *str, map_config *map);
int		assignment_identifiers_text_colour(map_config *map);
void	assignment_identifiers_colours(map_config *map);
void	assignment_identifiers_resolution(map_config *map);
void	validation_identifiers_ceilling(map_config *map);
void	validation_identifiers_floor(map_config *map);
int		integer_validation(map_config *map);
void	print_error(char *str);
int		integer_validation_resolution(map_config *map);
int		integer_validation_size(map_config *map);
int		path_validation(char *str);
void	screen_validation_r(map_config *map);
void	texture_validation_no(map_config *map);
void	texture_validation_so(map_config *map);
void	texture_validation_ea(map_config *map);
void	texture_validation_we(map_config *map);
void	texture_validation_s(map_config *map);
int		color_validation_ceilling(map_config *map);
int		color_validation_floor(map_config *map);
int		validate_plan(char *str, map_plan *plan);
void	init_plan_values(map_plan *plan);
int		check_identifiers(map_config *map);
void	check_characters_plane(char *str, map_plan *plan);
void	check_allowed_values(char *str, map_plan *plan);
void	assigning_plane_values(map_plan *plan);

#endif
