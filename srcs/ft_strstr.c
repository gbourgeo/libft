/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:55:58 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/04/11 08:07:41 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strstr(const char *str, const char *tofind)
{
	size_t	iter_i = 0;
	size_t	iter_j = 0;

	if (str != NULL && tofind != NULL)
	{
		while (str[iter_i] != '\0')
		{
			iter_j = 0;
			while (tofind[iter_j] != '\0'
				&& str[iter_i + iter_j] != '\0'
				&& tofind[iter_j] == str[iter_i + iter_j])
			{
				iter_j++;
			}
			if (tofind[iter_j] == '\0')
				return (char *)(str + iter_i);
			iter_i++;
		}
		if (tofind[iter_j] == '\0')
		{
			return (char *)(str + iter_i);
		}
	}
	return (NULL);
}
