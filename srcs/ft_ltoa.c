/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 19:53:48 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/03 23:09:19 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_ltoa(long num)
{
    char *ptr  = NULL;
    int   sign = 0;
    int   iter = 0;
    long  src  = 0;

    src  = num;
    iter = (num < 0 ? 3 : 2);
    while (num /= 10)
    {
        ++iter;
    }
    ptr = (char *) malloc(sizeof(*ptr) * iter);
    if (ptr == NULL)
    {
        return (NULL);
    }
    ptr[--iter] = '\0';
    if (src == 0)
    {
        ptr[0] = '0';
    }
    sign = (src < 0 ? -1 : 1);
    if (sign < 0)
    {
        ptr[0] = '-';
    }
    while (src != 0)
    {
        ptr[--iter] = (char) (((src % 10) * sign) + 48);
        src /= 10;
    }
    return (ptr);
}
