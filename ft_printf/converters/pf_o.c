/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 04:14:53 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:36:43 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_constants.h"
#include "ft_routine_printf.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static char *get_parameter_value(
    t_data  *data,
    t_param *parameter,
    t_conv  *conversion)
{
    if (*data->head == 'O'
        || (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_LL)))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, unsigned long long);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        return (ft_ltoa_base(parameter->value, 8));
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_Z)
        || (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_L))
        || (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_J)))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, unsigned long);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        parameter->value = (unsigned long) parameter->value;
        return (ft_ltoa_base(parameter->value, 8));
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_HH))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = (unsigned char) va_arg(data->ap, int);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        parameter->value = (unsigned char) parameter->value;
        return (ft_itoa_base(parameter->value, 8));
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_H))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = (unsigned short) va_arg(data->ap, int);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        parameter->value = (unsigned short) parameter->value;
        return (ft_itoa_base(parameter->value, 8));
    }
    if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
    {
        parameter->value  = va_arg(data->ap, unsigned int);
        parameter->status = PRINTF_PARAMETER_RECOVERED;
    }
    parameter->value = (unsigned int) parameter->value;
    return (ft_itoa_base(parameter->value, 8));
}

static const char *get_prefix_value(t_param *parameter, t_conv *conversion)
{
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_HASH)
        && parameter->value != 0)
    {
        return ("0");
    }
    return (NULL);
}

ssize_t pf_o(t_data *data, t_param *parameter, t_conv *conversion)
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
    // Special treatment
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_HASH)
        && TEST_BIT(conversion->flags.bits, PRINTF_FLAG_DOT))
    {
        if (parameter->value != 0)
        {
            if (conversion->flags.precision > len)
            {
                zeros -= 1;
                if (spaces > 0)
                {
                    spaces += 1;
                }
            }
        }
        else if (conversion->flags.precision == 0)
        {
            zeros = 1;
            spaces -= 1;
        }
    }
    // Value allocation
    conversion->len   = len + (prefix != NULL) + zeros + spaces;
    conversion->value = (char *) malloc(conversion->len);
    if (conversion->value == NULL)
    {
        free(src);
        return (-1);
    }
    pre_convert_specifiers(parameter, conversion, zeros, spaces, src, len, prefix);
    post_convert_specifiers(parameter, conversion, zeros, spaces, src, len, prefix);
    free(src);
    return (0);
}
