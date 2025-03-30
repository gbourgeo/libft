/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 04:14:53 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:36:43 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_constants.h"
#include "ft_routine_printf.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

ssize_t pf_n(t_data *data, t_param *parameter, t_conv _unused *conversion)
{
    if (parameter->status == PRINTF_PARAMETER_NOT_RECOVERED)
    {
        parameter->value  = (unsigned long long) va_arg(data->ap, int *);
        parameter->status = PRINTF_PARAMETER_RECOVERED;
    }
    if (parameter->value != 0)
    {
        *(int *) parameter->value = (int) data->wrote;
    }
    return (0);
}
