/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:32:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/21 18:26:19 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int error_redir()
{
    printf("syntax error near unexpected token `newline'\n");
    return (-1);
}

int error_redir2()
{
    printf("syntax error near unexpected token `<'\n");
    return (-1);
}

//fctn pour parsing des redirections 
// redirection apres un pipe mais jamais avant
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
    //printf("%d\n",j);
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
    start = i;
    while (dta->cmdwh[i])
    {
        if (dta->cmdwh[i] == '<' && dta->cmdwh[i + 1] == '<')
            break;
        k++;
        i++;
    }
    arg_redirbis(dta, k , start);
}

int arg_redirbis(t_data *dta, int k, int start)
{
    dta->cmd_rdr = (char *)malloc(sizeof(char *) * (k - start + 1));
    if (dta->cmd_rdr == NULL)
        return (-1);
    ft_strncpy(dta->cmd_rdr , dta->cmdwh, (k - start));
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
    //printf("le h = %d\n",h);
    return(h); 
}

// en fonction erreur si < en fin de ligne ou > + < et envoie dans la fonction pars pour le heardoc << 
// pas gere heardoc avec pipe 
int parsing_redir(t_data *dta, int i, int j, int k, int end)
{
    int start;
    char *tmp;
    //tmp = ft_strdup("");
        
    start = 0;
    while(dta->cmdwh[i])
    {
        if (dta->cmdwh[i] == '>' || dta->cmdwh[i] == '<')
        {
            k = skip_wh(dta->cmdwh , i);
            if (k == 1 && dta->cmdwh[i + k] == '\0' && dta->cmdwh[i + k] != dta->cmdwh[i])
                error_redir();
            if (k > 1 && dta->cmdwh[i + k] && (dta->cmdwh[i + k] == '>' || dta->cmdwh[i + k] == '<'))
                error_redir2();
            if (k == 1 && dta->cmdwh[i + k] == dta->cmdwh[i] && dta->cmdwh[i] == '<')
            {
                dta->start_r = (i + 2);
                //printf("%c\n", dta->cmd[dta->start_r]);
                //dta->res = pipe_heardoc(dta, &i);
                s_redir2(dta, j, start, end, i);
                tmp = ft_strdup("");
                tmp = ft_strjoin(tmp , dta->cmd_f);
                dta->res++;
                dta->cmd = ft_strjoin(tmp, dta->copyh);
                printf("dta-> cmd finale dans fonction heardoc %s\n", dta->cmd);
                if (dta->copyh != NULL)
                    free(dta->copyh);
                free(tmp);
            }
            dta->start_r = 0;
        }
        i++;
    }
    return (0);
}
