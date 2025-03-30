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

ssize_t pf_p(t_data *data, t_param *parameter, t_conv *conversion)
{
    const char *prefix = "0x";

    if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
    {
        parameter->value = va_arg(data->ap, unsigned long long);
        parameter->status = PRINTF_PARAMETER_RECOVERED;
    }
    char   *src    = ft_ltoa_base(parameter->value, 16);
    ssize_t len    = (ssize_t) ft_strlen(src);
    ssize_t zeros  = 0;
    ssize_t spaces = 0;

    compute_zeros_and_spaces(parameter, conversion, len, 2, &zeros, &spaces);
    // Value allocation
    conversion->len   = len + zeros + spaces + 2;
    conversion->value = (char *) malloc(conversion->len);
    if (conversion->value == NULL)
    {
        free(src);
        return (-1);
    }
    pre_convert_specifiers(parameter, conversion, zeros, spaces, src, len, prefix);
    post_convert_specifiers(parameter, conversion, zeros, spaces, src, len, prefix);
    free(src);
    return (0);
}
