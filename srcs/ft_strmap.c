/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:22:03 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/01/13 14:06:55 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char		*ft_strmap(const char *str, char (*func)(char))
{
	char	*ptr = NULL;
	size_t	iter = 0;

	if (str != NULL && func != NULL)
	{
		ptr = ft_strdup(str);
		if (ptr != NULL)
		{
			while (str[iter] != '\0')
			{
				ptr[iter] = func(str[iter]);
				++iter;
			}
			return (ptr);
		}
	}
	return (NULL);
}
