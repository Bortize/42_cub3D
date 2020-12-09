/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 01:12:36 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 12:23:05 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(t_struct *flags, unsigned long pointer)
{
	if (pointer != 0)
	{
		print_pointer(flags, pointer / 16);
		if (pointer % 16 >= 10)
		{
			ft_putchar('a' + (pointer % 16 % 10));
			flags->len++;
		}
		else
		{
			ft_putchar('0' + pointer % 16);
			flags->len++;
		}
	}
}
