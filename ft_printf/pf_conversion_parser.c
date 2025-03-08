/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conversion_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:20:03 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:33:10 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_constants.h"
#include "ft_routine_printf.h"

int pf_parse_conversion_specifiers(t_data *data, t_conv *conversion)
{
    static t_converter converters[] = {
        { 'c', pf_c_small }, { 'C', pf_c_big   },
        { 'd', pf_di      }, { 'D', pf_di      },
        { 'o', pf_o       }, { 'O', pf_o       },
        { 's', pf_s_small }, { 'S', pf_s_big   },
        { 'u', pf_u       }, { 'U', pf_u       },
        { 'x', pf_x_small }, { 'X', pf_x_big   },
        { 'p', pf_p       },
        { 'i', pf_di      },
        { '%', pf_percent },
    };
    size_t iter = 0;

    while (iter < LENGTH_OF(converters))
    {
        if (converters[iter].character == *data->head)
        {
            pf_conv_merge_modifiers(data, conversion);
            if (converters[iter].handler(data, conversion) == -1)
            {
                pf_data_clean(data);
                return (-1);
            }
            conversion->converted[conversion->pos] = '\0';
            return (0);
        }
        iter++;
    }
    /* Converteur non géré */
    data->head--;
    return (0);
}
