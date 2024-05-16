/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:54:10 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/16 16:59:20 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// fonction pas utiliser a tchequer pour inserer avec env var environnement etc ... 
void replace_quote(t_data *dta)
{
	int	i;
	int	in1;
	int	in2;

	in1 = -1;
	in2 = -1;
	i = -1;
	while (dta->cmd[++i])
	{
		if (dta->cmd[i] == '"' && in2 == -1)
			in1 *= -1;
		if (dta->cmd[i] == '\'' && in1 == -1)
			in2 *= -1;
		if (in1 == 1 && (dta->cmd[i] == '\'' || is_sep(dta->cmd[i])))
			dta->cmd[i] *= -1;
		if (in2 == 1 && (dta->cmd[i] == '"' || dta->cmd[i] == '$'
				|| is_sep(dta->cmd[i])))
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

void reset_quoteenv(t_data *dta)
{
		int i;

		i = 0;
		while (dta->cmd[i])
		{
				if (dta->cmd[i] == -34 || dta->cmd[i] == -39)
					dta->cmd[i] *= -1;
				i++;
		}
}