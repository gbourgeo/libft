/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 19:44:38 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/09/21 00:58:09 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		ft_puttab(const char **table)
{
	size_t	iter = 0;

	if (table != NULL)
	{
		while (table[iter] != NULL)
		{
			ft_putendl(table[iter]);
			iter++;
		}
	}
}
