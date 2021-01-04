/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:15:50 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/04 13:53:53 by bgomez-r         ###   ########.fr       */
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
		ft_printf("se encontro al jugador en la posición %d %d \n", plan->player_position_x, plan->player_position_y);
	}
}