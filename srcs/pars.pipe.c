/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:26:40 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/22 05:15:45 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int pars_pipe(t_data *dta)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(dta->cmd2);
    while (len > 0)
    {
        if (dta->cmd2[--len] == '|' && dta->cmd2[len + 1] == '\0')
        {
            printf("Syntax error: unexpected end of command '|'\n");
            return (1);
        }
        len--;
    }
    while (dta->cmd2[i])
    {
        if (dta->cmd2[0] == '|')
        {
            printf("Syntax error near unexpected token `|'\n");
            return (1);
        }
        if (dta->cmd2[i] == '|' && dta->cmd2[i + 1] == '|')
        {
            printf("Syntax error near unexpected token `|'\n");
            return (1);
        }
        i++;
    }
    free(dta->cmd2);
    return (0);
}