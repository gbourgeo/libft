/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x_small.c                                       :+:      :+:    :+:   */
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

ssize_t pf_x_small(t_data *data, t_conv *conversion)
{
    const char *prefix = NULL;
    char       *src    = NULL;
    conversion->result = get_x_modifier(data, conversion, &src);
    ssize_t len        = (ssize_t) ft_strlen(src);
    ssize_t prefix_len = 0;
    ssize_t zeros      = 0;
    ssize_t spaces     = 0;

    if (TEST_BIT(conversion->flags.bits, PRINTF_FLAG_HASH)
        && conversion->result != 0)
    {
        prefix     = "0x";
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
