/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:34:59 by bloisel           #+#    #+#             */
/*   Updated: 2024/04/26 13:32:16 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int countwh_sep(t_data *dta)
{
	int i;
	int j;
	int k;

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
	dta->cmdwh = (char *)malloc(sizeof(char *) * (i + j) + 1);
	add_whsep(dta);
}

char *add_whsep(t_data *dta)
{
	int i;
	int k;
	int j;
	
	k = 0;
	i = 0;
	j = 0;
	
	while (dta->cmd[i] && i <= j)
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
				dta->cmdwh[j] = dta->cmd[i];
				if (is_sep(dta->cmd[i++ + 1]) == 0)
				{
					j++;
					dta->cmdwh[j++] = 32;
				}
			}
			if (k == 2)
			{
				if (is_sep(dta->cmd[i - 1]) == 0)
				{
					dta->cmdwh[j++] = 32;
				}
				dta->cmdwh[j++] = dta->cmd[i++];
				dta->cmdwh[j] = dta->cmd[i];
				if (is_sep(dta->cmd[i++ + 1]) == 0)
				{
					dta->cmdwh[++j] = 32;
					j++;
				}
			}
		}
		dta->cmdwh[j++] = dta->cmd[i++];
	}
	dta->cmdwh[j] = '\0';
	printf("%s\n", dta->cmdwh);
	return (dta->cmdwh);
}