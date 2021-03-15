/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:14:02 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/13 13:05:26 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_integer(t_struct *flags)
{
	int	integer;

	flags->count = 0;
	integer = 0;
	integer = va_arg(flags->ap, int);
	int_counter(flags, integer);
	if (flags->flag_minus && flags->flag_zero && flags->flag_width)
		flags->flag_zero = 0;
	if (flags->aux < 0)
		flags->precision = 0;
	if (flags->flag_width)
		flag_width_integer(flags, integer);
	if (integer < 0)
		integer = print_negative(flags, integer);
	if (flags->flag_zero)
		flag_zero_integer(flags);
	if (flags->flag_precision)
		flag_precision_integer(flags);
	print_integer(flags, integer);
	if (flags->flag_minus)
		flag_minus_integer(flags, integer);
}
