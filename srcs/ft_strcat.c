/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:42:45 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/01/21 14:52:51 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char		*ft_strcat(char *dest, const char *src)
{
	size_t	iter_d = 0;
	size_t	iter_s = 0;

	if (dest != NULL && src != NULL)
	{
		iter_d = ft_strlen(dest);
		while (src[iter_s] != '\0')
		{
			dest[iter_d + iter_s] = src[iter_s];
			iter_s++;
		}
		dest[iter_d + iter_s] = '\0';
	}
	return (dest);
}
