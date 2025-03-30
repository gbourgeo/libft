/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parameter_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 07:20:03 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/02/20 21:33:10 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void pf_parameter_table_debug(t_dyntab *parameters)
{
    t_param *param = NULL;
    ssize_t  iter  = 0;
    ssize_t last_recovered_parameter_pos = parameters->len;

    while (last_recovered_parameter_pos > 0)
    {
        param = (t_param *) parameters->table + last_recovered_parameter_pos - 1;
        if (param->status == PRINTF_PARAMETER_RECOVERED)
        {
            break;
        }
        last_recovered_parameter_pos--;
    }
    (void) write(STDOUT_FILENO, "\n\e[34m** PARAMETERS\n", 21);
    (void) write(STDOUT_FILENO, "Position | Status | Value\n", 27);
    while (iter < last_recovered_parameter_pos)
    {
        param = (t_param *) parameters->table + iter;
        write(STDOUT_FILENO, "#", 1);
        ft_putnbr((int) iter);
        write(STDOUT_FILENO, " | ", 3);
        if (param->status == PRINTF_PARAMETER_NOT_RECOVERED)
        {
            write(STDOUT_FILENO, "Not recovered\n", 15);
        }
        else if (param->status == PRINTF_PARAMETER_RECOVERED)
        {
            write(STDOUT_FILENO, "Recovered | ", 13);
            ft_putnbr((int) param->value);
            write(STDOUT_FILENO, "\n", 1);
        }
        iter++;
    }
    (void) write(STDOUT_FILENO, "\e[0m", 5);
}

void pf_parameter_table_free(t_dyntab *parameters)
{
    free(parameters->table);
}

int pf_parameter_table_init(t_dyntab *parameters)
{
    size_t iter = 0;

    parameters->table = (t_param *) malloc(sizeof(t_param) * PRELOAD_CONVERSION_NB);
    if (parameters->table == NULL)
    {
        return (1);
    }
    while (iter < PRELOAD_CONVERSION_NB)
    {
        pf_parameter_init((t_param *) parameters->table + iter);
        iter++;
    }
    parameters->pos = 0;
    parameters->len = PRELOAD_CONVERSION_NB;
    return (0);
}

void pf_parameter_init(void *parameter)
{
    t_param *param = parameter;

    param->value  = 0;
    param->status = PRINTF_PARAMETER_NOT_RECOVERED;
}

t_param *pf_parameter_new(t_dyntab *parameters)
{
    t_param *param = NULL;

    if (pf_data_dyn_table_check(parameters, sizeof(t_param), pf_parameter_init) != 0)
    {
        return (NULL);
    }
    /* Récupération du paramètre */
    param = (t_param *) parameters->table + parameters->pos;
    /* Incrément de la position à l'élément suivant dans le tableau pour les prochains appels */
    parameters->pos++;
    return (param);
}
