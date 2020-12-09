/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortize <bortize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:03:01 by bortize           #+#    #+#             */
/*   Updated: 2020/12/09 23:04:11 by bortize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		check_identifier(char c, map_config	*map)
{
    if (c == 'R')
        map->width = 1;
    else if (c == 'S')
        map->s = 1;
    else if (c == 'C')
        map->c = 1;
    else if (c == 'F')
        map->f = 1;
    return (0);
}