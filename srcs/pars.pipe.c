/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:26:40 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/07 03:10:02 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int pars_pipe(t_data *dta)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(dta->cmd2);
    if (len > 0)
    {
        if(dta->cmd2[len] == '\0' && dta->cmd2[--len] == '|')
        {
            printf("le premier --");
            printf("Syntax error: unexpected end of command '|'\n");
            return (1);
        }
        while(is_sep(dta->cmd2[len]) == 1)
        {
            len--;
        }
        if (dta->cmd2[len] == '|')
        {
            printf("le deuxieme --");
            printf("Syntax error: unexpected end of command '|'\n");
            return (1);
        }
    }
    while(is_sep(dta->cmd2[i]) == 1)
        i++;
    if (dta->cmd2[i] == '|')
    {
        printf("fisrt arg en +");
        printf("Syntax error near unexpected token `|'\n");
        return (1);
    }
    while(dta->cmd2[i])
    {
        if (dta->cmd2[i] == '|' && dta->cmd2[i + 1] == '|')
        {
            printf("deux || daffile");
            printf("Syntax error near unexpected token `|'\n");
            return (1);
        }
        i++;
    }
    free(dta->cmd2);
    return (0);
}