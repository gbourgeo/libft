/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 22:15:29 by gbourgeo          #+#    #+#             */
/*   Updated: 2016/04/21 17:41:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "ft_defines.h"

enum
{
    GNL_BUFF_SIZE = 8
};

typedef struct _align(32) s_gnl
{
    int           fd;
    char         *copy;
    struct s_gnl *next;
    struct s_gnl *prev;
} t_gnl;

int get_next_line(int filed, char **line);

#endif
