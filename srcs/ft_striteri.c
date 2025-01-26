/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:24:19 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/01 21:07:47 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		ft_striteri(char *str, void (*func)(unsigned int, char *))
{
	size_t	iter = 0;

	if (str != NULL && func != NULL)
	{
		while (str[iter] != '\0')
		{
			func(iter, str + iter);
			++iter;
		}
	}
}
