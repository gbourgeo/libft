/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unhandled.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 23:29:41 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/08/16 04:57:34 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include <stdlib.h>

ssize_t pf_unhandled(t_data *data, t_conv *conversion)
{
    t_param parameter = {};
    ssize_t zeros     = 0;
    ssize_t spaces    = 0;

    compute_zeros_and_spaces(&parameter, conversion, 1, 0, &zeros, &spaces);
    // Value allocation
    conversion->len   = 1 + zeros + spaces + 2;
    conversion->value = (char *) malloc(conversion->len);
    if (conversion->value == NULL)
    {
        return (-1);
    }
    pre_convert_specifiers(&parameter, conversion, zeros, spaces, data->head, 1, NULL);
    post_convert_specifiers(&parameter, conversion, zeros, spaces, data->head, 1, NULL);
    return (0);
}
