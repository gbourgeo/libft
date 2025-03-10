/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 22:33:04 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:37:06 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "libft.h"
#include <stdlib.h>

ssize_t pf_p(t_data *data, t_conv *conversion)
{
    const char *prefix = "0x";
    conversion->result = (conversion->type == PRINTF_CONV_NONE) ?
        va_arg(data->ap, unsigned long long) :
        conversion->result;
    char   *src        = ft_ltoa_base(conversion->result, 16);
    ssize_t len        = (ssize_t) ft_strlen(src);
    ssize_t zeros      = 0;
    ssize_t spaces     = 0;

    compute_zeros_and_spaces(conversion, len, 2, &zeros, &spaces);
    // New result allocation
    if (pf_conv_new_result(conversion, len + zeros + spaces + 2) != 0)
    {
        return (-1);
    }
    pre_write_modifiers(conversion, zeros, spaces, src, len, prefix);
    post_write_modifiers(conversion, zeros, spaces, src, len, prefix);
    free(src);
    return (0);
}
