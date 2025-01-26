/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 19:32:45 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/11/28 15:31:13 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	iter = 0;

	if (dest != NULL && src != NULL)
	{
		while (iter < len)
		{
			((unsigned char *)dest)[iter] = ((unsigned char *)src)[iter];
			++iter;
		}
	}
	return (dest);
}
