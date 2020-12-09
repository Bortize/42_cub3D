/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 10:42:04 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/22 09:15:37 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_integer(t_struct *flags, int integer)
{
	char *number;

	flags->j = 0;
	if (flags->flag_precision == 1 && flags->precision == 0 && integer == 0)
		flags->j = 0;
	else
	{
		number = ft_itoa(integer);
		while (number[flags->j] != '\0')
		{
			flags->len += write(1, &number[flags->j], 1);
			flags->j++;
		}
		free(number);
		number = NULL;
	}
}
