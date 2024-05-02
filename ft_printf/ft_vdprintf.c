/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:05:53 by gbourgeo          #+#    #+#             */
/*   Updated: 2019/07/17 13:18:50 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_vdprintf.h"

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_dt		data;
	int			ret;

	ft_memset(&data, 0, sizeof(data));
	data.fd = fd;
	data.tail = (char *)format;
	data.writeto = ft_vdprintf_write;
	va_copy(data.ap, ap);
	ret = pf_routine(&data);
	va_end(data.ap);
	return (ret);
}
