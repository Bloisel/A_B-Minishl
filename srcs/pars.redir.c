/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:32:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/04/30 18:34:25 by bloisel          ###   ########.fr       */
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


// skip white space dans fonction avant malloc 
char *s_redir(t_data *dta,char *str)
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
    while (dta->cmdwh[i])
    {
        if (dta->cmdwh[i] == '>' || dta->cmdwh[i] == '<')
        {
            k = skip_wh(dta->cmdwh , i);
            if (k == 1 && dta->cmdwh[i + k] == '\0' && dta->cmdwh[i + k] != dta->cmdwh[i])
            {
                EXIT_FAILURE;
                //return (error_redir());
            }
            if (k > 1 && dta->cmdwh[i + k] && (dta->cmdwh[i + k] == '>' || dta->cmdwh[i + k] == '<'))
            {
                EXIT_FAILURE;
                //return (error_redir());
            }
            if (k == 1 && dta->cmdwh[i + k] == dta->cmdwh[i] && dta->cmdwh[i] == '<')
            {
                arg_redir(dta);
                s_redir2(dta, j, start, end, i);
                return (dta->cmd_rdr);
            }
        } 
        i++;        
    }   
    return (dta->cmd_rdr);
}

int s_redir2(t_data *dta, int j, int start, int end, int i)
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
        return (-1);
    if (end > start)
        ft_strncpy(dta->copy, &dta->cmdwh[start], (j - start + 1));
    k = (j - start + 1);
    s_redir3(dta, k);
}
