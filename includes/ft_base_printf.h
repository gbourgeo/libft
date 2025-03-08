/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_printf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:20:27 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:39:00 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE_PRINTF_H
#define FT_BASE_PRINTF_H

#include "ft_constants.h"
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define PRELOAD_CONVERSION_NB 10

typedef enum e_printf_output
{
    PRINTF_OUTPUT_FILE_DESCRIPTOR = 0,
    PRINTF_OUTPUT_FILE_STREAM     = 1,
    PRINTF_OUTPUT_BUFFER          = 2,
} e_output;

typedef enum e_printf_conversion_identity
{
    PRINTF_CONV_NONE            = 0,
    PRINTF_CONV_UNIDENTIFIED    = 1,
    PRINTF_CONV_LENGTH_MODIFIER = 2,
    PRINTF_CONV_PRECISION       = 3,
    PRINTF_CONV_CONVERTER       = 4,
} e_conv;

typedef struct _align(32) s_printf_family_buffer_output
{
    char  *str;  // Buffer de sortie pour snprintf, sprintf, etc.
    size_t pos;  // dernière position d'écriture.
    size_t size; // Taille du buffer.
} t_buffer;

typedef union
{
    t_buffer buff;   // La sortie est un buffer
    FILE    *stream; // La sortie est un stream
    int      fd;     // La sortie est un file descriptor
} u_output;

typedef struct _align(32) s_flag
{
    uint16_t bits;      // Bits de modification de longueur et de précision
    ssize_t  min_width; // '*' ou digit après '%'
    ssize_t  precision; // '*' ou digits après '.'
} t_flag;

typedef struct _align(128) s_conversion_specification_table
{
    e_conv             type;        // Type de conversion
    const char        *tail;        // Pointeur de début de la conversion ('%...')
    const char        *head;        // Pointeur de fin de la conversion
    t_flag             flags;       // Flags de modification
    unsigned long long result;      // Résultat fourni en paramètre
    char              *converted;   // Résultat converti en string
    ssize_t            pos;         // Position d'écriture dans le buffer
    ssize_t            len;         // Taille du buffer
    int                error_found; // Erreur trouvée lors d'une conversion
} t_conv;

typedef struct _align(128) s_print_family_data
{
    e_output    family;           // Type de printf appelant (utilisé pour l'union)
    u_output    output;           // Type de sortie (fd, stream, buffer)
    const char *tail;             // Pointeur de début de format
    const char *head;             // Pointeur de fin de format
    va_list     ap;               // Stdargs
    t_conv     *conversion_table; // Tableau des résultats de conversion
    ssize_t     conversion_pos;   // Position sur l'élément suivant du tableau de conversion
    ssize_t     conversion_len;   // Longueur tableau de conversion
} t_data;

int     pf_data_init(t_data     *data,
                     e_output    family,
                     u_output    output,
                     const char *format);
void    pf_data_clean(t_data *data);
t_conv *pf_data_get_next_conversion(t_data *data, const char *tail, const char *head);
t_conv *pf_conv_get_next_converter(t_data *data, ssize_t *pos);
void    pf_conv_init(t_conv *conversion);
void    pf_conv_merge_modifiers(t_data *data, t_conv *conversion);
int     pf_conv_new_result(t_conv *conversion, ssize_t len);
void    pf_conv_nwrite_char(t_conv *conversion, uint8_t chr, ssize_t ntimes);
void    pf_conv_nwrite_char_unverified(t_conv *conversion, uint8_t chr, ssize_t ntimes);
void    pf_conv_nwrite_str(t_conv *conversion, const char *str, ssize_t len);
void    pf_conv_nwrite_wstr(t_conv *conversion, const wchar_t *src, ssize_t len);
void    pf_conv_write_wchar(t_conv *conversion, wchar_t src);
int     pf_parse_conversion_modifiers(t_data *data, t_conv **conversion);
int     pf_parse_conversion_specifiers(t_data *data, t_conv *conversion);
int     pf_routine(t_data *data);
ssize_t pf_output(t_data *data);
ssize_t pf_wcharlen(wchar_t src);
ssize_t pf_wstrlen(const wchar_t *src);

ssize_t pf_c_big(t_data *data, t_conv *conversion);
ssize_t pf_c_small(t_data *data, t_conv *conversion);
ssize_t pf_di(t_data *data, t_conv *conversion);
ssize_t pf_o(t_data *data, t_conv *conversion);
ssize_t pf_p(t_data *data, t_conv *conversion);
ssize_t pf_percent(t_data *data, t_conv *conversion);
ssize_t pf_s_big(t_data *data, t_conv *conversion);
ssize_t pf_s_small(t_data *data, t_conv *conversion);
ssize_t pf_u(t_data *data, t_conv *conversion);
ssize_t pf_x_big(t_data *data, t_conv *conversion);
ssize_t pf_x_small(t_data *data, t_conv *conversion);

unsigned long long get_x_modifier(t_data *data, t_conv *conversion, char **src);

void compute_zeros_and_spaces(t_conv  *conversion,
                              ssize_t  result_len,
                              ssize_t  prefix_len,
                              ssize_t *zeros,
                              ssize_t *spaces);
void pre_write_modifiers(t_conv     *conversion,
                         ssize_t     zeros,
                         ssize_t     spaces,
                         const char *src,
                         ssize_t     len,
                         const char *prefix);
void post_write_modifiers(t_conv     *conversion,
                          ssize_t     zeros,
                          ssize_t     spaces,
                          const char *src,
                          ssize_t     len,
                          const char *prefix);

#endif
