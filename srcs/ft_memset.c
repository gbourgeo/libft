/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:07:39 by gbourgeo          #+#    #+#             */
/*   Updated: 2016/06/14 02:53:41 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memset(void *ptr, int chr, size_t len)
{
	size_t	iter = 0;

	if (ptr != NULL)
	{
		while (iter < len)
		{
			((unsigned char *)ptr)[iter] = (unsigned char)chr;
			iter++;
		}
	}
	return (ptr);
}
