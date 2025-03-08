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
#include "ft_constants.h"
#include "ft_routine_printf.h"
#include <wchar.h>

static unsigned long long get_modifier(t_data *data, t_conv *conversion)
{
    return (conversion->type == PRINTF_CONV_NONE) ?
        va_arg(data->ap, int) :
        (int) (conversion->result);
}

ssize_t pf_c_small(t_data *data, t_conv *conversion)
{
    conversion->result = get_modifier(data, conversion);
    ssize_t min_width  = 0;

    if (conversion->flags.min_width > 0)
    {
        min_width = conversion->flags.min_width - 1;
    }
    // New result allocation
    if (pf_conv_new_result(conversion, (long) (sizeof(int) + min_width)) != 0)
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
    if (conversion->flags.bits >> 7 != 0 && conversion->result > 127)
    {
        pf_conv_write_wchar(conversion, (wchar_t) conversion->result);
    }
    else
    {
        pf_conv_nwrite_char_unverified(conversion, conversion->result, 1);
    }
    // Post minimum width write
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_MINUS))
    {
        pf_conv_nwrite_char(conversion, ' ', min_width);
    }
    return (0);
}
