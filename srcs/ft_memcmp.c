/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 22:38:17 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/01/13 14:07:40 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t len)
{
	size_t	iter = 0;

	if (ptr1 != NULL && ptr2 != NULL)
	{
		while (iter < len)
		{
			if (((unsigned char *)ptr1)[iter] != ((unsigned char *)ptr2)[iter])
			{
				return (((unsigned char *)ptr1)[iter] - ((unsigned char *)ptr2)[iter]);
			}
			++iter;
		}
		return (0);
	}
	return (-1);
}
