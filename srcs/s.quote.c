/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.quote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:40:27 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/15 18:25:50 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// bien exit proprement a la fin si erreur 


void error_s_quote()
{
    printf("erreur quote minishell\n");
    //exit;
}

int s_quote2(t_data *dta, int splq, int dblq)
{
    if (splq && !dblq)
    {
        error_s_quote();
        return (-2);
    }
    if (dblq && !splq)
    {
        error_s_quote();
        return (-2);
    }
    return (1);
}

int s_quote(t_data *dta , char *str)
{
    int i;
    int dblq;
    int splq;

    splq = 0;
    dblq = 0;
    i = 0;
    while (dta->cmd[i])
    {
        if (dta->cmd[i] == 39)
        {
            dta->count = 1;
            if(!dblq)
                splq = !splq;
        }
        if (dta->cmd[i] == 34)
        {
            dta->count = 2;
            if (!splq)
                dblq = !dblq;
        }
        i++;   
    }
    if ((!dblq && splq) || (dblq && !splq)) 
        return s_quote2(dta, splq, dblq);
    return (1);
}
