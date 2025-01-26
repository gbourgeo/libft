/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 19:29:44 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/04/01 00:00:25 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *str, unsigned int start, size_t len)
{
	size_t	iter = 0;
	char	*ptr = NULL;

	if (str != NULL)
	{
		ptr = malloc(sizeof(*ptr) * (len + 1));
		if (ptr != NULL)
		{
			while (iter < len && str[start + iter] != '\0')
			{
				ptr[iter] = str[start + iter];
				iter++;
			}
			ptr[iter] = '\0';
			return (ptr);
		}
	}
	return (NULL);
}
