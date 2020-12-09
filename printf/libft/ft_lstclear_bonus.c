/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:24:34 by bgomez-r          #+#    #+#             */
/*   Updated: 2019/12/27 17:26:28 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_aux;
	t_list	*save;

	if (*lst != NULL)
	{
		lst_aux = *lst;
		while (lst_aux != NULL)
		{
			save = lst_aux->next;
			del(lst_aux->content);
			free(lst_aux);
			lst_aux = save;
		}
		*lst = NULL;
	}
}
