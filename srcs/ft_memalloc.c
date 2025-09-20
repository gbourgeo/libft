/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 00:47:06 by gbourgeo          #+#    #+#             */
/*   Updated: 2013/12/07 19:59:24 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void *ft_memalloc(size_t size)
{
    char  *ptr  = NULL;
    size_t iter = 0;

    ptr = (char *) malloc(size);
    if (ptr == NULL)
    {
        return (NULL);
    }
    while (iter < size)
    {
        ptr[iter++] = 0;
    }
    return (void *) (ptr);
}
