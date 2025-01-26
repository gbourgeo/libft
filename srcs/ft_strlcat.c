/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:34:33 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/02/01 21:35:58 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	iter_d = 0;
	size_t	iter_s = 0;

	if (dest == NULL || src == NULL)
	{
		return (0);
	}
	iter_d = ft_strlen(dest);
	if (size > iter_d)
	{
		while (src[iter_s] != '\0' && iter_d + iter_s < size - 1)
		{
			dest[iter_d + iter_s] = src[iter_s];
			++iter_s;
		}
		dest[iter_d + iter_s] = '\0';
		return (ft_strlen(src) + iter_d);
	}
	return (ft_strlen(src) + size);
}
