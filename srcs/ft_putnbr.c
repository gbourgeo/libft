/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:52:14 by gbourgeo          #+#    #+#             */
/*   Updated: 2015/01/27 18:14:59 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int num)
{
	int		ret = 0;

	if (num < 0)
	{
		ft_putchar('-');
		if (num == -2147483648)
			ret = 1;
		num = (num + ret) * (-1);
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr((num % 10) + ret);
	}
	else
		ft_putchar(num + 48);
}
