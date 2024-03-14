/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:32:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/03/14 18:42:17 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// cas <<EOF (+) >en fin de ligne (+) > < erreur syntax (+)  

int error_redir()
{
    printf("erreur redirection minishell\n");
    return (-1);
}

int s_redir(t_data *dta)
{
    int i;

    i = 0;

    while (dta->cmd[i])
    {
        if (dta->cmd[i] == '>' || dta->cmd[i] == '<' || dta->cmd[i] == '|' && dta->cmd[i + 1] == '\0')
            return (error_redir());
        if (dta->cmd[i] == '>' && dta->cmd[i + 1] == '<')
            return(error_redir());
        if (dta->cmd[i] == '<' && dta->cmd[i + 1] == '<')
            return(error_redir());
        i++;        
    }    
    return (0);
}

