/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hexade_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:14:25 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/14 13:49:30 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_hexade_upper(t_struct *flags)
{
	unsigned int	hexade;

	flags->count = 0;
	hexade = 0;
	hexade = va_arg(flags->ap, unsigned int);
	hexade_countdigits(flags, hexade);
	if (flags->flag_width)
		flag_width_integer(flags, hexade);
	if (flags->flag_zero)
		flag_zero_integer(flags);
	if (flags->flag_precision)
		flag_precision_integer(flags);
	if (hexade == 0)
		hexade_zero(flags, hexade);
	print_hexade_upper(flags, hexade);
	if (flags->flag_minus)
		flag_minus_integer(flags, hexade);
}
