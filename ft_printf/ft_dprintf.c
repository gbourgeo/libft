/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:17:15 by gbourgeo          #+#    #+#             */
/*   Updated: 2018/09/21 07:17:15 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "ft_base_printf.h"
#include <stdarg.h>

int ft_dprintf(int filed, const char * restrict format, ...)
{
    t_data data = { 0 };
    int    ret  = -1;

    if (pf_data_init(&data,
                 PRINTF_OUTPUT_FILE_DESCRIPTOR,
                 (u_output) { .fd = filed },
                 format) == 0)
    {
        va_start(data.ap, format);
        ret = pf_routine(&data);
        va_end(data.ap);
    }
    pf_data_clean(&data);
    return (ret);
}
