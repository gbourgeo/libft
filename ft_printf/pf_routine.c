/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:20:03 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:33:10 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include <stddef.h>

int pf_routine(t_data *data)
{
    t_conv *conversion = NULL;
    ssize_t wrote      = 0;

    while (*data->head != '\0')
    {
        if (*data->head == '%')
        {
            conversion = pf_data_get_next_conversion(data, data->head, data->head);
            if (conversion == NULL)
            {
                return (-1);
            }
            if (pf_parse_conversion_modifiers(data, &conversion) == 0)
            {
                if (pf_parse_conversion_specifiers(data, conversion) != 0)
                {
                    return (-1);
                }
                conversion->type = PRINTF_CONV_CONVERTER;
                conversion->head = data->head + 1;
            }
        }
        if (*data->head != '\0')
        {
            data->head++;
        }
    }
    wrote = pf_output(data);
    return (int) (wrote);
}
