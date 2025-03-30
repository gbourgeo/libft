/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 04:14:39 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:37:28 by gbourgeo         ###   ########.fr       */
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
    if (*data->head == 'U'
        || TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_Z)
        || TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_J)
        || TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_L))
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
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_LL))
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, unsigned long long);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_HH)
             || TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_H))
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
    else
    {
        if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            parameter->value  = va_arg(data->ap, unsigned int);
            parameter->status = PRINTF_PARAMETER_RECOVERED;
        }
        else
        {
            parameter->value = (unsigned int) parameter->value;
        }
    }
    return (ft_ltoa_base(parameter->value, 10));
}

ssize_t pf_u(t_data *data, t_param *parameter, t_conv *conversion)
{
    char   *src    = NULL;
    ssize_t len    = 0;
    ssize_t zeros  = 0;
    ssize_t spaces = 0;

    src = get_parameter_value(data, parameter, conversion);
    len = (ssize_t) ft_strlen(src);
    // Minimum width
    compute_zeros_and_spaces(parameter, conversion, len, 0, &zeros, &spaces);
    // Value allocation
    conversion->len   = len + zeros + spaces;
    conversion->value = (char *) malloc(conversion->len);
    if (conversion->value == NULL)
    {
        free(src);
        return (-1);
    }
    pre_convert_specifiers(parameter, conversion, zeros, spaces, src, len, NULL);
    post_convert_specifiers(parameter, conversion, zeros, spaces, src, len, NULL);
    free(src);
    return (0);
}
