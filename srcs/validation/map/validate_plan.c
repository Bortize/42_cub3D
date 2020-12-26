/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:52:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/26 14:49:47 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

int		validate_plan(char *str, map_plan *plan)
{
	check_characters(str, plan);
	if (plan->row_len < ft_strlen(str))
		plan->row_len = ft_strlen(str);
	return (0);
}
