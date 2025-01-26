/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:39:41 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/02/01 21:50:06 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		*ft_memccpy(void *dest, const void *src, int chr, size_t len)
{
	size_t	iter = 0;

	if (dest != NULL && src != NULL)
	{
		while (iter < len)
		{
			((unsigned char *)dest)[iter] = ((unsigned char *)src)[iter];
			if (((unsigned char *)src)[iter] == (unsigned char)chr)
			{
				return (dest + iter + 1);
			}
			iter++;
		}
	}
	return (NULL);
}
