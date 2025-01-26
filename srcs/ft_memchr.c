/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 21:55:10 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/03/27 19:23:30 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memchr(const void *src, int chr, size_t len)
{
	size_t	iter = 0;

	if (src != NULL)
	{
		while (iter < len)
		{
			if ((unsigned char)chr == ((unsigned char *)src)[iter])
			{
				return ((void *)(src + iter));
			}
			++iter;
		}
	}
	return (NULL);
}
