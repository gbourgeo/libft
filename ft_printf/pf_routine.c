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
    t_conv conversion;

    while (*data->head != '\0')
    {
        if (*data->head == '%')
        {
            data->wrote += pf_output_string(data, data->tail, data->head - data->tail);
            pf_conversion_init(&conversion, data->head);
            if (pf_parse_modifiers(data, &conversion) == 0)
            {
                if (*data->head != '\0'
                    && pf_parse_specifiers(data, &conversion) != 0)
                    {
                        return (-1);
                    }
                    data->wrote += pf_output_conversion(data, &conversion);
                    #ifdef PRINTF_DEBUG
                    pf_parameter_table_debug(&data->parameters);
                    pf_conversion_debug(&conversion);
                    #endif
                }
            data->tail = data->head + 1;
        }
        data->head += (*data->head != '\0') ? 1 : 0;
    }
    data->wrote += pf_output_string(data, data->tail, data->head - data->tail);
    return (int) (data->wrote);
}
