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
#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

static ssize_t pf_output_to(t_data *data, const char *str, size_t len)
{
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

ssize_t pf_output(t_data *data)
{
    ssize_t     iter        = 0;
    t_conv     *conversion  = NULL;
    const char *ptr         = data->tail;
    ssize_t     wrote       = 0;
    int         error_found = 0;

    while (iter < data->conversion_pos)
    {
        conversion = pf_conv_get_next_converter(data, &iter);
        if (conversion == NULL)
        {
            break;
        }
        if (conversion->tail > ptr)
        {
            wrote += pf_output_to(data, ptr, conversion->tail - ptr);
        }
        if (conversion->converted != NULL
            && conversion->pos > 0)
        {
            wrote += pf_output_to(data,
                                  conversion->converted,
                                  conversion->pos);
            if (conversion->error_found != 0)
            {
                error_found = 1;
            }
        }
        ptr = conversion->head;
    }
    if (conversion != NULL
        && conversion->pos > 0
        && conversion->tail > ptr)
    {
        wrote += pf_output_to(data, ptr, conversion->tail - ptr);
        ptr = conversion->head;
    }
    if (data->head > ptr)
    {
        wrote += pf_output_to(data, ptr, data->head - ptr);
    }

#ifdef PRINTF_DEBUG
    write(STDOUT_FILENO, "\n\e[34m** CONVERSIONS\n", 22);
    iter = 0;
    while (iter < data->conversion_pos)
    {
        conversion = data->conversion_table + iter;
        printf("   [%zu] %.*s\n", iter, (int) (conversion->head - conversion->tail), conversion->tail);
        printf("         type            : %d\n", conversion->type);
        write(1, "         specifiers      : ", 28);
        ft_putbits(conversion->flags.bits, sizeof(conversion->flags.bits));
        write(STDOUT_FILENO, "\n", 1);
        printf("         width           : %ld\n"
               "         precision       : %ld\n"
               "         result          : %ld\n"
               "         pos             : %lu\n"
               "         len             : %lu\n"
               "         converted       : %s\n",
               conversion->flags.min_width,
               conversion->flags.precision,
               (ssize_t) conversion->result,
               conversion->pos,
               conversion->len,
               conversion->converted);
        ssize_t jter = 0;
        write(STDOUT_FILENO, "         hex             :", 27);
        while (jter < conversion->pos)
        {
            printf(" %#.02x", (uint8_t) conversion->converted[jter]);
            jter++;
        }
        (void) fflush(stdout);
        write(STDOUT_FILENO, "\n", 1);
        iter++;
    }
    write(STDOUT_FILENO, "\e[0m", 5);
    iter = 0;
#endif
    return ((error_found != 0) ? -1 : wrote);
}
