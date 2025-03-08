/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 23:26:48 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/04/05 06:25:37 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void gnl_free(t_gnl *tmp, t_gnl **gnl)
{
    if (tmp->copy)
    {
        free(tmp->copy);
    }
    tmp->copy = NULL;
    if (tmp->next != NULL)
    {
        tmp->next->prev = tmp->prev;
    }
    if (tmp->prev != NULL)
    {
        tmp->prev->next = tmp->next;
    }
    else
    {
        *gnl = tmp->next;
    }
    free(tmp);
    tmp = NULL;
}

static int analyse_line(char **line, t_gnl *tmp, t_gnl **gnl)
{
    char *ptr = NULL;

    ptr = ft_strjoin(tmp->copy, *line);
    if (tmp->copy)
    {
        free(tmp->copy);
    }
    tmp->copy = ptr;
	ptr = ft_strchr(tmp->copy, '\n');
    if (ptr == NULL)
    {
        return (0);
    }
    *ptr = '\0';
    free(*line);
    *line = ft_strdup(tmp->copy);
    if (*(ptr + 1))
    {
        ptr = ft_strdup(ptr + 1);
        free(tmp->copy);
        tmp->copy = ptr;
    }
    else
    {
        gnl_free(tmp, gnl);
    }
    return (1);
}

static int create_line(const int filed, char **line, t_gnl *tmp, t_gnl **gnl)
{
    ssize_t ret = 0;

    *line = ft_strnew(GNL_BUFF_SIZE + 1);
    if (*line == NULL)
    {
        return (-1);
    }
    if (tmp->copy && (analyse_line(line, tmp, gnl)) == 1)
    {
        return (1);
    }
    while (1)
    {
        ret = read(filed, *line, GNL_BUFF_SIZE);
        if (ret <= 0)
        {
            break;
        }
        if ((analyse_line(line, tmp, gnl)) == 1)
        {
            return (1);
        }
        ft_bzero(*line, GNL_BUFF_SIZE + 1);
    }
    free(*line);
    *line = ft_strdup(tmp->copy);
    gnl_free(tmp, gnl);
    return ((*line) ? 1 : 0);
}

static int check_struct(int filed, char **line, t_gnl **gnl)
{
    t_gnl *tmp = *gnl;

    while (tmp->fd != filed && tmp->next)
    {
        tmp = tmp->next;
    }
    if (tmp->fd == filed)
    {
        return (create_line(filed, line, tmp, gnl));
    }
    tmp->next = malloc(sizeof(*tmp));
    if (tmp->next == NULL)
    {
        return (-1);
    }
    tmp->next->fd   = filed;
    tmp->next->copy = NULL;
    tmp->next->next = NULL;
    tmp->next->prev = tmp;
    return (create_line(filed, line, tmp->next, gnl));
}

int get_next_line(int filed, char **line)
{
    static t_gnl *gnl = NULL;

    if (filed >= 0 && line != NULL && GNL_BUFF_SIZE > 0)
    {
        if (gnl == NULL)
        {
            gnl = malloc(sizeof(*gnl));
            if (gnl == NULL)
            {
                return (-1);
            }
            gnl->fd   = filed;
            gnl->copy = NULL;
            gnl->next = NULL;
            gnl->prev = NULL;
            return (create_line(filed, line, gnl, &gnl));
        }
        return (check_struct(filed, line, &gnl));
    }
    return (-1);
}
