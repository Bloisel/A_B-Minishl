/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:32:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/03 15:25:59 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


// CAS PAS GERE 
//bash-3.2$ echo | < ls wc
//       1       3      25
// bash-3.2$ echo | > ls wc
//

int error_redir()
{
    printf("erreur redirection minishell\n");
    return (-1);
}
//fctn pour parsing des redirections 
// redirection apres un pipe mais jamaias avant  
int s_redir(t_data *dta,char *str)
{
    int k;
    int end;
    int start;
    int j;
    int i;
    int res;

    res = 0;
    k = 0;
    start = 0;
    end = 0;
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
    i = 0;
    while (dta->cmdwh[i])
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
                res++;
                //return (dta->cmd_rdr);
            }
        } 
        i++;        
    }
    free(dta->cmd);
    if (res > 0)
        return (1);
    return (0);
}

// ARTUNG ARTUNG  echo << ls | wc
// ARTUNG ARTUNG echo << ls << la << pp avec des arguments entre 
// fctn appelle dans le cas ou heardoc << : permet de stocker le nom du fichier apres HEARDOC
// attention verifier les cas avec << et | dans la meme ligne 
void s_redir2(t_data *dta, int j, int start, int end, int i)
{
    int k;

    k = 0;
    j = (i + 2);
    while (dta->cmdwh[j] == ' ')
        j++;
    start = j;
    while (dta->cmdwh[j] != '\0' && dta->cmdwh[j] != '|' && dta->cmdwh[j] != ' ')
        j++;
    j--;
    end = j;
    dta->copy = (char *)malloc(sizeof(char *) * (j - start + 1));
    if (dta->copy == NULL)
        EXIT_FAILURE;
    if (end > start)
        ft_strncpy(dta->copy, &dta->cmdwh[start], (j - start + 1));
    printf("first redir copy %s\n", dta->copy);
    k = (j - start + 1);
    s_redir3(dta, k);
}

void pipe_heardoc(t_data *dta, int i)
{
    int k;
    int j;
    int start;
    int end;

    j = (i + 2);
    k = 0;
    start = 0;
    end = 0;
    while (dta->cmdwh[j] != '|')
        j++;
    start = j;
    printf("%d\n", start);
    while (dta->cmdwh[j])
        j++;
    j--;
    end = j;
    dta->cmdhp = (char *)malloc(sizeof(char *) * (j - start) + 1);
    if (dta->cmdhp)
        EXIT_FAILURE;
    if (end > start)
        ft_strncpy(dta->cmdhp , &dta->cmdwh[start], (j - start) + 1);
    printf("heardoc et pipe %s\n", dta->cmdhp); 
}
