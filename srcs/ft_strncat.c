/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:42:55 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/03 23:05:32 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char		*ft_strncat(char *dest, const char *src, size_t len)
{
	size_t	iter_d = 0;
	size_t	iter_s = 0;

	if (dest != NULL && src != NULL)
	{
		iter_d = ft_strlen(dest);
		while (src[iter_s] != '\0' && iter_d + 1 < len)
		{
			dest[iter_d++] = src[iter_s++];
		}
		dest[iter_d] = '\0';
	}
	return (dest);
}
