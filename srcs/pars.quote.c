/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:54:10 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/09 00:59:00 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// fonction pas utiliser a tchequer pour inserer avec env var environnement etc ... 
void replace_quote(t_data *dta)
{
    int i;
    int dq;
    int sq;

    i = -1;
    dq = -1;
    sq = -1;
     
    while (dta->cmd[++i])
    {
        if (dta->cmd[i] == 34 && dq == -1)
            dq *= -1;
        if (dta->cmd[i] == 39 && sq == -1)
            sq *= -1;
        if (dq == 1 && (dta->cmd[i] == 34 || dta->cmd[i] == '$'
                || is_sep(dta->cmd[i])))
            dta->cmd[i] *= -1;
        if (sq == 1 && (dta->cmd[i] == 39 || is_sep(dta->cmd[i])))
            dta->cmd[i] *= -1;
    }
}

void  remove_q(t_data *dta)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dta->cmd[i])
    {
        if (dta->cmd[i] == 34 || dta->cmd[i] == 39)
            ;
        else
        {
            dta->wc[j] = dta->cmd[i];
            j++;    
        }
        i++;
    }
    dta->wc[j] = '\0';
    free(dta->cmd);
    dta->cmd = dta->wc;
}
