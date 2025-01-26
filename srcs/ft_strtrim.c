/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 20:37:27 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/01 18:10:07 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char		*ft_strtrim(char const *str)
{
	size_t	start = 0;
	size_t	end = 0;

	if (str != NULL)
	{
		end = ft_strlen(str);
		while (ft_iswhitespace(str[start]) != 0)
		{
			++start;
		}
		while (end > start && ft_iswhitespace(str[end]) != 0)
		{
			--end;
		}
		return (ft_strsub(str, start, (end - start + 1)));
	}
	return (NULL);
}
