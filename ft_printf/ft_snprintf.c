/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:18:19 by gbourgeo          #+#    #+#             */
/*   Updated: 2018/09/21 07:18:58 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_snprintf.h"
#include "ft_base_printf.h"
#include <stdarg.h>
#include <stddef.h>

int ft_snprintf(char *str, size_t size,
                const char * restrict format, ...)
{
    t_data data = { 0 };
    int    ret  = -1;

    if (pf_data_init(&data,
                     PRINTF_OUTPUT_BUFFER,
                     (u_output) { .buff.str = str, .buff.size = size },
                     format) == 0)
    {
        va_start(data.ap, format);
        ret = pf_routine(&data);
        va_end(data.ap);
    }
    pf_data_clean(&data);
    return (ret);
}
