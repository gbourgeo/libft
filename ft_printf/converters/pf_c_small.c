/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 04:14:59 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/11/18 20:07:35 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_defines.h"
#include "ft_routine_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

static void get_parameter_value(t_data *data, t_param *parameter)
{
    if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
    {
        parameter->value  = va_arg(data->ap, int);
        parameter->status = PRINTF_PARAMETER_RECOVERED;
    }
    else
    {
        parameter->value = (int) parameter->value;
    }
}

ssize_t pf_c_small(t_data *data, t_param *parameter, t_conv *conversion)
{
    ssize_t min_width = 0;

    // Recover parameter
    get_parameter_value(data, parameter);
    // Conversion minimum width
    if (conversion->flags.min_width > 0)
    {
        min_width = conversion->flags.min_width - 1;
    }
    // Value allocation
    conversion->len   = PF_SIZEOF(int) + min_width;
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
    if (conversion->flags.bits >> (uint8_t) 7 != 0 && parameter->value > 127)
    {
        pf_conv_write_wchar(conversion, (wchar_t) parameter->value);
    }
    else
    {
        pf_conv_nwrite_char_unverified(conversion, parameter->value, 1);
    }
    // Post minimum width write
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_MINUS))
    {
        pf_conv_nwrite_char(conversion, ' ', min_width);
    }
    return (0);
}
