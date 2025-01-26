/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:54:52 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/01 21:12:54 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char				*ft_strmapi(char const *str, char (*func)(unsigned int, char))
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
				ptr[iter] = func(iter, str[iter]);
				++iter;
			}
			return (ptr);
		}
	}
	return (NULL);
}
