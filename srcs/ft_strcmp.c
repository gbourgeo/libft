/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:39:09 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/01/29 13:23:16 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t	iter = 0;

	if (str1 != NULL && str2 != NULL)
	{
		while (str1[iter] != '\0'
			&& str2[iter] != '\0'
			&& (unsigned char)str1[iter] == (unsigned char)str2[iter])
		{
			++iter;
		}
		return ((unsigned char)str1[iter] - (unsigned char)str2[iter]);
	}
	return (-1);
}
