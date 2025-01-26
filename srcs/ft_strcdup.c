/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 10:58:57 by gbourgeo          #+#    #+#             */
/*   Updated: 2016/04/21 18:03:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strcdup(const char *str, char chr)
{
	char	*dest = NULL;
	size_t	len = 0;

	if (str != NULL)
	{
		while (str[len] != '\0'
			&& str[len] != chr)
		{
			len++;
		}
		dest = (char *)malloc(sizeof(*dest) * (len + 1));
		if (dest != NULL)
		{
			ft_strncpy(dest, str, len);
			dest[len] = '\0';
		}
	}
	return (dest);
}
