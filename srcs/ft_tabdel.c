/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 01:16:15 by gbourgeo          #+#    #+#             */
/*   Updated: 2019/10/30 20:47:00 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_tabdel(char ***table)
{
	size_t	iter = 0;

	if (table != NULL && *table != NULL)
	{
		while ((*table)[iter])
		{
			free((*table)[iter]);
			(*table)[iter] = NULL;
			iter++;
		}
		free((void *)*table);
		*table = NULL;
	}
}
