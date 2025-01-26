/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 05:43:22 by gbourgeo          #+#    #+#             */
/*   Updated: 2016/04/21 18:03:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_str2join(char const *str1, char const *str2, char const *str3)
{
	size_t	len = 0;
	char	*ptr = NULL;

	len = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3) + 1;
	ptr = (char *)malloc(sizeof(*ptr) * len);
	if (ptr != NULL)
	{
		ptr = ft_strcpy(ptr, str1);
		ptr = ft_strcat(ptr, str2);
		ptr = ft_strcat(ptr, str3);
	}
	return (ptr);
}
