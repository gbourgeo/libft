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

unsigned long long get_x_modifier(t_data *data, t_conv *conversion, char **src)
{
    unsigned long long result = 0;

    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_Z)
        || TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_LL))
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            (unsigned long long) va_arg(data->ap, unsigned long long) :
            (unsigned long long) conversion->result;
        *src   = ft_ltoa_base(result, 16);
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_J))
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            (uintmax_t) va_arg(data->ap, uintmax_t) :
            (uintmax_t) conversion->result;
        *src   = ft_ltoa_base(result, 16);
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_L))
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            (unsigned long) va_arg(data->ap, unsigned long) :
            (unsigned long) conversion->result;
        *src   = ft_ltoa_base(result, 16);
    }
    else /* if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_HH)
             || TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_H)) */
    {
        result = (conversion->type == PRINTF_CONV_NONE) ?
            (int) va_arg(data->ap, int) :
            (int) conversion->result;
        *src   = ft_itoa_base(result, 16);
    }
    return (result);
}

ssize_t pf_x_big(t_data *data, t_conv *conversion)
{
    const char *prefix = NULL;
    char       *src    = NULL;
    conversion->result = get_x_modifier(data, conversion, &src);
    ssize_t len        = (ssize_t) ft_strlen(src);
    ssize_t prefix_len = 0;
    ssize_t zeros      = 0;
    ssize_t spaces     = 0;

    ft_strtoupper(src);
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_HASH)
        && conversion->result != 0)
    {
        prefix     = "0X";
        prefix_len = 2;
    }
    // Minimum width
    compute_zeros_and_spaces(conversion, len, prefix_len, &zeros, &spaces);
    // New result allocation
    if (pf_conv_new_result(conversion, len + zeros + spaces + prefix_len) != 0)
    {
        return (-1);
    }
    pre_write_modifiers(conversion, zeros, spaces, src, len, prefix);
    post_write_modifiers(conversion, zeros, spaces, src, len, prefix);
    free(src);
    return (0);
}
