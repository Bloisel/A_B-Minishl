/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:34:59 by bloisel           #+#    #+#             */
/*   Updated: 2024/04/30 14:59:40y bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// fctn pour compter les wh a ajouter entre les seperateurs 
void countwh_sep(t_data *dta)
{
	int i;
	int j;
	int k;
	int res;

	j = 0;
	i = 0;
	k = 0;
	while (dta->cmd[i])
	{
		if (is_sep2(dta->cmd[i]) == 1)
		{
			k = is_sep3(dta, i);
			if (k == 1)
			{
				if (is_sep(dta->cmd[i - 1]) == 0)
					j++;
				if (is_sep(dta->cmd[i + 1]) == 0)
					j++;
				i++;
			}
			if (k == 2)
			{
				if (is_sep(dta->cmd[i - 1]) == 0)
					j++;
				if (is_sep(dta->cmd[i + 2]) == 0)
					j++;
				i += 2;
			}
		}
		i++;	
	}
	res = ((i + j) + 2);
	dta->cmdwh = (char *)malloc(sizeof(char *) * (i + j) + 1);
	add_whsep(dta, res);
}

// verfier le cas avec echo << ls | la 
// fctn pour ajouter les wh a la chaine malloc 
char *add_whsep(t_data *dta, int res)
{
	int i;
	int k;
	int j;
	
	k = 0;
	i = 0;
	j = 0;
	
	while (dta->cmd[i] && res >= j)
	{
		if (is_sep2(dta->cmd[i]) == 1)
		{
			k = is_sep3(dta, i);
			if (k == 1)
			{
				if (is_sep(dta->cmd[i - 1]) == 0)
				{
					dta->cmdwh[j++] = 32;
				}
				dta->cmdwh[j++] = dta->cmd[i];
				i++;
				if (is_sep(dta->cmd[i + 1]) == 0)
				{
					dta->cmdwh[j++] = 32;
				}
			}
			if (k == 2)
			{
				if (is_sep(dta->cmd[i - 1]) == 0)
				{
					dta->cmdwh[j++] = 32;
				}
				dta->cmdwh[j++] = dta->cmd[i];
				dta->cmdwh[j++] = dta->cmd[++i];
				i++;
				if (is_sep(dta->cmd[i + 1]) == 0)
				{
					dta->cmdwh[j] = 32;
					j++;
				}
			}
		}
		dta->cmdwh[j++] = dta->cmd[i++];
	}
	dta->cmdwh[j] = '\0';
	//printf("commande de dta->cmdwh avec spaceadd %s\n", dta->cmdwh);
	return (dta->cmdwh);
}