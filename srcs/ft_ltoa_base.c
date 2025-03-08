/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 22:06:38 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:35:29 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char *ft_ltoa_base(unsigned long long num, unsigned int base)
{
    const char        *base_str = "0123456789abcdef";
    unsigned long long size     = (num == 0);
    unsigned long long iter     = num;
    char              *ret      = NULL;

    if (base == 0 || base > ft_strlen(base_str))
    {
        return (NULL);
    }
    while (iter)
    {
        size++;
        iter /= base;
    }
    ret = ft_strnew(size + 1);
    if (ret != NULL)
    {
        while (size-- > 0)
        {
            ret[size] = base_str[num % base];
            num /= base;
        }
    }
    return (ret);
}
