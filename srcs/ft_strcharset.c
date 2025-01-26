/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 14:57:52 by gbourgeo          #+#    #+#             */
/*   Updated: 2016/04/21 18:04:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char		*ft_strcharset(const char *str, const char *charset)
{
	size_t	iter = 0;
	size_t	jter = 0;

	if (str != NULL && charset != NULL)
	{
		while (str[iter] != '\0')
		{
			jter = 0;
			while (charset[jter] != '\0')
			{
				if (str[iter] == charset[jter])
				{
					return (char *)(str + iter);
				}
				++jter;
			}
			++iter;
		}
	}
	return (NULL);
}
