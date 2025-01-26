/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:01:51 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/01 21:07:22 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		ft_striter(char *str, void (*func)(char *))
{
	size_t	iter = 0;

	if (str != NULL && func != NULL)
	{
		while (str[iter] != '\0')
		{
			func(str + iter);
			++iter;
		}
	}
}
