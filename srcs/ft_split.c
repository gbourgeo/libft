/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 20:05:34 by gbourgeo          #+#    #+#             */
/*   Updated: 2016/04/21 17:58:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_chr_len(const char *str, const char *charset)
{
	size_t		len = 0;

	while (str[len] != '\0'
		&& ft_strchr(charset, str[len]) != NULL)
	{
		++len;
	}
	return (len);
}

static size_t	get_line_len(const char *str, const char *charset)
{
	size_t		len = 0;

	while (str[len] != '\0'
		&& ft_strchr(charset, str[len]) == NULL)
	{
		++len;
	}
	return (len);
}

static size_t	get_table_len(const char *str, const char *charset)
{
	size_t	iter = 0;
	size_t	lines = 0;

	if (str != NULL)
	{
		while (str[iter] != '\0')
		{
			iter += get_chr_len(str + iter, charset);
			lines += (str[iter] != '\0');
			iter += get_line_len(str + iter, charset);
		}
	}
	return (lines);
}

char		**ft_split(const char *str, const char *charset)
{
	char	**table = NULL;
	size_t	table_len = 0;
	size_t	table_i = 0;
	size_t	str_len = 0;
	size_t	str_i = 0;

	table_len = get_table_len(str, charset);
	table = (char **)malloc(sizeof(*table) * (table_len + 1));
	if (table != NULL)
	{
		while (table_i < table_len)
		{
			str_i += get_chr_len(str + str_i, charset);
			str_len = get_line_len(str + str_i, charset);
			table[table_i] = ft_strsub(str, str_i, str_len);
			if (table[table_i] == NULL)
			{
				break;
			}
			str_i += str_len;
			++table_i;
		}
		table[table_i] = NULL;
	}
	return (table);
}
