/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 00:19:41 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/09/21 00:57:46 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t		ft_tablen(const char **table)
{
	size_t	iter = 0;

	if (table != NULL)
	{
		while (table[iter] != NULL)
		{
			++iter;
		}
	}
	return (iter);
}
