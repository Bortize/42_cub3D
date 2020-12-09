/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexade_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:42:53 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 12:21:45 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexade_zero(t_struct *flags, unsigned int hexade)
{
	if (hexade == 0 && flags->flag_precision == 0)
	{
		ft_putchar('0');
		flags->len++;
	}
	if (hexade == 0 && flags->flag_precision == 1 && flags->precision != 0)
	{
		ft_putchar('0');
		flags->len++;
	}
}
