/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 04:14:43 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/11/18 20:09:17 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_defines.h"
#include "ft_routine_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>

static void get_parameter_value(t_data *data, t_param *parameter)
{
    if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
    {
        parameter->value  = (unsigned long long) va_arg(data->ap, const wchar_t *);
        parameter->status = PRINTF_PARAMETER_RECOVERED;
    }
}

static long get_precision_length(ssize_t max_len, const wchar_t *src)
{
    ssize_t wlen = 0;

    while (*src != 0 && wlen < max_len)
    {
        wlen += pf_wcharlen((int) *src);
        if (wlen >= max_len)
        {
            break;
        }
        src++;
    }

    return wlen;
}

ssize_t pf_s_big(t_data *data, t_param *parameter, t_conv *conversion)
{
    const wchar_t *ptr       = NULL;
    ssize_t        len       = 0;
    ssize_t        min_width = 0;

    get_parameter_value(data, parameter);
    ptr = (parameter->value != 0) ?
        (const wchar_t *) parameter->value :
        L"(null)";
    len = pf_wstrlen(ptr);
    // Precision
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_DOT)
        && conversion->flags.precision < len)
    {
        len = get_precision_length(conversion->flags.precision, ptr);
    }
    // Minimum width
    min_width = (conversion->flags.min_width > len) ?
        conversion->flags.min_width - len :
        0;
    // Value allocation
    conversion->len   = len + min_width;
    conversion->value = (char *) malloc(conversion->len);
    if (conversion->value == NULL)
    {
        return (-1);
    }
    // Pre minimum width write
    if (!TEST_BIT(conversion->flags.bits, PRINTF_FLAG_MINUS))
    {
        pf_conv_nwrite_char(conversion,
                            (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_ZERO)) ? '0' : ' ',
                            min_width);
    }
    // Write value
    pf_conv_nwrite_wstr(conversion, ptr, len);
    // Post minimum width write
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_MINUS))
    {
        pf_conv_nwrite_char(conversion, ' ', min_width);
    }
    return (0);
}
