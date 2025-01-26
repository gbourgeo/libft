/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 13:51:45 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/02/04 14:06:05 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strrcdup(const char *src, char chr)
{
	char	*dest = NULL;
	size_t	iter = 0;
	size_t	len = 0;

	iter = 0;
	len = ft_strlen(src);
	while (len > 0 && src[len - 1] != chr)
	{
		--len;
	}
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest != NULL)
	{
		ft_strncpy(dest, src, len);
		dest[iter] = '\0';
	}
	return (dest);
}
