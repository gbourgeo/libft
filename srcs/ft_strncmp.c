/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:47:34 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/01/29 13:24:49 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t	iter = 0;

	if (str1 != NULL && str2 != NULL && len > 0)
	{
		while (str1[iter] != '\0'
			&& str2[iter] != '\0'
			&& iter < len
			&& (unsigned char)str1[iter] == (unsigned char)str2[iter])
		{
			++iter;
		}
		if (iter == len || str1[iter] == '\0' || str2[iter] == '\0')
		{
			return (0);
		}
		return ((unsigned char)str1[iter] - (unsigned char)str2[iter]);
	}
	return (0);
}
