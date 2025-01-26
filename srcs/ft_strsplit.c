/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 00:58:36 by gbourgeo          #+#    #+#             */
/*   Updated: 2014/03/27 19:29:35 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_chr_len(const char *str, char chr)
{
	size_t		len = 0;

	while (str[len] == chr && str[len] != '\0')
	{
		++len;
	}
	return (len);
}

static size_t	get_line_len(const char *str, char chr)
{
	size_t		len = 0;

	while (str[len] != chr && str[len] != '\0')
	{
		++len;
	}
	return (len);
}

static size_t	get_table_len(const char *str, char chr)
{
	size_t	iter = 0;
	size_t	lines = 0;

	if (str != NULL)
	{
		while (str[iter] != '\0')
		{
			iter += get_chr_len(str + iter, chr);
			lines += (str[iter] != '\0');
			iter += get_line_len(str + iter, chr);
		}
	}
	return (lines);
}

char		**ft_strsplit(const char *str, char chr)
{
	char	**table = NULL;
	size_t	table_len = 0;
	size_t	table_i = 0;
	size_t	str_len = 0;
	size_t	str_i = 0;

	table_len = get_table_len(str, chr);
	table = (char **)malloc(sizeof(*table) * (table_len + 1));
	if (table != NULL)
	{
		while (table_i < table_len)
		{
			str_i += get_chr_len(str + str_i, chr);
			str_len = get_line_len(str + str_i, chr);
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
