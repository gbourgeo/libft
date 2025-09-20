/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:08:51 by gbourgeo          #+#    #+#             */
/*   Updated: 2018/04/11 02:39:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "ft_base_printf.h"
#include <stdarg.h>

int ft_fprintf(FILE *stream, const char * restrict format, ...)
{
    t_data data = { 0 };
    int    ret  = -1;

    if (pf_data_init(&data,
                     PRINTF_OUTPUT_FILE_STREAM,
                     (u_output) { .stream = stream },
                     format) == 0)
    {
        va_start(data.ap, format);
        ret = pf_routine(&data);
        va_end(data.ap);
    }
    pf_data_clean(&data);
    return (ret);
}
