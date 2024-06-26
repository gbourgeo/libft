/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 00:19:41 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/09/21 00:57:46 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_tablen(const char **table)
{
	int		i;

	i = 0;
	while (table && table[i])
		i++;
	return (i);
}
