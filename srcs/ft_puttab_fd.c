/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 19:46:34 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/09/21 00:58:27 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_puttab_fd(char * const *table, int fd)
{
	int			i;

	i = 0;
	while (table && table[i])
	{
		ft_putendl_fd(table[i], fd);
		i++;
	}
}
