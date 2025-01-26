/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:42:48 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/03/17 19:32:55 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

void		ft_putendl_fd(char const *str, int fde)
{
	size_t	len = 0;

	len = ft_strlen(str);
	write(fde, str, len);
	write(fde, "\n", 1);
}
