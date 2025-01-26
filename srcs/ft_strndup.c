/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 14:54:16 by gbourgeo          #+#    #+#             */
/*   Updated: 2016/04/21 18:08:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strndup(const char *src, size_t size)
{
	char	*dest = NULL;

	dest = (char *)malloc(sizeof(*dest) * (size + 1));
	if (dest != NULL)
	{
		ft_strncpy(dest, src, size);
		dest[size] = '\0';
	}
	return (dest);
}
