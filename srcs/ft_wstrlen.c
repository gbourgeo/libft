/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:22:13 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/17 06:02:11 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>

size_t ft_wstrlen(const wchar_t *str)
{
    size_t len = 0;

    if (str != NULL)
    {
        while (str[len] != 0)
        {
            len++;
        }
    }
    return (len);
}
