/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:00:01 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/02/10 19:20:38 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		ft_strclr(char *str)
{
	size_t	iter = 0;

	if (str != NULL)
	{
		while (str[iter] != '\0')
		{
			str[iter] = '\0';
			++iter;
		}
	}
}
