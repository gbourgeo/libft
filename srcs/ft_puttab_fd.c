/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 19:46:34 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/09/21 00:58:27 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		ft_puttab_fd(const char **table, int fde)
{
	size_t	iter = 0;

	if (table != NULL)
	{
		while (table[iter] != NULL)
		{
			ft_putendl_fd(table[iter], fde);
			iter++;
		}
	}
}
