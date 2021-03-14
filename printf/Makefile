# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/21 11:25:34 by borjagrd          #+#    #+#              #
#    Updated: 2021/03/13 23:38:38 by rnavarre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

.SILENT:

NAME		=	libftprintf.a

LIBFT		=	libft.a

SRCS		=	ft_printf.c \
				initialize_flags.c \
				check_flags.c \
				check_type.c \
				minus_zero_flag.c \
				flag_zero_percent.c \
				width_flag.c \
				precision_flag.c \
				flags_trigger.c \
				int_counter.c \
				hexade_countdigits.c \
				flag_width_integer.c \
				flag_width_string.c \
				flag_width_pointer.c \
				type_integer.c \
				type_unsigned_int.c \
				type_string.c \
				type_char.c \
				type_hexade_low.c \
				type_hexade_upper.c \
				type_pointer.c \
				type_percent.c \
				flag_zero_integer.c \
				flag_precision_integer.c \
				flag_precision_string.c \
				print_integer_width.c \
				print_negative.c \
				print_string_width.c \
				print_integer.c \
				print_unsigned.c \
				print_string.c \
				print_hexade_low.c \
				print_hexade_upper.c \
				print_hexade_upper.c \
				print_pointer.c \
				print_pointer_width.c \
				flag_minus_integer.c \
				flag_minus_string.c \
				flag_minus_pointer.c \
				flag_minus_pointer.c \
				flag_minus_percent.c \
				hexade_zero.c \
				itoa_unsigned.c \
				flag_precision_pointer.c \
				pointer_countdigits.c \

CC			= @gcc

CFLAGS		= -Wall -Wextra -Werror

OBJS		= $(SRCS:.c=.o)

INCLUDE		= ./libft

AR			= ar rcs

RM			= rm -rf

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME):	$(INCLUDE) $(OBJS)
				@$(CC) $(CFLAGS) -c $(SRCS)
				# Llama al Makefile que esta en la ruta ./libft
				@make -C $(INCLUDE)
				@echo "\n	LIBRERIA GENERADA ✅ 👉 libft.a \n"
				@cp libft/libft.a ./
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJS)
				@echo "\n	LIBRERIA GENERADA (libft+printf) ✅ 👉 libftprintf.a \n"
				@ranlib $(NAME)
				@echo "\n	GENERANDO INDEX ✅ 👉 libftprintf.a \n"

clean:
			$(RM) $(OBJS)
			make -C $(INCLUDE) clean

fclean:		clean
				@$(RM) $(NAME)
				@make -C $(INCLUDE) fclean
				@$(RM) a.out a.out.dSYM

re:			fclean all

debug:		CFLAGS += -g3 -fsanitize=address
debug:		$(NAME)

.PHONY:		all clean fclean re
