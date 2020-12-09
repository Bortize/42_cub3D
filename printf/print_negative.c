/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:16:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 12:23:01 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_negative(t_struct *flags, long int integer)
{
	if (integer == -2147483648)
		return (integer);
	write(1, "-", 1);
	flags->len++;
	integer *= -1;
	return (integer);
}
