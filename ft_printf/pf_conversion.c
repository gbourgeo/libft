/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:20:03 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:33:10 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include <stdlib.h>
#include <wchar.h>

void pf_conv_init(t_conv *conversion)
{
    /* Init de la nouvelle conversion */
    conversion->type            = PRINTF_CONV_NONE;
    conversion->tail            = NULL;
    conversion->head            = NULL;
    conversion->flags.bits      = 0;
    conversion->flags.min_width = 0;
    conversion->flags.precision = 0;
    conversion->result          = 0;
    conversion->converted       = NULL;
    conversion->pos             = 0;
    conversion->len             = 0;
    conversion->error_found     = 0;
}

int pf_conv_new_result(t_conv *conversion, ssize_t len)
{
    conversion->converted = (char *) malloc(len + 1);
    conversion->len       = len;
    conversion->pos       = 0;
    if (conversion->converted == NULL)
    {
        return (-1);
    }

    return (0);
}

void pf_conv_merge_modifiers(t_data *data, t_conv *conversion)
{
    t_conv *conv = NULL;
    ssize_t iter = data->conversion_pos - 2;

    while (iter >= 0)
    {
        conv = data->conversion_table + iter;
        if (conv->type == PRINTF_CONV_LENGTH_MODIFIER)
        {
            conversion->tail = conv->tail;
            conversion->flags.bits |= conv->flags.bits;
            conversion->flags.min_width = conv->flags.min_width;
        }
        else if (conv->type == PRINTF_CONV_PRECISION)
        {
            conversion->tail = conv->tail;
            conversion->flags.bits |= conv->flags.bits;
            conversion->flags.precision = conv->flags.precision;
        }
        else
        {
            break;
        }
        iter--;
    }
}

t_conv *pf_conv_get_next_converter(t_data *data, ssize_t *pos)
{
    t_conv *conversion = NULL;

    while (*pos < data->conversion_pos)
    {
        conversion = data->conversion_table + *pos;
        *pos += 1;
        if (conversion->type == PRINTF_CONV_CONVERTER)
        {
            return (conversion);
        }
    }
    return (conversion);
}
