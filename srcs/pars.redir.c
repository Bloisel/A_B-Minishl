/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:32:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/16 18:30:55 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int error_redir()
{
    printf("erreur redirection minishell\n");
    return (-1);
}

//fctn pour parsing des redirections 
// redirection apres un pipe mais jamaias avant

int arg_beforeredir(t_data *dta)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dta->cmdwh[i])
    {
        if (dta->cmdwh[i] == '>' || dta->cmdwh[i] == '<')
        {
            arg_redir(dta);
            break;
        }
        i++;
    }
    j = intfors_redir(dta);
    printf("%d\n",j);
    return (j);
}

// fonction pour reccuper argument avant heardoc ex : "echo << ls" devient "echo " dans dta->cmd_rdr
int arg_redir(t_data *dta)
{
    int i;
    int start;
    int k;

    i = 0;
    start = 0;
    k = 0;
    while (dta->cmdwh[i] != '<' && dta->cmdwh[i] != '>')
    {
        while (is_sep(dta->cmdwh[i]) == 1)
            i++;
        if (dta->cmdwh[i] == '>' || dta->cmdwh[i] == '<')
            break;
        if (is_sep(dta->cmdwh[i]) == 1)
            start = i++;
        while (is_sep(dta->cmdwh[i]) == 0)
        {
            k++;
            i++;
        }
    }
    arg_redirbis(dta, k , start);
}

int arg_redirbis(t_data *dta, int k, int start)
{
    dta->cmd_rdr = (char *)malloc(sizeof(char *) * (k - start + 1));
    if (dta->cmd_rdr == NULL)
        return (-1);
    ft_strncpy(dta->cmd_rdr , dta->cmdwh, (k - start + 1));
    printf("tour de arg redir chaine realloc %s\n", dta->cmd_rdr);
    return (0); 
}

int intfors_redir(t_data *dta)
{
    int h;
    int i;
    int j;
    int k;
    int end;
    
    i = 0;
    j = 0;
    k = 0;
    end = 0;
    h = parsing_redir(dta, i, j, k, end);
    return (h); 
}

// en fonction erreur si < en fin de ligne ou > + < et envoie dans la fonction pars pour le heardoc << 
int parsing_redir(t_data *dta, int i, int j, int k, int end)
{
    int start;

    start = 0;
    while(dta->cmdwh[i])
    {
        if (dta->cmdwh[i] == '>' || dta->cmdwh[i] == '<')
        {
            k = skip_wh(dta->cmdwh , i);
            if (k == 1 && dta->cmdwh[i + k] == '\0' && dta->cmdwh[i + k] != dta->cmdwh[i])
                error_redir();
            if (k > 1 && dta->cmdwh[i + k] && (dta->cmdwh[i + k] == '>' || dta->cmdwh[i + k] == '<'))
                error_redir();
           if (k == 1 && dta->cmdwh[i + k] == dta->cmdwh[i] && dta->cmdwh[i] == '<')
            {
                pipe_heardoc(dta, i);
                s_redir2(dta, j, start, end, i);
                dta->res++;
                // return ? sinon res tjs ok pour conditions  
            }
        }
        i++;
    }
    free(dta->cmd);
    if (dta->res > 0)
    {
        printf("okdot");
        return (1);
    }
    return (0);
}
