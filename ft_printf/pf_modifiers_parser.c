/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_modifiers_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:20:03 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:33:10 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "ft_constants.h"
#include "ft_routine_printf.h"
#include "libft.h"
#include <stddef.h>
#include <stdint.h>

static int pf_atoi(t_data *data)
{
    int res = 0;

    while (*data->head != '\0' && ft_isdigit(*data->head) != 0)
    {
        res = res * 10;
        res = res + *data->head - '0';
        data->head++;
    }
    return (res);
}

static int printf_flag_hash(t_data *data, t_conv **conversion)
{
    ASSIGN_BIT((*conversion)->flags.bits, PRINTF_FLAG_HASH);
    data->head++;
    return (0);
}

static int printf_flag_minus(t_data *data, t_conv **conversion)
{
    ASSIGN_BIT((*conversion)->flags.bits, PRINTF_FLAG_MINUS);
    data->head++;
    return (0);
}

static int printf_flag_plus(t_data *data, t_conv **conversion)
{
    ASSIGN_BIT((*conversion)->flags.bits, PRINTF_FLAG_PLUS);
    data->head++;
    return (0);
}

static int printf_flag_space(t_data *data, t_conv **conversion)
{
    ASSIGN_BIT((*conversion)->flags.bits, PRINTF_FLAG_SPACE);
    data->head++;
    return (0);
}

static int printf_flag_zero(t_data *data, t_conv **conversion)
{
    ASSIGN_BIT((*conversion)->flags.bits, PRINTF_FLAG_ZERO);
    data->head++;
    return (0);
}

static int printf_flag_star(t_data *data, t_conv **conversion)
{
    t_conv *new_conversion = NULL;

    ASSIGN_BIT((*conversion)->flags.bits, PRINTF_FLAG_STAR);
    (*conversion)->result = va_arg(data->ap, int);
    if (!TEST_BIT((*conversion)->flags.bits, PRINTF_FLAG_DOT))
    {
        (*conversion)->type            = PRINTF_CONV_LENGTH_MODIFIER;
        (*conversion)->flags.min_width = (long) (*conversion)->result;
        if ((*conversion)->flags.min_width < 0)
        {
            REMOVE_BIT((*conversion)->flags.bits, (uint32_t) PRINTF_FLAG_ZERO);
            ASSIGN_BIT((*conversion)->flags.bits, PRINTF_FLAG_MINUS);
            (*conversion)->flags.min_width = -(*conversion)->flags.min_width;
        }
    }
    else
    {
        (*conversion)->type            = PRINTF_CONV_PRECISION;
        (*conversion)->flags.precision = (long) (*conversion)->result;
        if ((*conversion)->flags.precision < 0)
        {
            REMOVE_BIT((*conversion)->flags.bits, (uint32_t) PRINTF_FLAG_DOT);
            REMOVE_BIT((*conversion)->flags.bits, (uint32_t) PRINTF_FLAG_STAR);
            (*conversion)->flags.precision = 0;
        }
    }
    data->head++;
    (*conversion)->head = data->head;
    new_conversion      = pf_data_get_next_conversion(data, (*conversion)->tail, data->head);
    if (new_conversion == NULL)
    {
        return (-1);
    }
    *conversion = new_conversion;
    return (0);
}

static int printf_flag_dot(t_data *data, t_conv **conversion)
{
    ASSIGN_BIT((*conversion)->flags.bits, PRINTF_FLAG_DOT);
    data->head++;
    return (0);
}

static int printf_flag_is_digit(t_data *data, t_conv **conversion)
{
    if (!TEST_BIT((*conversion)->flags.bits, PRINTF_FLAG_DOT))
    {
        (*conversion)->flags.min_width = pf_atoi(data);
    }
    else
    {
        (*conversion)->flags.precision = pf_atoi(data);
        if ((*conversion)->flags.precision < 0)
        {
            REMOVE_BIT((*conversion)->flags.bits, (uint32_t) PRINTF_FLAG_DOT);
            (*conversion)->flags.precision = 0;
        }
    }
    return (0);
}

static int printf_length_h(t_data *data, t_conv **conversion)
{
    if (!TEST_BIT((*conversion)->flags.bits, PRINTF_LENGTH_H))
    {
        ASSIGN_BIT((*conversion)->flags.bits, PRINTF_LENGTH_H);
    }
    else
    {
        ASSIGN_BIT((*conversion)->flags.bits, PRINTF_LENGTH_HH);
    }
    data->head++;
    return (0);
}

