/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision_integer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 08:50:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 11:36:56 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_precision_integer(t_struct *flags)
{
	int num_len;

	num_len = flags->count;
	flags->j = 0;
	if (flags->flag_integer_negative)
		num_len -= 1;
	if (flags->precision > num_len)
	{
		while (flags->j < (flags->precision - num_len))
		{
			write(1, "0", 1);
			flags->len++;
			flags->j++;
		}
	}
}
