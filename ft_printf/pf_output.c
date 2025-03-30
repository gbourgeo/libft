/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 02:08:51 by gbourgeo          #+#    #+#             */
/*   Updated: 2018/04/11 02:30:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

ssize_t pf_output_string(t_data *data, const char *str, size_t len)
{
    if (str == NULL || len == 0)
    {
        return (0);
    }
    if (data->family == PRINTF_OUTPUT_FILE_DESCRIPTOR)
    {
        return (write(data->output.fd, str, len));
    }
    if (data->family == PRINTF_OUTPUT_FILE_STREAM)
    {
        return (ssize_t) (fwrite(str,
                                 1,
                                 len,
                                 data->output.stream));
    }
    if (data->family == PRINTF_OUTPUT_BUFFER)
    {
        size_t iter = 0;
        size_t pos  = data->output.buff.pos;

        while (iter + pos < data->output.buff.size
               && iter < len)
        {
            data->output.buff.str[pos + iter] = str[iter];
            iter++;
        }
        data->output.buff.str[pos + iter] = '\0';
        data->output.buff.pos += iter;
        return (ssize_t) (iter);
    }
    return (0);
}

ssize_t pf_output_conversion(t_data *data, t_conv *conversion)
{
    ssize_t wrote = 0;

    if (conversion->value != NULL && conversion->pos > 0)
    {
        wrote += pf_output_string(data, conversion->value, conversion->pos);
    }
    return (wrote);
}
