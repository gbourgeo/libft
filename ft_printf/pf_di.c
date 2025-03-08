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

static unsigned long long get_modifier(t_data *data, t_conv *conversion)
{
    if (*conversion->head == 'D')
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, unsigned long long) :
            conversion->result;
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
            va_arg(data->ap, intmax_t) :
            (intmax_t) conversion->result;
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_LL))
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, long long) :
            (long long) conversion->result;
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_L))
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            va_arg(data->ap, long) :
            (long) conversion->result;
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_HH))
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            (signed char) va_arg(data->ap, int) :
            (signed char) conversion->result;
    }
    if (TEST_BIT(conversion->flags.bits, PRINTF_LENGTH_H))
    {
        return (conversion->type == PRINTF_CONV_NONE) ?
            (short) va_arg(data->ap, int) :
            (short) conversion->result;
    }
    return (conversion->type == PRINTF_CONV_NONE) ?
        va_arg(data->ap, int) :
        (int) conversion->result;
}

ssize_t pf_di(t_data *data, t_conv *conversion)
{
    char   *prefix      = NULL;
    char   *src         = NULL;
    ssize_t len         = 0;
    ssize_t zeros       = 0;
    ssize_t spaces      = 0;
    int     is_negative = 0;

    conversion->result = get_modifier(data, conversion);
    is_negative        = ((long) conversion->result < 0) ? -1 : 1;
    src                = ft_ltoa((long) conversion->result * is_negative);
    len                = (ssize_t) ft_strlen(src);

    if ((long long) conversion->result < 0)
    {
        prefix = "-";
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_PLUS))
    {
        prefix = "+";
    }
    else if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_SPACE))
    {
        prefix = " ";
    }
    // Minimum width
    compute_zeros_and_spaces(conversion,
                             len,
                             (prefix != NULL),
                             &zeros,
                             &spaces);
    // New result allocation
    if (pf_conv_new_result(conversion,
                           len + zeros + spaces + (prefix != NULL) + 1)
        != 0)
    {
        return (-1);
    }
    pre_write_modifiers(conversion,
                        zeros,
                        spaces,
                        src,
                        len,
                        prefix);
    post_write_modifiers(conversion,
                         zeros,
                         spaces,
                         src,
                         len,
                         prefix);
    free(src);
    return (0);
}
