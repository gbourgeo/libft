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
#include <stdint.h>
#include <stdlib.h>

static unsigned long long get_modifier(t_data *data, t_conv *conversion)
{
    if (*conversion->head == 'U')
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, unsigned long) :
            (unsigned long) conversion->result;
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_Z))
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, size_t) :
            (size_t) conversion->result;
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_J))
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, uintmax_t) :
            (uintmax_t) conversion->result;
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_LL))
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, unsigned long long) :
            (unsigned long long) conversion->result;
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_L))
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, unsigned long) :
            (unsigned long) conversion->result;
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_HH))
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, int) :
            (int) conversion->result;
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_H))
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, int) :
            (int) conversion->result;
    }
    return (conversion->type == PRINTF_CONV_NONE) ?
        va_arg(data->ap, unsigned int) :
        (unsigned int) conversion->result;
}

ssize_t pf_u(t_data *data, t_conv *conversion)
{
    conversion->result = get_modifier(data, conversion);
    char   *src        = ft_ltoa_base(conversion->result, 10);
    ssize_t len        = (ssize_t) ft_strlen(src);
    ssize_t zeros      = 0;
    ssize_t spaces     = 0;

    // Minimum width
    compute_zeros_and_spaces(conversion, len, 0, &zeros, &spaces);
    // New result allocation
    if (pf_conv_new_result(conversion, len + zeros + spaces) != 0)
    {
        return (-1);
    }
    pre_write_modifiers(conversion, zeros, spaces, src, len, NULL);
    post_write_modifiers(conversion, zeros, spaces, src, len, NULL);
    free(src);
    return (0);
}
