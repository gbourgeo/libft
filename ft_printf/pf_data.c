/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:08:51 by gbourgeo          #+#    #+#             */
/*   Updated: 2018/04/11 02:30:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include <stdlib.h>
#include <string.h>

int pf_data_init(t_data     *data,
                 e_output    family,
                 u_output    output,
                 const char *format)
{
    data->family = family;
    if (family == PRINTF_OUTPUT_FILE_DESCRIPTOR)
    {
        data->output.fd = output.fd;
    }
    else if (family == PRINTF_OUTPUT_FILE_STREAM)
    {
        data->output.stream = output.stream;
    }
    else if (family == PRINTF_OUTPUT_BUFFER)
    {
        data->output.buff.str  = output.buff.str;
        data->output.buff.pos  = 0;
        data->output.buff.size = output.buff.size;
    }
    data->tail = format;
    data->head = format;
    return (pf_parameter_table_init(&data->parameters) != 0);
}

void pf_data_clean(t_data *data)
{
    pf_parameter_table_free(&data->parameters);
}

int pf_data_dyn_table_check(t_dyntab *dyntable, size_t elem_size, void (*elem_initialiser)(void *))
{
    void   *ptrtable = NULL;
    ssize_t iter     = 0;

    if (dyntable->pos < 0)
    {
        return (-1);
    }
    /* Augmentation du tableau des paramètres si nécessaire */
    if (dyntable->pos + 1 >= dyntable->len)
    {
        dyntable->len += PRELOAD_CONVERSION_NB;
        ptrtable = realloc(dyntable->table, elem_size * dyntable->len);
        if (ptrtable == NULL)
        {
            return (-1);
        }
        dyntable->table = ptrtable;
        iter            = dyntable->pos;
        while (iter < dyntable->len)
        {
            elem_initialiser(dyntable->table + (iter * elem_size));
            iter++;
        }
    }
    return (0);
}
