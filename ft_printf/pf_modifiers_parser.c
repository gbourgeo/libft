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

static int printf_flag_hash(t_data _unused *data, t_conv *conv)
{
    ASSIGN_BIT(conv->flags.bits, PRINTF_FLAG_HASH);
    return (0);
}

static int printf_flag_minus(t_data _unused *data, t_conv *conv)
{
    ASSIGN_BIT(conv->flags.bits, PRINTF_FLAG_MINUS);
    return (0);
}

static int printf_flag_plus(t_data _unused *data, t_conv *conv)
{
    ASSIGN_BIT(conv->flags.bits, PRINTF_FLAG_PLUS);
    return (0);
}

static int printf_flag_space(t_data _unused *data, t_conv *conv)
{
    ASSIGN_BIT(conv->flags.bits, PRINTF_FLAG_SPACE);
    return (0);
}

static int printf_flag_zero(t_data _unused *data, t_conv *conv)
{
    ASSIGN_BIT(conv->flags.bits, PRINTF_FLAG_ZERO);
    return (0);
}

static int printf_flag_star(t_data *data, t_conv *conv)
{
    t_param *param = pf_parameter_new(&data->parameters);

    ASSIGN_BIT(conv->flags.bits, PRINTF_FLAG_STAR);
    param->value = va_arg(data->ap, int);
    if (!TEST_BIT(conv->flags.bits, PRINTF_FLAG_DOT))
    {
        param->status         = PRINTF_PARAMETER_RECOVERED;
        conv->flags.min_width = (long) param->value;
        if (conv->flags.min_width < 0)
        {
            REMOVE_BIT(conv->flags.bits, (uint32_t) PRINTF_FLAG_ZERO);
            ASSIGN_BIT(conv->flags.bits, PRINTF_FLAG_MINUS);
            conv->flags.min_width = -conv->flags.min_width;
        }
    }
    else
    {
        param->status         = PRINTF_PARAMETER_RECOVERED;
        conv->flags.precision = (long) param->value;
        if (conv->flags.precision < 0)
        {
            REMOVE_BIT(conv->flags.bits, (uint32_t) PRINTF_FLAG_DOT);
            REMOVE_BIT(conv->flags.bits, (uint32_t) PRINTF_FLAG_STAR);
            conv->flags.precision = 0;
        }
    }
    return (0);
}

static int printf_flag_dot(t_data _unused *data, t_conv *conv)
{
    ASSIGN_BIT(conv->flags.bits, PRINTF_FLAG_DOT);
    return (0);
}

static int printf_flag_is_digit(t_data *data, t_conv *conv)
{
    if (!TEST_BIT(conv->flags.bits, PRINTF_FLAG_DOT))
    {
        conv->flags.min_width = ft_atol(data->head);
    }
    else
    {
        conv->flags.precision = ft_atol(data->head);
        if (conv->flags.precision < 0)
        {
            REMOVE_BIT(conv->flags.bits, (uint32_t) PRINTF_FLAG_DOT);
            conv->flags.precision = 0;
        }
    }
    while (ft_isdigit(*(data->head + 1)) != 0)
    {
        data->head++;
    }
    return (0);
}

static int printf_length_h(t_data _unused *data, t_conv *conv)
{
    if (!TEST_BIT(conv->flags.bits, PRINTF_LENGTH_H))
    {
        ASSIGN_BIT(conv->flags.bits, PRINTF_LENGTH_H);
    }
    else
    {
        ASSIGN_BIT(conv->flags.bits, PRINTF_LENGTH_HH);
        REMOVE_BIT(conv->flags.bits, PRINTF_LENGTH_H);
    }
    return (0);
}

static int printf_length_l(t_data _unused *data, t_conv *conv)
{
    if (!TEST_BIT(conv->flags.bits, PRINTF_LENGTH_L))
    {
        ASSIGN_BIT(conv->flags.bits, PRINTF_LENGTH_L);
    }
    else
    {
        ASSIGN_BIT(conv->flags.bits, PRINTF_LENGTH_LL);
        REMOVE_BIT(conv->flags.bits, PRINTF_LENGTH_L);
    }
    return (0);
}

static int printf_length_j(t_data _unused *data, t_conv *conv)
{
    ASSIGN_BIT(conv->flags.bits, PRINTF_LENGTH_J);
    return (0);
}

static int printf_length_z(t_data _unused *data, t_conv *conv)
{
    ASSIGN_BIT(conv->flags.bits, PRINTF_LENGTH_Z);
    return (0);
}

static inline ssize_t pf_abs(ssize_t value)
{
    return ((value < 0) ? -value : value);
}

static int printf_param_position(t_data *data, t_conv *conv)
{
    t_param *param       = NULL;
    ssize_t  asked_pos   = pf_abs(conv->flags.min_width) - 1;
    ssize_t  current_pos = data->parameters.pos - 1;

    /* Reset du min_width */
    conv->flags.min_width = 0;
    if (asked_pos < 0)
    {
        return (-1);
    }
    /* Boucle sur les arguments jusqu'à la position demandée */
    while (current_pos < asked_pos)
    {
        param = pf_parameter_new(&data->parameters);
        if (param->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            param->value  = va_arg(data->ap, unsigned long long);
            param->status = PRINTF_PARAMETER_RECOVERED;
        }
        current_pos++;
    }
    data->parameters.pos = asked_pos;
    return (0);
}

int pf_parse_modifiers(t_data *data, t_conv *conv)
{
    static t_modif_hdlr flags[] = {
        { PRINTF_FLAG_IS_A_CHARACTER, "#",        printf_flag_hash      },
        { PRINTF_FLAG_IS_A_CHARACTER, "-",        printf_flag_minus     },
        { PRINTF_FLAG_IS_A_CHARACTER, "+",        printf_flag_plus      },
        { PRINTF_FLAG_IS_A_CHARACTER, " ",        printf_flag_space     },
        { PRINTF_FLAG_IS_A_CHARACTER, "0",        printf_flag_zero      },
        { PRINTF_FLAG_IS_A_CHARACTER, "*",        printf_flag_star      },
        { PRINTF_FLAG_IS_A_CHARACTER, ".",        printf_flag_dot       },
        { PRINTF_FLAG_IS_A_FUNCTION,  ft_isdigit, printf_flag_is_digit  },
        { PRINTF_FLAG_IS_A_CHARACTER, "h",        printf_length_h       },
        { PRINTF_FLAG_IS_A_CHARACTER, "l",        printf_length_l       },
        { PRINTF_FLAG_IS_A_CHARACTER, "j",        printf_length_j       },
        { PRINTF_FLAG_IS_A_CHARACTER, "z",        printf_length_z       },
        { PRINTF_FLAG_IS_A_CHARACTER, "$",        printf_param_position },
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
                ret = flags[iter].handler(data, conv);
                data->head++;
                break;
            }
            iter++;
        }
    }
    return (ret);
}
