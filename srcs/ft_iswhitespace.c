/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 02:11:55 by gbourgeo          #+#    #+#             */
/*   Updated: 2017/03/30 22:53:11 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_iswhitespace(char chr)
{
	return (chr == ' ' || (chr >= 9 && chr <= 11));
}
