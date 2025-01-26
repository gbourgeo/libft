/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 00:22:23 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/09/21 00:57:33 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_tabdup(const char **table)
{
	char	**cpy = NULL;
	size_t	iter = 0;

	cpy = (char **)malloc(sizeof(*table) * (ft_tablen(table) + 1));
	if (cpy == NULL)
	{
		return (NULL);
	}
	iter = 0;
	if (table != NULL)
	{
		while (table[iter] != NULL)
		{
			cpy[iter] = ft_strdup(table[iter]);
			iter++;
		}
	}
	cpy[iter] = NULL;
	return (cpy);
}
