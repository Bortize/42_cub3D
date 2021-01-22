/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:10:22 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/22 00:59:15 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	keypress(int keycode, t_window *graphic)
{
	if (keycode == KEY_R)
	{
			ft_printf("hola amigo");
			ft_printf("%s \n", graphic->plan.plan);
	}
	return(0);
}
