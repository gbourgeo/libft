/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 04:14:34 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:37:44 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_constants.h"
#include "ft_routine_printf.h"
#include "libft.h"
#include <stdlib.h>

static char *get_parameter_value(
    t_data  *data,
    t_param *parameter,
    t_conv  *conversion)
{
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_Z)
        || TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_LL))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, unsigned long long);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        return (ft_ltoa_base(parameter->value, 16));
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_J))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, uintmax_t);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        else
        {
            parameter->value = (uintmax_t) parameter->value;
        }
        return (ft_ltoa_base(parameter->value, 16));
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_L))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, unsigned long);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        else
        {
            parameter->value = (unsigned long) parameter->value;
        }
        return (ft_ltoa_base(parameter->value, 16));
    }
    /* if (TEST_BIT(parameter->flags.bits, PRINTF_LENGTH_HH)
             || TEST_BIT(parameter->flags.bits, PRINTF_LENGTH_H)) */
    if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
    {
        parameter->value  = va_arg(data->ap, int);
        parameter->status = PRINTF_PARAMETER_RECOVERED;
    }
    else
    {
        parameter->value = (int) parameter->value;
    }
    return (ft_itoa_base(parameter->value, 16));
}

ssize_t pf_x(t_data *data, t_param *parameter, t_conv *conversion)
{
    const char *prefix     = NULL;
    char       *src        = NULL;
    ssize_t     len        = 0;
    ssize_t     prefix_len = 0;
    ssize_t     zeros      = 0;
    ssize_t     spaces     = 0;

    src = get_parameter_value(data, parameter, conversion);
    len = (ssize_t) ft_strlen(src);
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_HASH)
        && parameter->value != 0)
    {
        prefix     = (*data->head == 'X') ? "0X" : "0x";
        prefix_len = 2;
    }
    // Minimum width
    compute_zeros_and_spaces(parameter, conversion, len, prefix_len, &zeros, &spaces);
    // Value allocation
    conversion->len   = len + zeros + spaces + prefix_len;
    conversion->value = (char *) malloc(conversion->len);
    if (conversion->value == NULL)
    {
        free(src);
        return (-1);
    }
    if (*data->head == 'X')
    {
        ft_strtoupper(src);
    }
    pre_convert_specifiers(parameter, conversion, zeros, spaces, src, len, prefix);
    post_convert_specifiers(parameter, conversion, zeros, spaces, src, len, prefix);
    free(src);
    return (0);
}
