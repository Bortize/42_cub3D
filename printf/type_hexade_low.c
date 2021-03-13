/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hexade_low.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:36:34 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/13 13:05:33 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_hexade_low(t_struct *flags)
{
	unsigned int	hexade;

	flags->count = 0;
	hexade = 0;
	hexade = va_arg(flags->ap, unsigned int);
	hexade_countdigits(flags, hexade);
	if (flags->flag_width)
		flag_width_integer(flags, hexade);
	if (hexade < 0)
		hexade = print_negative(flags, hexade);
	if (flags->flag_zero)
		flag_zero_integer(flags);
	if (flags->flag_precision)
		flag_precision_integer(flags);
	if (hexade == 0)
		hexade_zero(flags, hexade);
	print_hexade_low(flags, hexade);
	if (flags->flag_minus)
		flag_minus_integer(flags, hexade);
}
