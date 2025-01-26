/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:55:01 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/05/15 00:17:28 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void			*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	iter = 0;

	if (dest != NULL && src != NULL)
	{
		while (iter < len)
		{
			((unsigned char *)dest)[iter] = ((const unsigned char *)src)[iter];
			++iter;
		}
	}
	return (dest);
}
