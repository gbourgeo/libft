/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:16:03 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/05/15 00:01:31 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int chr)
{
	size_t	iter = 0;

	if (str != NULL)
	{
		while (str[iter] != '\0')
		{
			if (str[iter] == chr)
			{
				return (char *)(str + iter);
			}
			iter++;
		}
	}
	return (NULL);
}
