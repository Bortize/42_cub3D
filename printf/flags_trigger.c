/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_trigger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 11:23:06 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 11:40:43 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_trigger(const char *format, t_struct *flags)
{
	minus_zero_flag(format, flags);
	width_flag(format, flags);
	precision_flag(format, flags);
}
