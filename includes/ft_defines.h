/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defines.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:28:18 by gbourgeo          #+#    #+#             */
/*   Updated: 2025/01/26 13:04:46 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_DEFINES_H_
#define _FT_DEFINES_H_

#ifndef _pack
# define _pack __attribute__((packed))
#endif

#ifndef _align
# define _align(size) __attribute__((aligned(size)))
#endif

#ifndef _unused
# define _unused __attribute__((__unused__))
#endif

#ifndef LENGTH_OF
# define LENGTH_OF(table) (sizeof(table) / sizeof((table)[0]))
#endif

#ifndef TEST_BIT
# define TEST_BIT(storage, bit) ((storage) & (unsigned int) (bit))
#endif

#ifndef ASSIGN_BIT
# define ASSIGN_BIT(storage, bit) ((storage) |= (unsigned int) (bit))
#endif

#ifndef REMOVE_BIT
# define REMOVE_BIT(storage, bit) ((storage) &= ~(unsigned int) (bit))
#endif

#ifndef CLEAR_8BIT
# define CLEAR_8BIT(storage) ((storage) &= ~(unsigned char) (0xff))
#endif

#ifndef UINT32
# define UINT32(val) ((uint32_t) (val))
#endif

#endif /* _FT_DEFINES_H_ */
