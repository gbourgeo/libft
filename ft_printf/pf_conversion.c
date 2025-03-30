/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conversion_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:20:03 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:33:10 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>

void pf_conversion_debug(t_conv *conversion)
{
    ssize_t iter = 0;

    (void) write(STDOUT_FILENO, "\n\e[34m** CONVERSION\n", 21);
    write(STDOUT_FILENO, "[", 1);
    ft_putnbr((int) iter);
    write(STDOUT_FILENO, "]:", 2);
    write(STDOUT_FILENO, "\n    parameter  : ", 19);
    write(STDOUT_FILENO, conversion->tail, conversion->head - conversion->tail);
    write(STDOUT_FILENO, "\n    specifiers : ", 19);
    ft_putbits(conversion->flags.bits, sizeof(conversion->flags.bits));
    write(STDOUT_FILENO, "\n    width      : ", 19);
    ft_putnbr((int) conversion->flags.min_width);
    write(STDOUT_FILENO, "\n    precision  : ", 19);
    ft_putnbr((int) conversion->flags.precision);
    write(STDOUT_FILENO, "\n    conversion : ", 19);
    write(STDOUT_FILENO, conversion->value, conversion->len);
    write(STDOUT_FILENO, "\n    hex        : ", 19);
    iter = 0;
    while (iter < conversion->pos)
    {
        printf("%#.02x ", (uint8_t) conversion->value[iter]);
        iter++;
    }
    (void) fflush(stdout);
    write(STDOUT_FILENO, "\n    pos        : ", 19);
    ft_putnbr((int) conversion->pos);
    write(STDOUT_FILENO, "\n    len        : ", 19);
    ft_putnbr((int) conversion->len);
    write(STDOUT_FILENO, "\n", 1);
    (void) write(STDOUT_FILENO, "\e[0m", 5);
}

void pf_conversion_init(t_conv *conversion, const char *src)
{
    conversion->tail            = src;
    conversion->head            = src;
    conversion->flags.bits      = 0;
    conversion->flags.min_width = 0;
    conversion->flags.precision = 0;
    conversion->value           = NULL;
    conversion->pos             = 0;
    conversion->len             = 0;
    conversion->error_found     = 0;
}

void pf_conversion_free(t_conv *conversion)
{
    free(conversion->value);
}
