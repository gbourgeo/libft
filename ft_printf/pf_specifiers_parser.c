/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_specifiers_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:20:03 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:33:10 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_defines.h"
#include "ft_routine_printf.h"
#include <stddef.h>

int pf_parse_specifiers(t_data *data, t_conv *conv)
{
    static t_spec_hdlr converters[] = {
        { 'c', pf_c_small },
        { 'C', pf_c_big   },
        { 'd', pf_di      },
        { 'D', pf_di      },
        { 'o', pf_o       },
        { 'O', pf_o       },
        { 's', pf_s_small },
        { 'S', pf_s_big   },
        { 'u', pf_u       },
        { 'U', pf_u       },
        { 'x', pf_x       },
        { 'X', pf_x       },
        { 'i', pf_di      },
        { 'n', pf_n       },
        { 'p', pf_p       },
    };
    t_param *param = NULL;
    size_t   iter  = 0;

    while (iter < LENGTH_OF(converters))
    {
        if (converters[iter].character == *data->head)
        {
            param = pf_parameter_new(&data->parameters);
            if (converters[iter].handler(data, param, conv) == -1)
            {
                pf_data_clean(data);
                return (-1);
            }
            param->status = PRINTF_PARAMETER_RECOVERED;
            conv->head    = data->head + 1;
            return (0);
        }
        iter++;
    }
    pf_unhandled(data, conv);
    conv->head = data->head + 1;
    return (0);
}
