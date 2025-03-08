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
#include <stdint.h>
#include <stdlib.h>

static unsigned long long get_modifier(t_data *data,
                                       t_conv *conversion,
                                       char  **src)
{
    unsigned long long result = 0;

    if (*conversion->head == 'O')
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, unsigned long long) :
            conversion->result;
        *src   = ft_ltoa_base(result, 8);
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_Z))
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, size_t) :
            (size_t) conversion->result;
        *src   = ft_ltoa_base(result, 8);
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_J))
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, uintmax_t) :
            (uintmax_t) conversion->result;
        *src   = ft_ltoa_base(result, 8);
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_LL))
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, unsigned long long) :
            conversion->result;
        *src   = ft_ltoa_base(result, 8);
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_L))
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, unsigned long) :
            (unsigned long) conversion->result;
        *src   = ft_ltoa_base(result, 8);
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_HH))
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            (unsigned char) va_arg(data->ap, int) :
            (unsigned char) conversion->result;
        *src   = ft_itoa_base(result, 8);
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_H))
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            (unsigned short) va_arg(data->ap, int) :
            (unsigned short) conversion->result;
        *src   = ft_itoa_base(result, 8);
    }
    else
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, unsigned int) :
            (unsigned int) conversion->result;
        *src   = ft_itoa_base(result, 8);
    }
    return (result);
}

ssize_t pf_o(t_data *data, t_conv *conversion)
{
    const char *prefix = NULL;
    char       *src    = NULL;
    conversion->result = get_modifier(data, conversion, &src);
    ssize_t len        = (ssize_t) ft_strlen(src);
    ssize_t prefix_len = 0;
    ssize_t zeros      = 0;
    ssize_t spaces     = 0;

    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_HASH)
        && conversion->result != 0)
    {
        prefix     = "0";
        prefix_len = 1;
    }
    // Minimum width
    compute_zeros_and_spaces(conversion, len, prefix_len, &zeros, &spaces);
    // Special treatment
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_HASH)
        && TEST_BIT(conversion->flags.bits, PRINTF_FLAG_DOT))
    {
        if (conversion->result != 0)
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
    // New result allocation
    if (pf_conv_new_result(conversion, len + prefix_len + zeros + spaces) != 0)
    {
        return (-1);
    }
    pre_write_modifiers(conversion, zeros, spaces, src, len, prefix);
    post_write_modifiers(conversion, zeros, spaces, src, len, prefix);
    free(src);
    return (0);
}
