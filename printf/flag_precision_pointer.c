/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 21:11:58 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 11:37:04 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_precision_pointer(t_struct *flags)
{
	int aux;

	aux = flags->count;
	flags->j = 0;
	if (flags->flag_integer_negative)
		aux -= 1;
	if (flags->precision > aux)
	{
		while (flags->j < (flags->precision - aux))
		{
			write(1, "0", 1);
			flags->len++;
			flags->j++;
		}
	}
}
