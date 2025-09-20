/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 12:19:02 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/11/14 12:19:59 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long ft_atol(const char *str)
{
    long iter  = 0;
    long res   = 0;
    long isneg = 1;

    while (str[iter] == ' ' || str[iter] == '\n' || str[iter] == '\t'
           || str[iter] == '\v' || str[iter] == '\f' || str[iter] == '\r')
    {
        iter++;
    }
    if (str[iter] == '-')
    {
        isneg = -1;
        iter++;
    }
    else if (str[iter] == '+')
    {
        iter++;
    }
    while (str[iter] != '\0' && ft_isdigit(str[iter]) != 0)
    {
        res = res * 10;
        res = res + str[iter++] - '0';
    }
    return (res * isneg);
}
