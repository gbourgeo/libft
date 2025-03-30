/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 04:22:17 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:39:29 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_constants.h"
#include "ft_routine_printf.h"
#include "libft.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

static char *get_parameter_value(t_data *data, t_param *parameter, t_conv *conversion)
{
    int is_negative = 0;

    if (*data->head == 'D')
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, unsigned long long);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_Z))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, size_t);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        else
        {
            parameter->value = (size_t) parameter->value;
        }
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_J))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, intmax_t);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        else
        {
            parameter->value = (intmax_t) parameter->value;
        }
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_LL))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, long long);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        else
        {
            parameter->value = (long long) parameter->value;
        }
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_L))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, long);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        else
        {
            parameter->value = (long) parameter->value;
        }
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_HH))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = (signed char) va_arg(data->ap, int);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        else
        {
            parameter->value = (signed char) parameter->value;
        }
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_H))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = (short) va_arg(data->ap, int);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        else
        {
            parameter->value = (short) parameter->value;
        }
    }
    else
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
    is_negative = ((long) parameter->value < 0) ? -1 : 1;
    return (ft_ltoa((long) parameter->value * is_negative));
}

static const char *get_prefix_value(t_param *parameter, t_conv *conversion)
{
    if ((long long) parameter->value < 0)
    {
        return ("-");
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_PLUS))
    {
        return ("+");
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_SPACE))
    {
        return (" ");
    }
    return (NULL);
}

ssize_t pf_di(t_data *data, t_param *parameter, t_conv *conversion)
{
    char       *src    = NULL;
    const char *prefix = NULL;
    ssize_t     len    = 0;
    ssize_t     zeros  = 0;
    ssize_t     spaces = 0;

    src    = get_parameter_value(data, parameter, conversion);
    prefix = get_prefix_value(parameter, conversion);
    len    = (ssize_t) ft_strlen(src);
    // Minimum width
    compute_zeros_and_spaces(parameter, conversion, len, (prefix != NULL), &zeros, &spaces);
    // Value allocation
    conversion->len   = len + zeros + spaces + (prefix != NULL) + 1;
    conversion->value = (char *) malloc(conversion->len);
    if (conversion->value == NULL)
    {
        return (-1);
    }
    pre_convert_specifiers(parameter, conversion, zeros, spaces, src, len, prefix);
    post_convert_specifiers(parameter, conversion, zeros, spaces, src, len, prefix);
    free(src);
    return (0);
}
