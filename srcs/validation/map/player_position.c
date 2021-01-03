/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:15:50 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/03 23:46:35 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	player_position(char *str, map_plan *plan)
{
	if ((str[plan->i] == 'N') || (str[plan->i] == 'S') || (str[plan->i] == 'E')
		|| (str[plan->i] == 'W'))
	{
		plan->player_position_x = plan->rows_size + 1;
		plan->player_position_y = plan->i;
	}
}