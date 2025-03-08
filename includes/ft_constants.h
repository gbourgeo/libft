/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constants.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:28:18 by gbourgeo          #+#    #+#             */
/*   Updated: 2025/01/26 13:04:46 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONSTANTS_H
# define FT_CONSTANTS_H

# ifndef _pack
# define _pack __attribute__((packed))
# endif

# ifndef _align
#  define _align(size) __attribute__((aligned(size)))
# endif

# ifndef _unused
#  define _unused __attribute__((__unused__))
# endif

# ifndef LENGTH_OF
#  define LENGTH_OF(table) (sizeof(table) / sizeof((table)[0]))
# endif

# ifndef TEST_BIT
#  define TEST_BIT(storage, bit) ((storage) & (unsigned int)(bit))
# endif

# ifndef ASSIGN_BIT
#  define ASSIGN_BIT(storage, bit) ((storage) |= (unsigned int)(bit))
# endif

# ifndef REMOVE_BIT
#  define REMOVE_BIT(storage, bit) ((storage) &= ~(bit))
# endif

# endif /* FT_CONSTANTS_H */
