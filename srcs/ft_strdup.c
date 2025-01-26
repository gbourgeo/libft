/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:54:28 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/03/30 21:58:59 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *str)
{
	char	*dup = NULL;
	size_t	len = 0;
	size_t	iter = 0;

	if (str != NULL)
	{
		len = ft_strlen(str);
		dup = (char*)malloc(sizeof(*dup) * (len + 1));
		if (dup != NULL)
		{
			while (iter < len)
			{
				dup[iter] = str[iter];
				iter++;
			}
			dup[iter] = '\0';
		}
	}
	return (dup);
}
