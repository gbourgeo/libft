/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:19:11 by gbourgeo          #+#    #+#             */
/*   Updated: 2018/09/21 07:19:33 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"
#include "ft_base_printf.h"
#include <stddef.h>

int ft_sprintf(char *str, const char * restrict format, ...)
{
    t_data data = { 0 };
    int    ret  = -1;

    if (pf_data_init(&data,
                     PRINTF_OUTPUT_BUFFER,
                     (u_output) { .buff.str = str, .buff.size = (size_t) -1 },
                     format) == 0)
    {
        va_start(data.ap, format);
        ret = pf_routine(&data);
        va_end(data.ap);
    }
    pf_data_clean(&data);
    return (ret);
}
