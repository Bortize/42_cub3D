/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:35:04 by borjagrd          #+#    #+#             */
/*   Updated: 2020/10/20 08:33:38 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_struct
{
	va_list		ap;
	int			i;
	int			j;
	int			len;
	int			flag_minus;
	int			flag_zero;
	int			aux;
	int			flag_aux;
	int			width;
	int			flag_width;
	int			precision;
	int			flag_precision;
	int			count;
	int			flag_integer_negative;
}				t_struct;

int				ft_printf(const char *format, ...);
void			initialize_flags(t_struct *flags);
void			check_flags(const char *format, t_struct *flags);
void			check_type(const char *format, t_struct *flags);
void			minus_zero_flag(const char *format, t_struct *flags);
void			width_flag(const char *format, t_struct	*flags);
void			precision_flag(const char *format, t_struct *flags);
void			flags_trigger(const char *format, t_struct *flags);
void			int_counter(t_struct *flags, int integer);
void			int_counter_unsigned(t_struct *flags, unsigned int integer);
void			hexade_countdigits(t_struct *flags, unsigned int hexade);
void			flag_width_integer(t_struct *flags, long int integer);
void			flag_width_string(t_struct *flags, char *string);
void			flag_width_pointer(t_struct *flags, int pointer);
void			type_integer(t_struct *flags);
void			type_unsigned_int(t_struct *flags);
void			type_string(t_struct *flags);
void			type_char(t_struct *flags);
void			type_hexade_low(t_struct *flags);
void			type_hexade_upper(t_struct *flags);
void			type_pointer(t_struct *flags);
void			type_percent(t_struct *flags);
void			type_char(t_struct *flags);
void			flag_zero_integer(t_struct *flags);
void			hexade_zero(t_struct *flags, unsigned int hexade);
void			flag_zero_percent(t_struct *flags);
void			flag_precision_integer(t_struct *flags);
void			flag_precision_string(t_struct *flags, char *str);
int				print_negative(t_struct *flags, long int integer);
void			print_integer_width(t_struct *flags);
void			print_unsigned(t_struct *flags, unsigned int unsign);
void			print_string_width(t_struct *flags);
void			print_integer(t_struct *flags, int integer);
void			print_string(t_struct *flags, char *str);
void			print_hexade_low(t_struct *flags, unsigned int hexade);
void			print_hexade_upper(t_struct *flags, unsigned int hexade);
void			print_pointer_width(t_struct *flags);
void			print_pointer(t_struct *flags, unsigned long pointer);
void			flag_minus_integer(t_struct *flags, int intger);
void			flag_minus_string(t_struct *flags);
void			flag_minus_pointer(t_struct *flags, int pointer);
void			flag_minus_percent(t_struct *flags);
char			*itoa_unsigned(unsigned int n);
void			flag_precision_pointer(t_struct *flags);
void			pointer_countdigits(t_struct *flags, unsigned long pointer);

#endif
