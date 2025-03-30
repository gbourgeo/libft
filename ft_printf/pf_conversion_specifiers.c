/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conversion_specifiers.c                         :+:      :+:    :+:   */
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

void compute_zeros_and_spaces(
    t_param *parameter,
    t_conv  *conversion,
    ssize_t  result_len,
    ssize_t  prefix_len,
    ssize_t *zeros,
    ssize_t *spaces)
{
    if (conversion->flags.precision > result_len)
    {
        *zeros = conversion->flags.precision - result_len;
    }
    if (conversion->flags.min_width > *zeros + result_len)
    {
        if (!TEST_BIT(conversion->flags.bits, PRINTF_FLAG_DOT)
            && !TEST_BIT(conversion->flags.bits, PRINTF_FLAG_MINUS)
            && TEST_BIT(conversion->flags.bits, PRINTF_FLAG_ZERO))
        {
            *zeros = conversion->flags.min_width - (*zeros + result_len + prefix_len);
        }
        else
        {
            *spaces = conversion->flags.min_width - (*zeros + result_len + prefix_len);
            if (*spaces < 0)
            {
                *spaces = 0;
            }
            if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_DOT)
                && conversion->flags.precision == 0
                && parameter->value == 0)
            {
                *spaces += 1;
            }
        }
    }
}

void pre_convert_specifiers(
    t_param    *parameter,
    t_conv     *conversion,
    ssize_t     zeros,
    ssize_t     spaces,
    const char *src,
    ssize_t     len,
    const char *prefix)
{
    // minus implique d'écrire le résultat à gauche
    if (!TEST_BIT(conversion->flags.bits, PRINTF_FLAG_MINUS))
    {
        pf_conv_nwrite_char(conversion, ' ', spaces);
        pf_conv_nwrite_str(conversion, prefix, (ssize_t) ft_strlen(prefix));
        pf_conv_nwrite_char(conversion, '0', zeros);
        if (!TEST_BIT(conversion->flags.bits, PRINTF_FLAG_DOT)
            || conversion->flags.precision != 0
            || parameter->value > 0)
        {
            pf_conv_nwrite_str(conversion, src, len);
        }
    }
}

void post_convert_specifiers(
    t_param    *parameter,
    t_conv     *conversion,
    ssize_t     zeros,
    ssize_t     spaces,
    const char *src,
    ssize_t     len,
    const char *prefix)
{
    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_MINUS))
    {
        pf_conv_nwrite_str(conversion, prefix, (ssize_t) ft_strlen(prefix));
        pf_conv_nwrite_char(conversion, '0', zeros);
        if (!TEST_BIT(conversion->flags.bits, PRINTF_FLAG_DOT)
            || conversion->flags.precision != 0
            || parameter->value > 0)
        {
            pf_conv_nwrite_str(conversion, src, len);
        }
        pf_conv_nwrite_char(conversion, ' ', spaces);
    }
}
