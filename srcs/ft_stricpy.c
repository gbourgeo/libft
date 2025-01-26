/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stricpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:02:23 by gbourgeo          #+#    #+#             */
/*   Updated: 2016/04/21 18:07:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		ft_stricpy(char *dest, const char *src, size_t pos)
{
	size_t	iter = 0;
	size_t	jter = 0;

	jter = ft_strlen(src);
	if (dest == NULL || src == NULL || pos > ft_strlen(dest))
	{
		return ;
	}
	if (dest[pos] != '\0')
	{
		iter = ft_strlen(dest + pos);
		while (iter > 0)
		{
			dest[pos + iter + jter - 1] = dest[pos + iter - 1];
			--iter;
		}
	}
	while (src[iter] != 0)
	{
		dest[pos + iter] = src[iter];
		++iter;
	}
}
