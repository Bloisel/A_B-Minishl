/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:32:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/04/26 15:32:43 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// cas <<EOF (+) >en fin de ligne (+) > < erreur syntax (+)  
// peut etre supprime les Whitespaces pour les >  < 
// echo dd > bb < ss
// echo << ls << la a GERER 
// cat << ls | cat
// cas erreur cat <ls 
// chaine de characteres qui recupper cat ls << la << dhhdhdhd < jdjdj < bast < etc.. 

int error_redir()
{
    printf("erreur redirection minishell\n");
    return (-1);
}

/*int init_intforredir(t_data *dta)
{
    int i;
    int k;
    int end;
    int start;

    i = 0;
    k = 0;
    start = 0;
    end = 0;
}*/

int s_redir(t_data *dta)
{
    int k;
    int end;
    int start;
    int j;
    int i;

    k = 0;
    start = 0;
    end = 0;
    i = 0;
    j = 0;
    //arg_redir(dta);
    while (dta->cmd[i])
    {
        if (dta->cmd[i] == '>' || dta->cmd[i] == '<')
        {
            k = skip_wh(dta->cmd , i);
            if (k == 1 && dta->cmd[i + k] != '\0' && dta->cmd[i + k] != dta->cmd[i])
            {
                printf("%c\n",dta->cmd[i]);
                printf("%c\n",dta->cmd[i + k]);
                printf("ok\n");
                return (error_redir());
            }
            if (k > 1 && dta->cmd[i + k] && (dta->cmd[i + k] == '>' || dta->cmd[i + k] == '<'))
            {
                printf("ok2");
                return (error_redir());
            }
            if (k == 1 && dta->cmd[i + k] == dta->cmd[i] && dta->cmd[i] == '<')
            {
                s_redir2(dta, j, start, end, i);
            }
        } 
        i++;        
    }    
    return (0);
}

int s_redir2(t_data *dta, int j, int start, int end, int i)
{
    int k;

    k = 0;
    j = (i + 2);
    while (dta->cmd[j] == ' ')
        j++;
    start = j;
    while (dta->cmd[j] != '\0' && dta->cmd[j] != '|' && dta->cmd[j] != ' ')
        j++;
    j--;
    end = j;
    dta->copy = (char *)malloc(sizeof(char *) * (j - start + 1));
    if (dta->copy == NULL)
        return (-1);
    if (end > start)
        ft_strncpy(dta->copy, &dta->cmd[start], (j - start + 1));
    k = (j - start + 1);
    s_redir3(dta, k);
}
