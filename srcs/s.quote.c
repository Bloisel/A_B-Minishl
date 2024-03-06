/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.quote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:40:27 by bloisel           #+#    #+#             */
/*   Updated: 2024/03/06 19:12:26 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int error_s_quote()
{
    printf("erreur quote minishell\n");
    return (-1);
}

int ntg(t_data *dta , char c)
{
    int i;

    i = 0;

    while(dta->wc[i])
    {
        if (dta->wc[i] == c)
            return (-1);
        i++; 
    }
    return (1);
}

int d_quote(t_data *dta)
{
    int i;
    int j;

    i = 0;
    dta->wc = (char *)malloc((ft_strlen(dta->cmd) + 1)*sizeof(char));    
    ft_bzero(dta->wc , ft_strlen(dta->cmd));
    while (dta->cmd[i])
    {
        if (dta->cmd[i] == 34)
        {
            if (dta->cmd[i + 1] == '\0')
            {
                printf("err0\n");
                error_s_quote();
                return (-2);
            }
            j = 0;
            i++;
            while(dta->cmd[i] && dta->cmd[i] != 34)
            {
                dta->wc[j] = dta->cmd[i];
                if (dta->cmd[i + 1] == '\0')
                {
                    printf("err1\n");
                    error_s_quote();
                    return (-2);
                }
                if (dta->cmd[i] == 34)
                {
                    dta->wc[j] = '\0';
                    printf("copie egale = %s\n", dta->wc);
                    return (1);
                    break;
                }
                i++;
                j++;
            }
        }
        i++; 
    }
    return (1);
}

int s_quote(t_data *dta , char *str)
{
    int i;
    int j;

    j = 0;
    i = 0;
    dta->cmd = ft_strdup(str);
    while (dta->cmd[i])
    {
        if (dta->cmd[i] == 39)
        {
            if (dta->cmd[i + 1] == '\0')
            {
                printf("err2\n");
                error_s_quote();
                return (-2);
            }
            i++;
            while(dta->cmd[i] && dta->cmd[i] != 39)
            {
                if(dta->cmd[i + 1] == '\0')
                {
                    printf("err3\n");
                    error_s_quote();
                    return (-2);
                }
                i++;      
            }
        }
        i++;
    }
    return (1);
}
