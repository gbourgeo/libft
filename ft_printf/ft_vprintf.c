/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:05:53 by gbourgeo          #+#    #+#             */
/*   Updated: 2019/07/17 13:18:50 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vprintf.h"
#include "ft_base_printf.h"
#include <unistd.h>

int ft_vprintf(const char *format, va_list argp)
{
    t_data data = { 0 };
    int    ret  = -1;

    if (pf_data_init(&data,
                     PRINTF_OUTPUT_FILE_DESCRIPTOR,
                     (u_output) { .fd = STDOUT_FILENO },
                     format) == 0)
    {
        va_copy(data.ap, argp);
        ret = pf_routine(&data);
        va_end(data.ap);
    }
    pf_data_clean(&data);
    return (ret);
}
