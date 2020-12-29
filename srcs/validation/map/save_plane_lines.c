/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:58:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/29 21:04:52 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

int	save_plane_lines(char *str, map_plan *plan)
{
//	char *ptr;

	//ptr = str;
	plan->one_line_plan = ft_strjoin(plan->one_line_plan, str);
	ft_printf("%s \n", plan->one_line_plan);
	ft_printf("%s \n", ft_strjoin(plan->one_line_plan, str));
	return (0);
}
