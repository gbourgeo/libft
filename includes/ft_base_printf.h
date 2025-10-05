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

#include "ft_defines.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define PF_SIZEOF(type)       ((ssize_t) sizeof(type))

enum
{
    PRELOAD_CONVERSION_NB = 10
};

typedef enum e_printf_output
{
    PRINTF_OUTPUT_FILE_DESCRIPTOR = 0,
    PRINTF_OUTPUT_FILE_STREAM     = 1,
    PRINTF_OUTPUT_BUFFER          = 2,
} e_output;

typedef enum e_printf_parameter_status
{
    PRINTF_PARAMETER_NOT_RECOVERED = 0,
    PRINTF_PARAMETER_RECOVERED     = 1,
} e_param_status;

typedef struct _align(32) s_printf_family_buffer_output
{
    char  *str;  // Buffer de sortie pour snprintf, sprintf, etc.
    size_t pos;  // dernière position d'écriture.
    size_t size; // Taille du buffer.
} t_buffer;

typedef struct _align(32) s_flag
{
    uint16_t bits;      // Bits de modification de longueur et de précision
    ssize_t  min_width; // '*' ou digit après '%'
    ssize_t  precision; // '*' ou digits après '.'
} t_flag;

typedef struct _align(128) s_converted_parameter
{
    const char *tail;        // Pointeur de début ('%...')
    const char *head;        // Pointeur de fin
    t_flag      flags;       // Flags de modification (longueur, espaces, etc.)
    char       *value;       // Résultat de conversion
    ssize_t     pos;         // Position d'écriture dans le buffer
    ssize_t     len;         // Taille du buffer
    int         error_found; // Erreur trouvée lors d'une conversion
} t_conv;

typedef struct _align(16) s_param
{
    unsigned long long value;  // Valeur du paramètre
    e_param_status     status; // Type de paramètre
} t_param;

typedef struct _align(32) s_dynamic_table
{
    void   *table; // Table des paramètres
    ssize_t pos;   // Position du prochain élément disponible du tableau
    ssize_t len;   // Taille du tableau
} t_dyntab;

typedef union
{
    t_buffer buff;   // La sortie est un buffer
    FILE    *stream; // La sortie est un stream
    int      fd;     // La sortie est un file descriptor
} u_output;

typedef struct _align(128) s_print_family_data
{
    t_dyntab    parameters; // Table des paramètres fourni à ft_printf
    u_output    output;     // Type de sortie (fd, stream, buffer)
    const char *tail;       // Pointeur de début de format
    const char *head;       // Pointeur de fin de format
    ssize_t     wrote;      // Bytes écrits jusqu'à présent
    va_list     ap;         // Stdargs
    e_output    family;     // Type de printf appelant (utilisé pour l'union)
} t_data;

int  pf_data_init(t_data *data, e_output family, u_output output, const char *format);
void pf_data_clean(t_data *data);
int  pf_data_dyn_table_check(t_dyntab *dyntable, size_t elem_size, void (*elem_initialiser)(void *));

void     pf_parameter_init(void *parameter);
t_param *pf_parameter_new(t_dyntab *parameters);
void     pf_parameter_table_debug(t_dyntab *parameters);
void     pf_parameter_table_free(t_dyntab *parameters);
int      pf_parameter_table_init(t_dyntab *parameters);

void pf_conversion_free(t_conv *conversion);
void pf_conversion_init(t_conv *conversion, const char *src);
void pf_conversion_debug(t_conv *conversion);

void pf_conv_nwrite_char(t_conv *conversion, uint8_t chr, ssize_t ntimes);
void pf_conv_nwrite_char_unverified(t_conv *conversion, uint8_t chr, ssize_t ntimes);
void pf_conv_nwrite_str(t_conv *conversion, const char *str, ssize_t len);
void pf_conv_nwrite_wstr(t_conv *conversion, const wchar_t *src, ssize_t len);
void pf_conv_write_wchar(t_conv *conversion, wchar_t src);

ssize_t pf_output_conversion(t_data *data, t_conv *conversion);
ssize_t pf_output_string(t_data *data, const char *str, size_t len);
int     pf_parse_modifiers(t_data *data, t_conv *conv);
int     pf_parse_specifiers(t_data *data, t_conv *conv);
int     pf_routine(t_data *data);

ssize_t pf_c_big(t_data *data, t_param *parameter, t_conv *conversion);
ssize_t pf_c_small(t_data *data, t_param *parameter, t_conv *conversion);
ssize_t pf_di(t_data *data, t_param *parameter, t_conv *conversion);
ssize_t pf_n(t_data *data, t_param *parameter, t_conv *conversion);
ssize_t pf_o(t_data *data, t_param *parameter, t_conv *conversion);
ssize_t pf_p(t_data *data, t_param *parameter, t_conv *conversion);
ssize_t pf_s_big(t_data *data, t_param *parameter, t_conv *conversion);
ssize_t pf_s_small(t_data *data, t_param *parameter, t_conv *conversion);
ssize_t pf_u(t_data *data, t_param *parameter, t_conv *conversion);
ssize_t pf_unhandled(t_data *data, t_conv *conversion);
ssize_t pf_x(t_data *data, t_param *parameter, t_conv *conversion);
ssize_t pf_wcharlen(wchar_t src);
ssize_t pf_wstrlen(const wchar_t *src);

void compute_zeros_and_spaces(t_param *parameter,
                              t_conv  *conv,
                              ssize_t  result_len,
                              ssize_t  prefix_len,
                              ssize_t *zeros,
                              ssize_t *spaces);
void pre_convert_specifiers(t_param    *parameter,
                            t_conv     *conversion,
                            ssize_t     zeros,
                            ssize_t     spaces,
                            const char *src,
                            ssize_t     len,
                            const char *prefix);
void post_convert_specifiers(t_param    *parameter,
                             t_conv     *conversion,
                             ssize_t     zeros,
                             ssize_t     spaces,
                             const char *src,
                             ssize_t     len,
                             const char *prefix);

#endif