static int printf_length_l(t_data *data, t_conv **conversion)
{
    if (!TEST_BIT((*conversion)->flags.bits, PRINTF_LENGTH_L))
    {
        ASSIGN_BIT((*conversion)->flags.bits, PRINTF_LENGTH_L);
    }
    else
    {
        ASSIGN_BIT((*conversion)->flags.bits, PRINTF_LENGTH_LL);
    }
    data->head++;
    return (0);
}

static int printf_length_j(t_data *data, t_conv **conversion)
{
    ASSIGN_BIT((*conversion)->flags.bits, PRINTF_LENGTH_J);
    data->head++;
    return (0);
}

static int printf_length_z(t_data *data, t_conv **conversion)
{
    ASSIGN_BIT((*conversion)->flags.bits, PRINTF_LENGTH_Z);
    data->head++;
    return (0);
}

static inline ssize_t pf_abs(ssize_t value)
{
    return ((value < 0) ? -value : value);
}

static int printf_conv_position(t_data *data, t_conv **conversion)
{
    t_conv *new_conv = NULL;
    ssize_t real_pos = pf_abs((*conversion)->flags.min_width);

    /* Reset du min_width */
    (*conversion)->flags.min_width = 0;
    /* Erreur */
    if (real_pos == 0)
    {
        data->head -= 1;
        return (-1);
    }
    data->head++;
    while (data->conversion_pos < real_pos - 1)
    {
        new_conv = pf_data_get_next_conversion(data, NULL, NULL);
        if (new_conv->type == PRINTF_CONV_NONE)
        {
            new_conv->type   = PRINTF_CONV_UNIDENTIFIED;
            new_conv->tail   = NULL;
            new_conv->head   = NULL;
            new_conv->result = va_arg(data->ap, unsigned long long);
        }
    }
    data->conversion_pos = real_pos - 1;
    new_conv             = pf_data_get_next_conversion(data, (*conversion)->tail, data->head);
    pf_conv_init(*conversion);
    *conversion = new_conv;
    return (0);
}

int pf_parse_conversion_modifiers(t_data *data, t_conv **conversion)
{
    static t_specifier flags[] = {
        { PRINTF_FLAG_IS_A_CHARACTER, "#",        printf_flag_hash     },
        { PRINTF_FLAG_IS_A_CHARACTER, "-",        printf_flag_minus    },
        { PRINTF_FLAG_IS_A_CHARACTER, "+",        printf_flag_plus     },
        { PRINTF_FLAG_IS_A_CHARACTER, " ",        printf_flag_space    },
        { PRINTF_FLAG_IS_A_CHARACTER, "0",        printf_flag_zero     },
        { PRINTF_FLAG_IS_A_CHARACTER, "*",        printf_flag_star     },
        { PRINTF_FLAG_IS_A_CHARACTER, ".",        printf_flag_dot      },
        { PRINTF_FLAG_IS_A_FUNCTION,  ft_isdigit, printf_flag_is_digit },
        { PRINTF_FLAG_IS_A_CHARACTER, "h",        printf_length_h      },
        { PRINTF_FLAG_IS_A_CHARACTER, "l",        printf_length_l      },
        { PRINTF_FLAG_IS_A_CHARACTER, "j",        printf_length_j      },
        { PRINTF_FLAG_IS_A_CHARACTER, "z",        printf_length_z      },
        { PRINTF_FLAG_IS_A_CHARACTER, "$",        printf_conv_position },
    };
    size_t iter = 0;
    int    ret  = 0;

    data->head++;
    while (iter < LENGTH_OF(flags) && *data->head != '\0' && ret == 0)
    {
        iter = 0;
        while (iter < LENGTH_OF(flags))
        {
            if ((flags[iter].identity == PRINTF_FLAG_IS_A_CHARACTER
                 && *data->head == *(char *) flags[iter].identifier)
                || (flags[iter].identity == PRINTF_FLAG_IS_A_FUNCTION
                    && ((t_fnc_ptr *) flags[iter].identifier)(*data->head) != 0))
            {
                ret = flags[iter].handler(data, conversion);
                break;
            }
            iter++;
        }
    }
    return (ret);
}
