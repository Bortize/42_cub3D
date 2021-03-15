/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_unsigned_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:10:46 by borjagrd          #+#    #+#             */
/*   Updated: 2021/03/15 01:28:31 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_unsigned_int(t_struct *flags)
{
	unsigned int integer;

	flags->count = 0;
	integer = 0;
	integer = va_arg(flags->ap, unsigned int);
	int_counter_unsigned(flags, integer);
	if (flags->flag_width)
		flag_width_integer(flags, integer);
	if (flags->flag_zero)
		flag_zero_integer(flags);
	if (flags->flag_precision)
		flag_precision_integer(flags);
	print_unsigned(flags, integer);
	if (flags->flag_minus)
		flag_minus_integer(flags, integer);
}

void	int_counter_unsigned(t_struct *flags, unsigned int integer)
{
	char	*str;

	flags->flag_integer_negative = 0;
	str = itoa_unsigned(integer);
	flags->count = ft_strlen(str);
	free(str);
	str = NULL;
}
