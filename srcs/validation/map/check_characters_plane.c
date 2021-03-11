/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters_plane.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:46:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 21:36:11 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** It goes through each index of the string to check if its value is one
** of those allowed by the subject (we want to detect if the map contains any
** identifier not allowed and checking if the position of the player is one of
** them. In the case that some char of the string is not valid, it handles the
** error.
*/

void	check_values_allowed(char *str, t_cub3d *cub)
{
	cub->plan.i = 0;
	while (str[cub->plan.i] != '\0')
	{
		if ((str[cub->plan.i] == '0') || (str[cub->plan.i] == '1') ||
		(str[cub->plan.i] == '2') || (str[cub->plan.i] == 'N') ||
		(str[cub->plan.i] == 'S') || (str[cub->plan.i] == 'E') ||
		(str[cub->plan.i] == 'W') || (str[cub->plan.i] == ' ') ||
		(str[cub->plan.i] == '\t'))
		{
			if (str[cub->plan.i] == '2')
				cub->map.count_sprites++;
			player_start_position(str, cub);
			cub->plan.i++;
		}
		else
		{
			print_error("El plano del mapa contiene valores no permitidos \n");
		}
	}
}

/*
** Look to see if there is at least one valid value in the list that is passed
** to you to analyze it in depth. If it contains one, it enters more in depth
** and after checking it, if all the characters passed in the string are
** correct, it adds +1 row. If not, it handles the error.
*/

void	check_characters_plane(char *str, t_cub3d *cub)
{
	if (ft_strchr(str, '0') || ft_strchr(str, '1') || ft_strchr(str, '2') ||
		ft_strchr(str, 'N') || ft_strchr(str, 'S') || ft_strchr(str, 'E') ||
		ft_strchr(str, 'W') || ft_strchr(str, ' ') || ft_strchr(str, '\t'))
	{
		check_values_allowed(str, cub);
		cub->plan.rows_size++;
	}
	else
	{
		print_error("El plano contiene valores NO VALIDOS \n");
	}
}
