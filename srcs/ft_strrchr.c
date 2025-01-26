/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:18:35 by gbourgeo          #+#    #+#             */
/*   Updated: 2016/06/26 19:58:20 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char		*ft_strrchr(const char *str, int chr)
{
	size_t	iter = 0;

	if (str != NULL)
	{
		iter = ft_strlen(str);
		while (iter > 0 && str[iter] != chr)
		{
			--iter;
		}
		if (str[iter] == chr)
		{
			return (char *)(str + iter);
		}
	}
	return (NULL);
}
