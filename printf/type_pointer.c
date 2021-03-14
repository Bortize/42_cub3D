/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:58:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/14 13:49:30 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_pointer(t_struct *flags)
{
	unsigned long pointer;

	pointer = 0;
	flags->count = 0;
	pointer = va_arg(flags->ap, unsigned long);
	pointer_countdigits(flags, pointer);
	if (flags->flag_width)
		flag_width_pointer(flags, pointer);
	write(1, "0x", 2);
	flags->len += 2;
	if (flags->flag_zero)
		flag_zero_integer(flags);
	if (flags->flag_precision)
		flag_precision_pointer(flags);
	if (pointer == 0)
		hexade_zero(flags, pointer);
	print_pointer(flags, pointer);
	if (flags->flag_minus)
		flag_minus_pointer(flags, pointer);
}
