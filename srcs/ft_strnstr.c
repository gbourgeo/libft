/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:32:39 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/03/27 07:24:52 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char   *ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	iter_i = 0;
	size_t	iter_j = 0;

	if (str != NULL && tofind != NULL)
	{
		while (str[iter_i] != '\0' && iter_i < len)
		{
			iter_j = 0;
			while (str[iter_i + iter_j] != '\0'
				&& tofind[iter_j] != '\0'
				&& iter_i + iter_j < len
				&& tofind[iter_j] == str[iter_i + iter_j])
			{
				++iter_j;
			}
			if (tofind[iter_j] == '\0')
			{
				return (char *)(str + iter_i);
			}
			++iter_i;
		}
	}
	return (NULL);
}
