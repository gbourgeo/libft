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

int pf_data_init(t_data     *data,
                 e_output    family,
                 u_output    output,
                 const char *format)
{
    size_t iter = 0;

    data->family = PRINTF_OUTPUT_FILE_DESCRIPTOR;
    if (family == PRINTF_OUTPUT_FILE_DESCRIPTOR)
    {
        data->output.fd = output.fd;
    }
    else if (PRINTF_OUTPUT_FILE_STREAM)
    {
        data->output.stream = output.stream;
    }
    else if (PRINTF_OUTPUT_BUFFER)
    {
        data->output.buff.str  = output.buff.str;
        data->output.buff.pos  = 0;
        data->output.buff.size = output.buff.size;
    }
    data->tail             = format;
    data->head             = format;
    data->conversion_table = (t_conv *) malloc(sizeof(t_conv) * PRELOAD_CONVERSION_NB);
    if (data->conversion_table == NULL)
    {
        return (-1);
    }
    while (iter < PRELOAD_CONVERSION_NB)
    {
        pf_conv_init(data->conversion_table + iter);
        iter++;
    }
    data->conversion_pos = 0;
    data->conversion_len = PRELOAD_CONVERSION_NB;
    return (0);
}

void pf_data_clean(t_data *data)
{
    ssize_t iter       = 0;
    t_conv *conversion = NULL;

    while (iter < data->conversion_pos)
    {
        conversion = data->conversion_table + iter;
        free(conversion->converted);
        iter++;
    }
    data->conversion_pos = 0;
    free(data->conversion_table);
    data->conversion_table = NULL;
}

t_conv *pf_data_get_next_conversion(t_data *data, const char *tail, const char *head)
{
    t_conv *conv = NULL;
    size_t  len  = 0;

    /* Augmentation du tableau de résultat de conversion */
    while (data->conversion_pos >= data->conversion_len)
    {
        data->conversion_len += PRELOAD_CONVERSION_NB;
        len  = sizeof(t_conv) * data->conversion_len;
        conv = (t_conv *) realloc(data->conversion_table, len);
        if (conv == NULL)
        {
            return (NULL);
        }
        data->conversion_table = conv;
    }
    conv = data->conversion_table + data->conversion_pos;
    /* Incrément de la position à l'élément suivant dans le tableau */
    data->conversion_pos++;
    /* Initialisation du nouvel élément */
    conv->tail = tail;
    conv->head = head;
    return (conv);
}
