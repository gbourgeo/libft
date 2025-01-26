/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 18:51:33 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/01/27 18:14:20 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int num, int fde)
{
	int		ret = 0;

	if (num < 0)
	{
		ft_putchar_fd('-', fde);
		if (num == -2147483648)
			ret = 1;
		num = (num + ret) * (-1);
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fde);
		ft_putnbr_fd((num % 10) + ret, fde);
	}
	else
		ft_putchar_fd(num + 48, fde);
}
