/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:32:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/03/15 15:37:56 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// cas <<EOF (+) >en fin de ligne (+) > < erreur syntax (+)  

// peut etre supprime les Whitespaces pour les >  < 
// echo dd > bb < ss

int error_redir()
{
    printf("erreur redirection minishell\n");
    return (-1);
}

int skip_wh(char *str, int pos)
{
    int j;

    j = 1;
    while (str[pos + j] && is_sep(str[pos + j]) != 0)
    {
        j++;
    }
    return (j);
}

int s_redir(t_data *dta)
{
    int i;
    int k;

    k = 0;
    i = 0;
    while (dta->cmd[i])
    {
        if (dta->cmd[i] == '>' || dta->cmd[i] == '<')
        {
            k = skip_wh(dta->cmd , i);
            if (k == 1 && dta->cmd[i + k] != '\0' && dta->cmd[i + k] != dta->cmd[i])
                return (error_redir());
            if (k > 1 && dta->cmd[i + k] && (dta->cmd[i + k] == '>' || dta->cmd[i + k] == '<'))
                return (error_redir());
            if (k == 1 && dta->cmd[i + k] == dta->cmd[i] && dta->cmd[i] == '<')
            {
                // 1 er etape skip les espaces 
                // 2 eme etape parcourir la chaine jusqua delimiteur ' ' / EOF , pipe , autre redirection (test)
                // malloc ma chaine la stocker 
                // boucle infinit sur prompt jusqua ft_strncmp chaine
                
            }
        } 
        i++;        
    }    
    return (0);
}
