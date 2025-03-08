/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:26:05 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/02/10 19:23:51 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putbits(unsigned long number, size_t size)
{
    size_t        iter      = 0;
    unsigned long bit       = 0;
    size_t        padding = 0;

    if (size > sizeof(unsigned long))
    {
        return;
    }
    padding = (sizeof(unsigned long) - size) * 8;
    while (iter < size * 8)
    {
        if (iter != 0 && iter % 8 == 0)
        {
            ft_putchar(' ');
        }
        bit = (number << (iter + padding));
        bit >>= ((sizeof(unsigned long) * 8) - 1);
        ft_putnbr((int) bit);
        iter++;
    }
}
