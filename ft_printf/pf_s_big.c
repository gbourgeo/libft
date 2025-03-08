/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 04:14:43 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/11/18 20:09:17 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_constants.h"
#include "ft_routine_printf.h"
#include "libft.h"
#include <stddef.h>
#include <wchar.h>

static long get_precision_length(ssize_t max_len, const wchar_t *src)
{
    ssize_t wlen = 0;

    while (*src != 0 && wlen < max_len)
    {
        wlen += pf_wcharlen((int) *src);
        if (wlen >= max_len)
        {
            break;
        }
        src++;
    }

    return wlen;
}

ssize_t pf_s_big(t_data *data, t_conv *conversion)
{
    const wchar_t *ptr       = (conversion->type == PRINTF_CONV_NONE) ?
              va_arg(data->ap, const wchar_t *) :
              (const wchar_t *) conversion->result;
    ssize_t        len       = 0;
    ssize_t        min_width = 0;

    if (ptr == NULL)
    {
        ptr = L"(null)";
    }
    len = pf_wstrlen(ptr);
    // Precision
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_DOT)
        && conversion->flags.precision < len)
    {
        len = get_precision_length(conversion->flags.precision, ptr);
    }
    // Minimum width
    min_width = (conversion->flags.min_width > len) ?
        conversion->flags.min_width - len :
        0;
    // New result allocation
    if (pf_conv_new_result(conversion, len + min_width) != 0)
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
    // Write result
    pf_conv_nwrite_wstr(conversion, ptr, len);
    // Post minimum width write
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_MINUS))
    {
        pf_conv_nwrite_char(conversion, ' ', min_width);
    }
    conversion->result = (unsigned long long) ptr;
    return (0);
}
