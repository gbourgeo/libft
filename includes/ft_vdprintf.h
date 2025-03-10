/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:13:33 by gbourgeo          #+#    #+#             */
/*   Updated: 2019/07/17 13:21:17 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VPRINTF_H
#define FT_VPRINTF_H

#include "ft_base_printf.h"

int  ft_vdprintf(int filed, const char *format, va_list argp);
void ft_vdprintf_write(t_data *data);

#endif
