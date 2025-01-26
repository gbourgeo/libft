/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:53:13 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/02/20 13:13:00 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strcpy(char *dest, const char *src)
{
	size_t	iter = 0;

	if (dest != NULL && src != NULL)
	{
		while (src[iter] != '\0')
		{
			dest[iter] = src[iter];
			iter++;
		}
		dest[iter] = '\0';
	}
	return (dest);
}
