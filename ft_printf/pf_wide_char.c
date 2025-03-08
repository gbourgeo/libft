/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wide_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 04:14:34 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:37:44 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include <string.h>
#include <wchar.h>

ssize_t pf_wcharlen(wchar_t src)
{
    if (src < 0x80)
    {
        return (1);
    }
    if (src < 0x800)
    {
        return (2);
    }
    if (src < 0x10000)
    {
        return (3);
    }
    if (src < 0x200000)
    {
        return (4);
    }
    return (1);
}

ssize_t pf_wstrlen(const wchar_t *src)
{
    ssize_t len = 0;

    if (src != NULL)
    {
        while (*src != 0)
        {
            len += pf_wcharlen(*src);
            src++;
        }
    }
    return (len);
}
