/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:09:49 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/03 23:06:07 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char		*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	iter = 0;

	if (dest != NULL)
	{
		if (src != NULL)
		{
			while (src[iter] != '\0'
				&& iter < len)
			{
				dest[iter] = src[iter];
				++iter;
			}
		}
		while (iter < len)
		{
			dest[iter] = '\0';
			iter++;
		}
	}
	return (dest);
}
