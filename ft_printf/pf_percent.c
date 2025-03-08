/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 23:29:41 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/08/16 04:57:34 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_constants.h"
#include <stdlib.h>

ssize_t pf_percent(t_data _unused *data, t_conv *conversion)
{
    ssize_t zeros  = 0;
    ssize_t spaces = 0;

    conversion->result = '%';
    compute_zeros_and_spaces(conversion, 1, 0, &zeros, &spaces);
    // New result allocation
    if (pf_conv_new_result(conversion, 1 + zeros + spaces) != 0)
    {
        return (-1);
    }
    pre_write_modifiers(conversion, zeros, spaces, "%", 1, NULL);
    post_write_modifiers(conversion, zeros, spaces, "%", 1, NULL);
    return (0);
}
