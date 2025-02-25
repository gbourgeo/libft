/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 18:06:57 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/03/28 11:23:49 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void		ft_strerror(char *str)
{
	if (str != NULL)
	{
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
}
