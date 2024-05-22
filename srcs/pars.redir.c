/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:32:26 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/22 03:09:42 by bloisel          ###   ########.fr       */
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

void intfors_redir(t_data *dta)
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
    parsing_redir(dta, i, j, k, end);
}

// en fonction erreur si < en fin de ligne ou > + < et envoie dans la fonction pars pour le heardoc << 
int parsing_redir(t_data *dta, int i, int j, int k, int end)
{
    int start;
    int key_size;
    char *tmp;
        
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
                s_redir2(dta , j , start , end , i);
                getline_beforekey2(dta);
                free(dta->key_dot);
                free(dta->copyh);
            }
            dta->start_r = 0;
        }
        i++;
    }
    return (0);
}
