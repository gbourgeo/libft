/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 19:51:09 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/03/30 00:11:11 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char		*ft_strjoin(char const *str1, char const *str2)
{
	size_t	len = 0;
	char	*ptr = NULL;

	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	ptr = ft_strnew(len);
	if (ptr != NULL)
	{
		ptr = ft_strcpy(ptr, str1);
		ptr = ft_strcat(ptr, str2);
	}
	return (ptr);
}
