/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttabc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 19:44:38 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/09/21 00:58:09 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_puttabc(char * const *table, char * const preprint)
{
	int		i;

	i = 0;
	while (table && table[i])
	{
		ft_putstr(preprint);
		ft_putendl(table[i]);
		i++;
	}
}
