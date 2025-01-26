/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 05:28:41 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/19 17:35:13 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*func)(t_list *))
{
	t_list	*so_fresh = NULL;

	so_fresh = (t_list *)malloc(sizeof(*so_fresh));
	so_fresh = func(lst);
	if (lst->next != NULL)
	{
		so_fresh->next = ft_lstmap(lst->next, func);
	}
	return (so_fresh);
}
