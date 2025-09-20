/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s_small.c                                       :+:      :+:    :+:   */
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
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>

static const char *get_parameter_value(t_data  *data,
                                       t_param *parameter)
{
    if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
    {
        parameter->value  = (unsigned long long) va_arg(data->ap, const char *);
        parameter->status = PRINTF_PARAMETER_RECOVERED;
    }
    return ((parameter->value != 0) ?
                (const char *) parameter->value :
                "(null)");
}

ssize_t pf_s_small(t_data *data, t_param *parameter, t_conv *conversion)
{
    const char *ptr       = NULL;
    ssize_t     len       = 0;
    ssize_t     min_width = 0;

    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_L))
    {
        return (pf_s_big(data, parameter, conversion));
    }
    ptr = get_parameter_value(data, parameter);
    len = (ssize_t) ft_strlen(ptr);
    // Precision
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_DOT)
        && conversion->flags.precision < len)
    {
        len = conversion->flags.precision;
    }
    // Minimum width
    min_width         = (conversion->flags.min_width > len) ?
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
    pf_conv_nwrite_str(conversion, ptr, len);
    // Post minimum width write
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_MINUS))
    {
        pf_conv_nwrite_char(conversion, ' ', min_width);
    }
    return (0);
}
