/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_printf.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:20:27 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:39:00 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROUTINE_PRINTF_H
#define FT_ROUTINE_PRINTF_H

#include "ft_base_printf.h"
#include "ft_constants.h"

/**
 * @brief Identifiant du modificateur
 */
typedef enum
{
    PRINTF_FLAG_IS_A_CHARACTER = 0,
    PRINTF_FLAG_IS_A_FUNCTION,
} t_fidentifier;

/**
 * @brief Enuméré pour bit de modification (flags.bit)
 */
enum
{
    PRINTF_FLAG_NONE  = 0x0000, // 00000000 00000000
    PRINTF_FLAG_HASH  = 0x0001, // 00000000 00000001
    PRINTF_FLAG_MINUS = 0x0002, // 00000000 00000010
    PRINTF_FLAG_PLUS  = 0x0004, // 00000000 00000100
    PRINTF_FLAG_SPACE = 0x0008, // 00000000 00001000
    PRINTF_FLAG_ZERO  = 0x0010, // 00000000 00010000
    PRINTF_FLAG_STAR  = 0x0020, // 00000000 00100000
    PRINTF_FLAG_DOT   = 0x0040, // 00000000 01000000
    PRINTF_LENGTH_H   = 0x0080, // 00000000 10000000
    PRINTF_LENGTH_HH  = 0x0100, // 00000001 00000000
    PRINTF_LENGTH_L   = 0x0200, // 00000010 00000000
    PRINTF_LENGTH_LL  = 0x0400, // 00000100 00000000
    PRINTF_LENGTH_J   = 0x0800, // 00001000 00000000
    PRINTF_LENGTH_Z   = 0x1000, // 00010000 00000000
};

/**
 * @brief Structure des caractères de conversion supportés. Contient:
 *
 * - char : Caractère de conversion
 *
 * - ssize_t (*)(t_data *, t_conv *) : Fonction de gestion du caractère
 */
typedef struct _align(16) s_specifier_handler
{
    char    character;                                 // Caractère reconnu comme conversion
    ssize_t (*handler)(t_data *, t_param *, t_conv *); // Fonction de gestion du caractère
} t_spec_hdlr;

/**
 * @brief Structure des spécificateurs supportés. Contient:
 *
 * - t_identifier                 : Identité (caractère ou fonction)
 *
 * - void *                       : Valeur
 *
 * - int (*)(t_data *, t_conv *)  : Fonction de gestion du spécficateur
 */
typedef struct _align(32) s_modifier_handler
{
    t_fidentifier identity;                       // Type de spécificateur
    void         *identifier;                     // Nom/Fonction du spécificateur (#, -, +, *, etc.)
    int           (*handler)(t_data *, t_conv *); // Fonction de gestion de l'identifieur
} t_modif_hdlr;

typedef int t_fnc_ptr(int);

#endif /* FT_ROUTINE_PRINTF_H */
