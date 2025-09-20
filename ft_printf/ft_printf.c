/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:08:51 by gbourgeo          #+#    #+#             */
/*   Updated: 2018/04/11 02:30:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_base_printf.h"
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char * restrict format, ...)
{
    t_data data = { 0 };
    int    ret  = -1;

    if (pf_data_init(&data,
                     PRINTF_OUTPUT_FILE_DESCRIPTOR,
                     (u_output) { .fd = STDOUT_FILENO },
                     format) == 0)
    {
        va_start(data.ap, format);
        ret = pf_routine(&data);
        va_end(data.ap);
    }
    pf_data_clean(&data);
    return (ret);
}
