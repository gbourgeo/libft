/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 19:53:48 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/03 23:09:19 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int num)
{
	char	*ptr = NULL;
	int		sign = 0;
	int		iter = 0;
	int		src = 0;

	src = num;
	iter = (num < 0 ? 3 : 2);
	while ((num /= 10))
		++iter;
	if ((ptr = (char*)malloc(sizeof(*ptr) * iter)) == NULL)
		return (NULL);
	ptr[--iter] = '\0';
	if (src == 0)
		ptr[0] = '0';
	if ((sign = (src < 0 ? -1 : 1)) < 0)
		ptr[0] = '-';
	while (src != 0)
	{
		ptr[--iter] = ((src % 10) * sign + 48);
		src /= 10;
	}
	return (ptr);
}
