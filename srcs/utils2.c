/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:34:59 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/16 14:40:39 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

// 0 pour no WH
int	is_sep(char c)
{
	if (c == '\n' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

// 0 pour no separateur
int is_sep2(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}


int is_sep3(t_data *dta, int pos)
{
	if ((dta->cmd[pos] == '>' && dta->cmd[pos + 1] == '>')
		|| (dta->cmd[pos] == '<' && dta->cmd[pos + 1] == '<'))
		return (2);
	return (1);
}

int is_sep4(char c)
{
	if (c == -34 || c == -39 || c == -32)	
		return (1);
	return (0);
}