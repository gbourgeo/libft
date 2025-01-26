/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:26:55 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/17 06:04:55 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

void	ft_putstr(char const *str)
{
	size_t	len = 0;

	len = ft_strlen(str);
	write(STDOUT_FILENO, str, len);
}
