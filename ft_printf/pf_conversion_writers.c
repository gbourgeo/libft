/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conversion_writers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:20:03 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:33:10 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include <stddef.h>
#include <stdint.h>
#include <wchar.h>

void pf_conv_nwrite_char(t_conv *conversion, uint8_t chr, ssize_t ntimes)
{
    if (chr > 0)
    {
        while (conversion->pos < conversion->len
               && ntimes > 0)
        {
            conversion->value[conversion->pos] = (char) chr;
            conversion->pos++;
            ntimes--;
        }
    }
}

void pf_conv_nwrite_char_unverified(t_conv *conversion, uint8_t chr, ssize_t ntimes)
{
    while (conversion->pos < conversion->len
           && ntimes > 0)
    {
        conversion->value[conversion->pos] = (char) chr;
        conversion->pos++;
        ntimes--;
    }
}

void pf_conv_nwrite_str(t_conv *conversion, const char *str, ssize_t len)
{
    if (str != NULL)
    {
        while (conversion->pos < conversion->len
               && *str != '\0'
               && len > 0)
        {
            conversion->value[conversion->pos] = *str;
            conversion->pos++;
            str++;
            len--;
        }
    }
}

void pf_conv_write_wchar(t_conv *conversion, wchar_t src)
{
    uint32_t code = src;

    if (code < 0x80)
    {
        conversion->value[conversion->pos++] = (char) code;
    }
    else if (code < 0x800) // 00000yyy yyxxxxxx
    {
        if (conversion->pos + 2 > conversion->len)
        {
            conversion->error_found = 1;
        }
        else
        {
            conversion->value[conversion->pos++] = (char) ((uint32_t) 0b11000000 | (code >> (uint32_t) 6));
            conversion->value[conversion->pos++] = (char) ((uint32_t) 0b10000000 | (code & (uint32_t) 0x3f));
        }
    }
    else if (code < 0x10000) // zzzzyyyy yyxxxxxx
    {
        if (conversion->pos + 3 > conversion->len)
        {
            conversion->error_found = 1;
        }
        else
        {
            conversion->value[conversion->pos++] = (char) ((uint32_t) 0b11100000 | (code >> (uint32_t) 12));                    // 1110zzz
            conversion->value[conversion->pos++] = (char) ((uint32_t) 0b10000000 | ((code >> (uint32_t) 6) & (uint32_t) 0x3f)); // 10yyyyy
            conversion->value[conversion->pos++] = (char) ((uint32_t) 0b10000000 | (code & (uint32_t) 0x3f));                   // 10xxxxx
        }
    }
    else if (code < 0x200000) // 000uuuuu zzzzyyyy yyxxxxxx
    {
        if (conversion->pos + 4 > conversion->len)
        {
            conversion->error_found = 1;
        }
        else
        {
            conversion->value[conversion->pos++] = (char) ((uint32_t) 0b11110000 | (code >> (uint32_t) 18));                     // 11110uuu
            conversion->value[conversion->pos++] = (char) ((uint32_t) 0b10000000 | ((code >> (uint32_t) 12) & (uint32_t) 0x3f)); // 10uuzzzz
            conversion->value[conversion->pos++] = (char) ((uint32_t) 0b10000000 | ((code >> (uint32_t) 6) & (uint32_t) 0x3f));  // 10yyyyyy
            conversion->value[conversion->pos++] = (char) ((uint32_t) 0b10000000 | (code & (uint32_t) 0x3f));                    // 10xxxxxx
        }
    }
    else
    {
        conversion->error_found = 1;
    }
}

void pf_conv_nwrite_wstr(t_conv *conversion, const wchar_t *src, ssize_t len)
{
    ssize_t iter = 0;

    if (src != NULL)
    {
        while (conversion->pos < conversion->len
               && src[iter] != 0
               && iter < len)
        {
            pf_conv_write_wchar(conversion, src[iter]);
            iter++;
        }
    }
}
