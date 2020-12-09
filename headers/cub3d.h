/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortize <bortize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:28:33 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/09 22:45:26 by bortize          ###   ########.fr       */
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
	int			*f;
	int			*c;
}				map_config;

int		file_validation(char *str);
void	init_identifier(map_config *map);
int 	read_map(int fd, map_config *map);
int		find_identifier(char *str, map_config *map);
int		check_identifier(char c, map_config	*map);

#endif
