/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.quote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:40:27 by bloisel           #+#    #+#             */
/*   Updated: 2024/03/08 15:53:23 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int error_s_quote()
{
    printf("erreur quote minishell\n");
    return (-1);
}

int s_quote2(t_data *dta, int splq, int dblq)
{
    printf("\n");
    if (splq && !dblq)
    {
        printf("Error SINGLE\n");
        error_s_quote();
        return (-2);
    }
    if (dblq && !splq)
    {
        printf("%d\n",dblq);
        printf("Error DOUBLE\n");
        error_s_quote();
        return (-2);
    }
    return (1);
}

int s_quote(t_data *dta , char *str)
{
    int i;
    int j;
    int dblq;
    int splq;

    splq = 0;
    dblq = 0;
    // init de boolens , splq = 0 (faux) // !splq # de splq donc de 0 et donc !splq = 1 et vrais 
    i = 0;
    j = 0;
    while (dta->cmd[i])
    {
        if (dta->cmd[i] == 39)
        {
            dta->count++;
            if(!dblq)
            {
                splq = !splq;
            }
        }
        else if (dta->cmd[i] == 34)
            dblq = !dblq;
        i++;   
    }
    if (!dblq && dta->count > 0)
        dta->count = 100;
    s_quote2(dta , splq , dblq);
    return (1);
}
