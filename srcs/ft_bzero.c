/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:50:19 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/01/10 14:02:14 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_bzero(void *ptr, size_t len)
{
	size_t	iter = 0;

	if (ptr != NULL)
	{
		while (iter < len)
		{
			((unsigned char *)ptr)[iter] = 0;
			iter++;
		}
	}
}
