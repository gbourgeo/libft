/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 04:56:36 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/19 17:35:15 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		ft_lstiter(t_list *lst, void (*func)(t_list *))
{
	func(lst);
	if (lst->next != NULL)
	{
		ft_lstiter(lst->next, func);
	}
}
